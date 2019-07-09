/********************************************************
 *                                                      *
 *                                                      *
 *      user_sm.h			          	*
 *                                                      *
 *							*
 *		FI-UNAM					*
 *		17-2-2019                               *
 *                                                      *
 ********************************************************/
#include <math.h>
//#include "sm_avoidance.h"
#define pi 3.1415926
const float eps=0.1;	
#define eta 0.1	//Peso de la fuerza de repulsión
#define porc 0.7 //Porcentaje del laser value para considerar obstáculo

float xd, yd;
float f_atrac_x, f_atrac_y;
float q_next_x = 0.0;
float q_next_y = 0.0;
float f_unit_x = 0.0;
float f_unit_y = 0.0;
float f_total_x = 0.0;
float f_total_y = 0.0;
float gira_angulo = 0.0;
float avanza_dist = 0.0;
float f_rep_sum_x = 0.0;
float f_rep_sum_y = 0.0;
int ind_state=0;
int cont_est;



float posLight(float *photos)
{
	float menor = photos[0];
	int id = 0;
	for (int i = 0; i < 8; i++)
	{
		if(photos[i] > menor)
		{
			menor = photos[i];
			id = i;
		}
	}
	float angulo = (45*id*pi)/180.0;
	//printf("%.4f\n", angulo);
	return angulo;
}


float distLight(float intensidad)
{
	float dist = 0.9948002167*pow(intensidad,- 0.9124168741);
	//printf("%.4f\n", dist);
	return dist;
}

void coordenadas(float mag, float ang)
{
	xd = mag*cos(ang);
	yd = mag*sin(ang);
	//printf("%.4f %.4f\n", xd, yd);
	
}

void f_atrac(float xd, float yd)
{
	f_atrac_x = -xd*eps;
	f_atrac_y = -yd*eps;
	//printf("F atracción: %.4f %.4f\n", f_atrac_x, f_atrac_y);
} 

void f_rep(float size, float *observations, float laser_value)
{	
	f_rep_sum_x = 0.0;
	f_rep_sum_y = 0.0;
	for(int i = 0; i < size; i++)
	{
		float d0 = laser_value*porc; 
		float q_obs_x = observations[i]*cos(-1.5708 + (pi/(size -1))*i);
		float q_obs_y = observations[i]*sin(-1.5708 + (pi/(size -1))*i);
		if(observations[i] <= d0)
		{	
			f_rep_sum_x += -eta*((1.0/observations[i])-(1/d0))*(-q_obs_x/pow(observations[i],3));
			f_rep_sum_y += -eta*((1.0/observations[i])-(1/d0))*(-q_obs_y/pow(observations[i],3));;
		}
	}
	printf("F repulsión: %.4f %.4f\n", f_rep_sum_x, f_rep_sum_y);
}

void calcula_campos(float intensity, float *light_values, float *observations, int size, float laser_value, float Mag_Advance){

	coordenadas(distLight(intensity),posLight(light_values));
	f_atrac(xd, yd);
	f_rep(size, observations, laser_value);
	f_total_x = f_atrac_x + f_rep_sum_x;
	f_total_y = f_atrac_y + f_rep_sum_y;
	//printf("F total: %.4f %.4f", f_total_x, f_total_y);
	f_unit_x = f_total_x/(sqrt((f_total_x*f_total_x)+(f_total_y*f_total_y)));
	f_unit_y = f_total_y/(sqrt((f_total_x*f_total_x)+(f_total_y*f_total_y)));
	//printf("F unit: %.4f %.4f\n", f_unit_x, f_unit_y);
	q_next_x = -(Mag_Advance*f_unit_x);
	q_next_y = -(Mag_Advance*f_unit_y);
	//printf("Q next: %.4f %.4f\n", q_next_x, q_next_y);
	gira_angulo = atan2(q_next_y,q_next_x);
	//printf("Angulo: %.4f\n", gira_angulo);
	avanza_dist = sqrt((q_next_x*q_next_x)+(q_next_y*q_next_y));
	//printf("Distancia: %.4f\n", avanza_dist);
}


int campos(float intensity, float *light_values, float *observations, int size, float laser_value, int  dest, int obs ,movement *movements, int *next_state, float Mag_Advance ,float max_twist)
{
 printf("intensity %f\n",intensity);
 printf("quantized destination %d\n",dest);
 printf("quantized obs %d\n",obs);
 for(int i = 0; i < 8; i++)
        printf("light_values[%d] %f\n",i,light_values[i]);
 for (int i = 0; i < size ; i++ ) 
         printf("laser observations[%d] %f\n",i,observations[i]);
/*------------------------------------------------------------------------*/
	int state = *next_state;	//El * denota el valor de la dirección, & denota la localidad
	switch(state){
		case 0:	
			cont_est = 0;
			calcula_campos(intensity, light_values, observations, size, laser_value, Mag_Advance);
			//Si gira_angulo es 0 y el ángulo entre el robot y el centroide del objeto es 0
			if(obs == 3 && (gira_angulo > 2.7925 && gira_angulo < 3.4906))
			//Haces máquina evade obstáculos
				//printf("Ya me atoré");
				*next_state = 2;
			//else
			else{
				if(gira_angulo < 0)
					*movements=generate_output(RIGHT,Mag_Advance,fabs(gira_angulo));
				else
					*movements=generate_output(LEFT,Mag_Advance,gira_angulo);
				*next_state = 1;
			}
			break;

		case 1:
			*movements=generate_output(FORWARD,avanza_dist,max_twist);
			*next_state = 0;
			break;

		case 2:
			if(cont_est < 15){
				sm_avoid_obstacles(obs,movements,&ind_state,Mag_Advance,max_twist);
				cont_est++;
				*next_state = 2;
			} else{
				*movements=generate_output(STOP,Mag_Advance,max_twist);
				*next_state = 0;
				ind_state = 0;
			}
			break;

		default:
			*movements=generate_output(STOP,Mag_Advance,max_twist);
			*next_state = 0;
	}

//si muy cerca ya nada
	if(intensity >= 4.0)
		return 1;
	else 
		return 0;

//getchar();
}



                 
