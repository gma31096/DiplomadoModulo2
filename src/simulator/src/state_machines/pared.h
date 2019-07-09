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
// State Machine 
bool allIsClear(float* distancias, int tam, float max){
	float min = 99999;
	for(int i=0;i<tam;i++)	if(distancias[i]<min) min = distancias[i];
	printf("%f\n",min);
	if(min<=max) return false;
	else return true; 
}

void pared_sm(float intensity, float *light_values, float *observations, int size, float laser_value, int  dest, int obs ,movement *movements  ,int *next_state ,float Mag_Advance ,float max_twist)
{

 int state = *next_state;

 printf("intensity %f\n",intensity);
 printf("quantized destination %d\n",dest);
 printf("quantized obs %d\n",obs);
 for(int i = 0; i < 8; i++)
        printf("light_values[%d] %f\n",i,light_values[i]);
 for (int i = 0; i < size ; i++ ) 
         printf("laser observations[%d] %f\n",i,observations[i]);
/*------------------seguidor de paredes v2-----------------------------*/

switch ( state ) {
	case 0:
		*movements = generate_output(STOP,Mag_Advance,max_twist);
		if(allIsClear(observations,size,0.035))	*next_state = 1;
		else *next_state = 2;
		break;
	
	case 1:
                *movements=generate_output(FORWARD,Mag_Advance,max_twist);
                *next_state = 0;
		break;
	case 2:
	
                *movements=generate_output(BACKWARD,0.5*Mag_Advance,max_twist);
		eso = getTurnAngle(observations,size);
		*next_state = 3;
		break;
	case 3:
		if(eso>10*pi/180.0)
		{
			*movements = generate_output(LEFT,Mag_Advance,eso);
			*next_state = 0;
		}else{
			*movements = generate_output(LEFT,Mag_Advance,0.5*pi);
			*next_state = 4;
		}
		break;
	case 4:
		*movements = generate_output(FORWARD,0.3*Mag_Advance,max_twist);
		*next_state = 5;
		break;
	case 5:
		*movements = generate_output(RIGHT,Mag_Advance,pi*0.5);
		*next_state = 0;
		break;
	default:
                *movements=generate_output(STOP,Mag_Advance,max_twist);
                *next_state = 0;
                break;            
}

/*-------------------seguidor de paredes v1-------------------------------*/
/*switch ( state ) {

        case 0:
		*movements = generate_output(STOP,Mag_Advance,max_twist);
		if(frontIsClear(observations,size,0.035))	*next_state = 1;
		else *next_state = 2;
               	break;

        case 1:
               *movements=generate_output(FORWARD,Mag_Advance,max_twist);
               *next_state = 0;
                break;
	case 2:
		*movements = generate_output(BACKWARD,Mag_Advance,max_twist);
		*next_state = 3;
		break;
	case 3:
		*movements = generate_output(LEFT,Mag_Advance,max_twist);
		*next_state = 4;
		break;
	case 4: 
		*movements = generate_output(LEFT,Mag_Advance,max_twist);
		*next_state = 0;
		break;
	default:
                *movements=generate_output(STOP,Mag_Advance,max_twist);
                *next_state = 0;
                break;            
 }*/
printf("Next State: %d\n", *next_state);
while(angle>2*pi)	angle-=2*pi;
while(angle<0)	angle+=2*pi;
printf("Angle:\t%f\n",angle*180/pi);
posx += dis * cos(angle);
posy += dis * sin(angle);
printf("X relative: \t%f\n",10*posx);
printf("Y relative: \t%f\n",10*posy);
printf("\n distancia: %f\n",10*sqrt((posx*posx)+(posy*posy)));

//getchar();
}



                 
