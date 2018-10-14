/********************************************************
 *                                                      *
 *                                                      *
 *      state_machine_avoidance_destination.h          	*
 *                                                      *
 *		Jesus Savage				*
 *		FI-UNAM					*
 *		5-2-2015                                *
 *                                                      *
 ********************************************************/

int quantize_light(float *light_values)
{
    int sensor = 0;

    for(int i = 1; i < 8; i+=2)
        if( light_values[i] < light_values[sensor])
            sensor = i;

    if(sensor == 0)
        return 0;
    else if(sensor == 1)
        return 1;
    else if(sensor == 3)
        return 2;
    else if(sensor == 5)
        return 3;
    else if(sensor == 7)
        return 4;

    return 0;
}
// State Machine 
void sm_avoidance_destination(int  dest,int obs ,movement *movements  ,int *next_state ,float Mag_Advance ,float max_twist)
{
 int state = *next_state;

printf("obs %d\n",obs );
 //printf(" obs intensity %d obstacles %d dest %d\n",intensity,obs,dest);

 switch ( state ) {

        case 0:

			*movements=generate_output(FORWARD,Mag_Advance,max_twist);
                        //printf("Present State: %d FORWARD\n", state);
                        *next_state = 1;

                break;

        case 1:
                if (obs == 0){
			// there is not obstacle
                        *movements=generate_output(FORWARD,Mag_Advance,max_twist);
                        //printf("Present State: %d FORWARD\n", state);
                        *next_state = 16;
                }
                else{
                        *movements=generate_output(STOP,Mag_Advance,max_twist);
                        //printf("Present State: %d STOP\n", state);

                        if (obs == 1){
                                // obtacle in the  right
                                *next_state = 4;
                        }
                        else if (obs == 2){
                                // obtacle in the left
                                *next_state = 2;
                        }
                        else if (obs == 3){
				// obstacle in the front
                                *next_state = 6;
                        }
                }

                break;

        case 2: // Backward, obstacle in the left
                *movements=generate_output(BACKWARD,Mag_Advance,max_twist);
		//printf("Present State: %d BACKWARD, obstacle LEFT\n", state);
                *next_state = 3;
                break;

        case 3: // right turn
                *movements=generate_output(RIGHT,Mag_Advance,max_twist);
		//printf("Present State: %d TURN RIGHT\n", state);
                *next_state = 0;
                break;

        case 4: // Backward, obstacle in the right
                *movements=generate_output(BACKWARD,Mag_Advance,max_twist);
		//printf("Present State: %d BACKWARD, obstacle RIGHT\n", state);
                *next_state = 5;
                break;

        case 5: // left turn
                *movements=generate_output(LEFT,Mag_Advance,max_twist);
		//printf("Present State: %d TURN LEFT\n", state);
                *next_state = 0;
                break;

        case 6: // Backward, obstacle in front
                *movements=generate_output(BACKWARD,Mag_Advance,max_twist);
		//printf("Present State: %d BACKWARD, obstacle FRONT\n", state);
                *next_state = 7;
                break;

	case 7: /// Left turn
                *movements=generate_output(LEFT,Mag_Advance,max_twist);
		//printf("Present State: %d TURN 1 LEFT\n", state);
                *next_state = 8;
                break;

        case 8:// Left turn
                *movements=generate_output(LEFT,Mag_Advance,max_twist);
		//printf("Present State: %d TURN 2 LEFT\n", state);
                *next_state = 9;
                break;

        case 9:// Left turn
                *movements=generate_output(LEFT,Mag_Advance,max_twist);
		//printf("Present State: %d TURN 3 LEFT\n", state);
                *next_state = 10;
                break;

        case 10: // Forward
                *movements=generate_output(FORWARD,Mag_Advance,max_twist);
                //printf("Present State: %d 1 FORWARD\n", state);
                *next_state = 11;
                break;

        case 11: // Forward
                *movements=generate_output(FORWARD,Mag_Advance,max_twist);
                //printf("Present State: %d 2 FORWARD\n", state);
                *next_state = 12;
                break;

        case 12: // Forward
                *movements=generate_output(FORWARD,Mag_Advance,max_twist);
                //printf("Present State: %d 3 FORWARD\n", state);
                *next_state = 13;
                break;

	case 13: // Right turn
                *movements=generate_output(RIGHT,Mag_Advance,max_twist);
                //printf("Present State: %d turn 1 RIGHT\n", state);
                *next_state = 14;
                break;

        case 14: // Right turn
                *movements=generate_output(RIGHT,Mag_Advance,max_twist);
                //printf("Present State: %d turn 2 RIGHT\n", state);
                *next_state = 15;
                break;

        case 15: // Right turn
                *movements=generate_output(RIGHT,Mag_Advance,max_twist);
                //printf("Present State: %d turn 3 RIGHT\n", state);
                *next_state = 0;
                break;


        case 16: // // check destination
		       if (dest == 4){
                                // go right
                                *movements=generate_output(RIGHT,Mag_Advance,max_twist);
                                //printf("Present State: %d RIGHT\n", state);
                                *next_state = 3;
                 }
                 else if (dest == 1){
                                // go left
                                *movements=generate_output(LEFT,Mag_Advance,max_twist);
                                //printf("Present State: %d LEFT\n", state);
                                *next_state = 5;
                 }
                 else if (dest == 3){
                                // go right single
                                *movements=generate_output(FORWARD,Mag_Advance,max_twist);
                                //printf("Present State: %d RIGHT\n", state);
                                *next_state = 3;
                 }
                 else if (dest == 2){
                                // go left single
                                *movements=generate_output(FORWARD,Mag_Advance,max_twist);
                                //printf("Present State: %d LEFT\n", state);
                                *next_state = 5;
                 }
                 else if (dest == 0){
                                // forward
                                *movements=generate_output(FORWARD,Mag_Advance,max_twist);
                                //printf("Present State: %d LEFT\n", state);
                                *next_state = 1;
                 }
                break;

	default:
		//printf("State %d not defined used ", state);
                *movements=generate_output(STOP,Mag_Advance,max_twist);
                *next_state = 0;
                break;

                
 }

 //printf("Next State: %d\n", *next_state);
 //return *movements;

}



                 
