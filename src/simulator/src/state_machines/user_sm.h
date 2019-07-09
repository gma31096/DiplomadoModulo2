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
#define pi 3.1415926
float posx = 0;
float posy = 0;
float angle = 0;
float dis = 0;
float eso = 0;
// State Machine 

bool frontIsClear(float* distancias, int tam, float max){
	float min = 99999;
	for(int i=tam*0.4;i<tam*0.6;i++)	if(distancias[i]<min) min = distancias[i];
	printf("%f\n",min);
	if(min<=max) return false;
	else return true; 
}
bool derIsBlock(float *distancias,int tam,float lim){
	int dersen = tam*0.2;
	float min = 999999999.9;
	for(int i = 0; i<dersen;i++)	if(distancias[i]<min) min = distancias[i];
	if(min<lim)	return true;
	else return false;
}
float lessDer(float *distancias,int tam){
	int dersen = tam*0.2;
        float min = 999999999.9;
        for(int i = 0; i<dersen;i++)    if(distancias[i]<min) min = distancias[i];
	printf("%.4f",min);
	return min;

}
float getTurnAngle(float *distancias,int tam){
	float min = 99999.9;
	int id = -1;
	for(int i = 0; i<tam; i++) {
		if(distancias[i]<min){
			min = distancias[i];
			id = i;
		}
	}
	return (pi*id)/tam;
}
int se = 0;
bool explora = true;
bool identifica = false;
bool rodea = false;
void user_sm(float intensity, float *light_values, float *observations, int size, float laser_value, int  dest, int obs ,movement *movements  ,int *next_state ,float Mag_Advance ,float max_twist)
{

 int state = *next_state;

 printf("intensity %f\n",intensity);
 printf("quantized destination %d\n",dest);
 printf("quantized obs %d\n",obs);
 for(int i = 0; i < 8; i++)
        printf("light_values[%d] %f\n",i,light_values[i]);
 for (int i = 0; i < size ; i++ ) 
         printf("laser observations[%d] %f\n",i,observations[i]);
/*------------------------------------------------------------------------*/
//dis = 0;
switch(state){
	case 0:
		
                if(frontIsClear(observations,size,0.05)) 
		{
                	*movements=generate_output(FORWARD,Mag_Advance,max_twist);
			se = 0;
		}else{
			se = 1;
			explora = false;
			identifica = true;
                	*movements = generate_output(STOP,Mag_Advance,max_twist);
		}
		break;
	case 1:
              	*movements = generate_output(STOP,Mag_Advance,max_twist);
		se = 100;				
		break;
	case 2:
              	*movements = generate_output(STOP,Mag_Advance,max_twist);
		if(!derIsBlock(observations,size,0.06)){
			*movements = generate_output(STOP,Mag_Advance,max_twist);
			printf("Es obstaculo");
			identifica = false;
			rodea = true;
			se = 3;
		}else if(!frontIsClear(observations,size,0.05)){
			*movements = generate_output(LEFT,Mag_Advance,pi*0.75);
			explora = true;
			identifica = false;
			printf("Es pared");
			se = 0;
		}else if(lessDer(observations,size)<0.04){
			*movements = generate_output(STOP,Mag_Advance,max_twist);
			printf("Alejate");
			se = 200;
		}else if(lessDer(observations,size)>0.05){
			*movements = generate_output(STOP,Mag_Advance,max_twist);
			printf("Acercate");
			se = 300;
		}else{
			*movements = generate_output(FORWARD,Mag_Advance,max_twist);
			dis = Mag_Advance;
			printf("Avanza");
			se = 2;
		}
		break;
	case 3:
		*movements = generate_output(FORWARD,3*Mag_Advance,max_twist);
		dis = 3*Mag_Advance;
		se = 4;
		break;
	case 4:
		*movements = generate_output(RIGHT,Mag_Advance,pi*0.5);
		angle-=pi*0.5;
		se = 5;
		break;
	case 5:
		*movements = generate_output(FORWARD,3*Mag_Advance,max_twist);
		dis = 3*Mag_Advance;
		se = 6;
		break;
	case 6:
		*movements = generate_output(RIGHT,Mag_Advance,pi*0.5);
		angle -=pi*0.5; 
		se = 7;
		break;
	case 7:
		*movements = generate_output(FORWARD,2*Mag_Advance,max_twist);
		dis = 2*Mag_Advance;
		se = 8;
		break;
	case 8:
		*movements = generate_output(LEFT,Mag_Advance,pi*0.5);
		angle += pi*0.5;
		se = 9;
		break;
	case 9:
              	*movements = generate_output(STOP,Mag_Advance,max_twist);
		se = 100;				
		break;
	case 10:
  	       if(!derIsBlock(observations,size,0.06)){
                        *movements = generate_output(STOP,Mag_Advance,max_twist);
                        printf("Esquina");
                        se = 3;
                }else if(lessDer(observations,size)>0.05){
                        *movements = generate_output(STOP,Mag_Advance,max_twist);
                        printf("Acercate");
                        se = 300;
		}else if(lessDer(observations,size)<0.04){
                        *movements = generate_output(STOP,Mag_Advance,max_twist);
                        printf("Alejate");
			se = 200;
		}else if(10*sqrt((posx*posx)+(posy*posy))<0.5){
			
			printf("\n %f Win?!!!!!!!!!!!!!!!",10*sqrt((posx*posx)+(posy*posy)));
                        *movements = generate_output(LEFT,Mag_Advance,pi*0.25);
			se = 0;
		}else{
			printf("Avanza");
                        dis = Mag_Advance;
			*movements = generate_output(FORWARD,Mag_Advance,max_twist);
			se = 10;
		}
	 
		break;
	case 100:
		printf("100\n");
		eso = getTurnAngle(observations,size);
		*movements = generate_output(LEFT,Mag_Advance,eso);
		if(identifica){
			se = 2;
			posx = 0;
			posy = 0;
			angle = 0;
			dis = 0;
		}else if(rodea)	se = 10;
		else 	se = 0;
		break;
	case 200:
		*movements = generate_output(LEFT,Mag_Advance,pi*0.5);
		angle += pi*0.5;
		se = 201;
		break;
	case 201:
		*movements = generate_output(FORWARD,0.4*Mag_Advance,max_twist);
		dis = 0.4*Mag_Advance;
		se = 202;
		break;
	case 202:
		*movements = generate_output(RIGHT,Mag_Advance,pi*0.5);
		angle -= pi*0.5;
		if(identifica) se = 2;
		else if(rodea) se = 10;
		else  se = 0;
		break;
	case 300:
		*movements = generate_output(RIGHT,Mag_Advance,pi*0.5);
		angle -= pi*0.5;
		se = 301;
		break;
	case 301:
		*movements = generate_output(FORWARD,0.4*Mag_Advance,max_twist);
		dis = 0.4*Mag_Advance;
		se = 302;
		break;
	case 302:
		*movements = generate_output(LEFT,Mag_Advance,pi*0.5);
		angle += pi*0.5;
		if(identifica)	se = 2;
		else if(rodea)	se = 10;
		else se = 0;
		break;
	default:
		explora = true;
		identifica = false;
		rodea = false;
		se = 0;
		break;
}

*next_state = se;
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



                 
