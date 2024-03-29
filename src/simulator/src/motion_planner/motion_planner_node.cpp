/***********************************************
*                                              *
*      motion_planner_node.cpp                 *
*                                              *
*      Jesus Savage                            *
*      Diego Cordero                           *
*                                              *
*              Bio-Robotics Laboratory         *
*              UNAM, 17-2-2019                 *
*                                              *
*                                              *
************************************************/

#include "ros/ros.h"
#include "../utilities/simulator_structures.h"
#include "../utilities/random.h"
#include "motion_planner_utilities.h"
#include "../state_machines/light_follower.h"
#include "../state_machines/sm_avoidance.h"
#include "../state_machines/sm_avoidance_destination.h"
#include "../state_machines/sm_destination.h"
#include "../state_machines/user_sm.h"
#include "../state_machines/dijkstra.h"
#include "../state_machines/dfs.h"
#include "../state_machines/bfs.h"
#include "../state_machines/Astar.h"
#include "../state_machines/campos.h"
#include "../state_machines/pared.h"
#include "clips_ros/SimuladorRepresentation.h"
#include "../behaviors/oracle.h"

int main(int argc ,char **argv)
{
    ros::init(argc ,argv ,"simulator_motion_planner_node");
    ros::NodeHandle n;
    ros::Subscriber params_sub = n.subscribe("simulator_parameters_pub",0, parametersCallback);
    ros::Subscriber sub = n.subscribe("/scan", 10, laserCallback);
    ros::Rate r(20);

    SimuladorRepresentation::setNodeHandle(&n);


    float lidar_readings[512];
    float light_readings[8];
    step steps[200];
    step graph_steps[200];
    int sensor;
    int i;
    int flagOnce;
    int est_sig;
    int cta_steps;

    int q_light;
    int q_inputs;

    float max_advance;
    float max_turn_angle;

    int tmp;

    float intensity;

    int flg_result;
    int flg_noise=0;

    float noise_advance,noise_angle;
    movement movements;
    char path[100];
    char object_name[20];

    float result;
    float final_x,final_y;

    int flg_finish;

    int mini_sm=1;

    // it sets the environment's path
    strcpy(path,"./src/simulator/src/data/");


    while( ros::ok()  )
    {
        flagOnce = 1;
        cta_steps = 0;
        mini_sm =1;

        while(params.run )
        {
            // it gets sensory data
            ros::spinOnce();
            if (!params.turtle)
            {
                get_light_values(&intensity,light_readings); // function in ~/catkin_ws/src/simulator/src/motion_planner/motion_planner_utilities.h

                get_lidar_values(lidar_readings,params.robot_x,
                                 params.robot_y,params.robot_theta,params.turtle); // function in ~/catkin_ws/src/simulator/src/motion_planner/motion_planner_utilities.h
            }
            else
            {
                get_light_values_turtle(&intensity,light_readings); // function in ~/catkin_ws/src/simulator/src/motion_planner/motion_planner_utilities.h
                for( i=0; i<512; i++)
                {
                    lidar_readings[i] = lasers[i];
                }
            }

            // it quantizes the sensory data
            q_light = quantize_light(light_readings); // function in ~/catkin_ws/src/simulator/src/motion_planner/motion_planner_utilities.h

            q_inputs = quantize_inputs(lidar_readings,params.laser_num_sensors,params.laser_value); // function in ~/catkin_ws/src/simulator/src/motion_planner/motion_planner_utilities.h

            max_advance=params.robot_max_advance;
            max_turn_angle=params.robot_turn_angle;

            switch ( params.behavior)
            {

            case 1:
                // This function sends light sensory data to a function that follows a light source and it issues
                // the actions that the robot needs to perfom.
                // It is located in ~/catkin_ws/src/simulator/src/state_machines/light_follower.h
                flg_result = light_follower(intensity, light_readings,&movements);
                if(flg_result == 1) stop();
                break;

            case 2:
                // This function sends light sensory data to an state machine that follows a light source and it issues
                // the actions that the robot needs to perfom.
                // It is located in ~/catkin_ws/src/simulator/src/state_machines/sm_destination.h
                if(flagOnce)
                {
                    est_sig = 1;
                    flagOnce = 0;
                }
                flg_result = sm_destination(intensity,q_light,&movements,&est_sig,params.robot_max_advance,params.robot_turn_angle);
                if(flg_result == 1) stop();

                break;

            case 3:
                // This function sends quantized sensory data to an state machine that avoids obstacles and it issues
                // the actions that the robot needs to perfom.
                // It is located in ~/catkin_ws/src/simulator/src/state_machines/sm_avoidance.h
                if(flagOnce)
                {
                    est_sig = 0;
                    flagOnce = 0;
                }
                sm_avoid_obstacles(q_inputs,&movements,&est_sig ,params.robot_max_advance ,params.robot_turn_angle);
                break;

            case 4:
                // This function sends quantized sensory data to an state machine that follows a light source and avoids obstacles
                // and it issues the actions that the robot needs to perfom.
                // It is located in ~/catkin_ws/src/simulator/src/state_machines/sm_avoidance_destination.h
                if(flagOnce)
                {
                    est_sig = 0;
                    flagOnce = 0;
                }
                flg_result=sm_avoidance_destination(intensity,q_light,q_inputs,&movements,&est_sig,
                                                    params.robot_max_advance ,params.robot_turn_angle);

                if(flg_result == 1) stop();
                break;

            case 5:
                // This function sends the intensity and the quantized sensory data to a Clips node and it receives the actions that
                // the robot needs to perfom to avoid obstacles and reach a light source according to first order logic
                // It is located in ~/catkin_ws/src/simulator/src/behaviors/oracle.h
                result=oracle_clips(intensity,q_light,q_inputs,&movements,max_advance ,max_turn_angle);
                if(result == 1.0) stop();
                break;
	    
	    case 66:
		// it finds a path from the origen to a destination using bfs
                if(flagOnce)
                {
                    for(i = 0; i < 200; i++) steps[i].node = -1;

                    // it finds a path from the origen to a destination using first search
                    bfs(params.robot_x ,params.robot_y ,params.light_x ,params.light_y ,params.world_name,steps);
                    print_algorithm_graph (steps);
                    i = 0;
                    final_x = params.light_x;
                    final_y = params.light_y;
                    set_light_position(steps[i].x,steps[i].y);
                    printf("New Light %d: x = %f  y = %f \n",i,steps[i].x,steps[i].y);
                    flagOnce = 0;
                    flg_finish=0;
                    est_sig = 0;
                    movements.twist=0.0;
                    movements.advance =0.0;
                }
                else
                {
                    //flg_result=sm_avoidance_destination(intensity,q_light,q_inputs,&movements,&est_sig,                                                        //params.robot_max_advance ,params.robot_turn_angle);
                    //flg_result = oracle_clips(intensity,q_light,q_inputs,&movements,max_advance ,max_turn_angle);
		   flg_result=sm_avoidance_destination(intensity,q_light,q_inputs,&movements,&est_sig,
                                                        params.robot_max_advance ,params.robot_turn_angle);

                    if(flg_result == 1)
                    {
                        if(flg_finish == 1)
                            stop();
                        else
                        {
                            if(steps[i].node != -1)
                            {
                                set_light_position(steps[i].x,steps[i].y);
                                printf("New Light %d: x = %f  y = %f \n",i,steps[i].x,steps[i].y);
                                printf("Node %d\n",steps[i].node);
                                i++;
                                //printf("type a number \n");
                                //scanf("%d",&tmp);
                            }
                            else
                            {
                                set_light_position(final_x,final_y);
                                printf("New Light %d: x = %f  y = %f \n",i,final_x,final_y);
                                flg_finish = 1;
                            }
                        }
                    }
                }
		break;
            case 6:
                // it finds a path from the origen to a destination using depth first search
                if(flagOnce)
                {
                    for(i = 0; i < 200; i++) steps[i].node = -1;

                    // it finds a path from the origen to a destination using first search
                    dfs(params.robot_x ,params.robot_y ,params.light_x ,params.light_y ,params.world_name,steps);
                    print_algorithm_graph (steps);
                    i = 0;
                    final_x = params.light_x;
                    final_y = params.light_y;
                    set_light_position(steps[i].x,steps[i].y);
                    printf("New Light %d: x = %f  y = %f \n",i,steps[i].x,steps[i].y);
                    flagOnce = 0;
                    flg_finish=0;
                    est_sig = 0;
                    movements.twist=0.0;
                    movements.advance =0.0;
                }
                else
                {
                    //flg_result=sm_avoidance_destination(intensity,q_light,q_inputs,&movements,&est_sig,                                                        //params.robot_max_advance ,params.robot_turn_angle);
                    //flg_result = oracle_clips(intensity,q_light,q_inputs,&movements,max_advance ,max_turn_angle);
		   flg_result=sm_avoidance_destination(intensity,q_light,q_inputs,&movements,&est_sig,
                                                        params.robot_max_advance ,params.robot_turn_angle);

                    if(flg_result == 1)
                    {
                        if(flg_finish == 1)
                            stop();
                        else
                        {
                            if(steps[i].node != -1)
                            {
                                set_light_position(steps[i].x,steps[i].y);
                                printf("New Light %d: x = %f  y = %f \n",i,steps[i].x,steps[i].y);
                                printf("Node %d\n",steps[i].node);
                                i++;
                                //printf("type a number \n");
                                //scanf("%d",&tmp);
                            }
                            else
                            {
                                set_light_position(final_x,final_y);
                                printf("New Light %d: x = %f  y = %f \n",i,final_x,final_y);
                                flg_finish = 1;
                            }
                        }
                    }
                }

                break;
	    case 77:
		if(flagOnce)
                {
                    for(i = 0; i < 200; i++)steps[i].node=-1;
                    // it finds a path from the origen to a destination using the Dijkstra algorithm
                    Astar(params.robot_x ,params.robot_y ,params.light_x ,params.light_y ,params.world_name,steps);
                    print_algorithm_graph (steps);
                    i=0;
                    final_x=params.light_x;
                    final_y= params.light_y;
                    set_light_position(steps[i].x,steps[i].y);
                    printf("New Light %d: x = %f  y = %f \n",i,steps[i].x,steps[i].y);
                    flagOnce = 0;
                    flg_finish=0;
                    est_sig = 0;
                    movements.twist=0.0;
                    movements.advance =0.0;
                }
                else
                {
                    flg_result=sm_avoidance_destination(intensity,q_light,q_inputs,&movements,&est_sig,
                                                        params.robot_max_advance ,params.robot_turn_angle);

                    if(flg_result == 1)
                    {
                        if(flg_finish == 1) stop();
                        else
                        {
                            if(steps[i].node != -1)
                            {
                                set_light_position(steps[i].x,steps[i].y);
                                printf("New Light %d: x = %f  y = %f \n",i,steps[i].x,steps[i].y);
                                printf("Node %d\n",steps[i].node);
                                i++;
                                //printf("type a number \n");
                                //scanf("%d",&tmp);
                            }
                            else
                            {
                                set_light_position(final_x,final_y);
                                printf("New Light %d: x = %f  y = %f \n",i,final_x,final_y);
                                flg_finish=1;
                            }
                        }
                    }
                }
                break;


            case 7:
                if(flagOnce)
                {
                    for(i = 0; i < 200; i++)steps[i].node=-1;
                    // it finds a path from the origen to a destination using the Dijkstra algorithm
                    dijkstra(params.robot_x ,params.robot_y ,params.light_x ,params.light_y ,params.world_name,steps);
                    print_algorithm_graph (steps);
                    i=0;
                    final_x=params.light_x;
                    final_y= params.light_y;
                    set_light_position(steps[i].x,steps[i].y);
                    printf("New Light %d: x = %f  y = %f \n",i,steps[i].x,steps[i].y);
                    flagOnce = 0;
                    flg_finish=0;
                    est_sig = 0;
                    movements.twist=0.0;
                    movements.advance =0.0;
                }
                else
                {
                    flg_result=sm_avoidance_destination(intensity,q_light,q_inputs,&movements,&est_sig,
                                                        params.robot_max_advance ,params.robot_turn_angle);

                    if(flg_result == 1)
                    {
                        if(flg_finish == 1) stop();
                        else
                        {
                            if(steps[i].node != -1)
                            {
                                set_light_position(steps[i].x,steps[i].y);
                                printf("New Light %d: x = %f  y = %f \n",i,steps[i].x,steps[i].y);
                                printf("Node %d\n",steps[i].node);
                                i++;
                                //printf("type a number \n");
                                //scanf("%d",&tmp);
                            }
                            else
                            {
                                set_light_position(final_x,final_y);
                                printf("New Light %d: x = %f  y = %f \n",i,final_x,final_y);
                                flg_finish=1;
                            }
                        }
                    }
                }
                break;

            case 8:
                // Here it goes your code for selection 8
                if(flagOnce)
                {
                    est_sig = 0;
                    flagOnce = 0;
                }
                user_sm(intensity,light_readings, lidar_readings, params.laser_num_sensors,params.laser_value,
                        q_light,q_inputs,&movements,&est_sig ,params.robot_max_advance ,params.robot_turn_angle);
                break;
	    case 88:
                // Here it goes your code for selection 8
                if(flagOnce)
                {
                    est_sig = 0;
                    flagOnce = 0;
                }
                pared_sm(intensity,light_readings, lidar_readings, params.laser_num_sensors,params.laser_value,
                        q_light,q_inputs,&movements,&est_sig ,params.robot_max_advance ,params.robot_turn_angle);
                break;
	    case 20:
		if(flagOnce)
                {
		    est_sig = 0;
                    flagOnce = 0;
                }
		flg_result = campos(intensity,light_readings, lidar_readings, params.laser_num_sensors,params.laser_value,
                        q_light,q_inputs,&movements, &est_sig ,params.robot_max_advance ,params.robot_turn_angle);
		if(flg_result == 1) stop();
		break;	

            case 9:

                flg_result=light_follower(intensity,light_readings,&movements);
                if(flg_result == 1)
                    set_light_position(.5,.25);

                break;

            
            case 10:

                


                switch(mini_sm)
                {
                    case 1:
                        movements.twist = 0;
                        movements.advance = .1;
                        mini_sm=2;
                    break;
                    case 2:
                        movements.twist = 0;
                        movements.advance = 0;    
                        strcpy(object_name,"a");
                        if(object_interaction(GRASP,object_name))
                            mini_sm=3;
                        else
                            mini_sm=1;
                    break;
                    case 3:
                        movements.twist = 3.1416/2;
                        movements.advance = .1;
                        mini_sm=4;
                    break;
                    case 4:
                        movements.twist = 0;
                        movements.advance = 0; 
                        if(object_interaction(RELEASE,object_name))
                            mini_sm=5;

                    break;
                    case 5:
                        movements.twist = -3.1416/2;
                        movements.advance = 0;
                        mini_sm=6;
                    break;
                    case 6:
                        movements.twist = 0;
                        movements.advance = .1;
                        mini_sm=77;
                    break;
                    case 77:
                        movements.twist = 0;
                        movements.advance = 0;    
                        strcpy(object_name,"b");
                        if(object_interaction(GRASP,object_name))
                            mini_sm=7;
                        else
                            mini_sm=6;
                    break;
                    case 7:
                        movements.twist = 3.1416/2;
                        movements.advance = .1;
                        mini_sm=8;
                    break;
                    case 8:
                        movements.twist = 0;
                        movements.advance = 0; 
                        if(object_interaction(RELEASE,object_name))
                            mini_sm=9;
                    break;
                    case 9:
                        movements.twist = -3.1416/2;
                        movements.advance = .0;
                        mini_sm=10;
                    break;
                    case 10:
                        movements.twist = 0;
                        movements.advance = .1;
                        mini_sm=11;
                    break;
                    case 11:
                        movements.twist = 0;
                        movements.advance = 0;    
                        strcpy(object_name,"c");
                        if(object_interaction(GRASP,object_name))
                            mini_sm=12;
                        else
                            mini_sm=10;
                    break;
                    case 12:
                        movements.twist = 3.1416/2;
                        movements.advance = .1;
                        mini_sm=13;
                    break;
                    case 13:
                        movements.twist = 0;
                        movements.advance = 0; 
                        if(object_interaction(RELEASE,object_name))
                            mini_sm=14;

                    break;
                    case 14:
                        movements.twist = -3.1416/2;
                        movements.advance = .1;
                        mini_sm=15;
                    break;
                    case 15:
                        movements.twist = 0;
                        movements.advance = 0;    
                        strcpy(object_name,"d");
                        if(object_interaction(GRASP,object_name))
                            mini_sm=166;
                        else
                            mini_sm=14;
                    break;
                    case 166:
                        movements.twist = -3.1416/2;
                        movements.advance = .3;
                        mini_sm=16;
                    break;
                    case 16:
                        movements.twist = -3.1416/2;
                        movements.advance = .4;
                        mini_sm=17;
                    break;
                    case 17:
                        movements.twist = 0;
                        movements.advance = 0; 
                        if(object_interaction(RELEASE,object_name))
                            mini_sm=18;

                    break;
                    case 18:
                        movements.twist = -3.1416/2;
                        movements.advance = .1;
                        mini_sm=19;
                    break;
                    case 19:
                        stop();
                    break;
                    
                }

                

                break;


            default:
                printf(" ******* SELECTION NO DEFINED *******\n");
                movements.twist = 3.1416/4;
                movements.advance = .03;
                break;
            }

            ros::spinOnce();
            printf("\n\n             MOTION PLANNER \n________________________________\n");
            printf("Light: x = %f  y = %f \n",params.light_x,params.light_y);
            printf("Robot: x = %f  y = %f \n",params.robot_x,params.robot_y);
            printf("Step: %d \n",cta_steps++);
            printf("Movement: twist: %f advance: %f \n" ,movements.twist ,movements.advance );

            flg_noise = params.noise;
            if(flg_noise == 1)
            {
                // it adds noise to the movement
                get_random_advance_angle(&noise_advance,&noise_angle,path);
                movements.twist = movements.twist + noise_angle;
                //printf("angle + noise %f\n",movements.twist);
                movements.advance = movements.advance + noise_advance;
                //printf("distance + noise %f\n",movements.advance );
            }
            move_robot(movements.twist,movements.advance,lidar_readings);
            ros::spinOnce();
            new_simulation = 0;
            r.sleep();
        }
        ros::spinOnce();
        r.sleep();
    }
}
