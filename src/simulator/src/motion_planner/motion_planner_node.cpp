#include "ros/ros.h"
#include "../utilities/simulator_structures.h"
#include "motion_planner_utilities.h"

#include "../state_machines/sm_light_follower.h"
#include "../state_machines/sm_avoidance.h"
#include "../state_machines/sm_avoidance_destination.h"
#include "../state_machines/dijkstra.h"
#include "../state_machines/dfs.h"

parameters params;

void parametersCallback(const simulator::Parameters::ConstPtr& paramss)
{
  params.robot_x             = paramss->robot_x   ;
  params.robot_y             = paramss->robot_y   ;
  params.robot_theta         = paramss->robot_theta   ;    
  params.robot_radio         = paramss->robot_radio   ;    
  params.robot_max_advance   = paramss->robot_max_advance   ;          
  params.robot_turn_angle    = paramss->robot_turn_angle   ;         
  params.laser_num_sensors   = paramss->laser_num_sensors   ;          
  params.laser_origin        = paramss->laser_origin         ;     
  params.laser_range         = paramss->laser_range   ;    
  params.laser_value         = paramss->laser_value   ;    
  strcpy(params.world_name ,paramss -> world_name.c_str());       
  params.noise               = paramss->noise   ;   
  params.run                 = paramss->run   ; 
  params.light_x             = paramss->light_x;
  params.light_y             = paramss->light_y;
  params.behavior            = paramss->behavior; 

}


int main(int argc ,char **argv)
{  
  ros::init(argc ,argv ,"simulator_motion_planner_node");
  ros::NodeHandle n;
  ros::Subscriber params_sub = n.subscribe("simulator_parameters_pub",0, parametersCallback);

  float lecturas_lidar[100];
  float lecturas_light[8];
  step steps[200];
  int sensor;
  int i;
  int flagOnce;
  int est_sig;
  for(i = 0; i < 200; i++)steps[i].node=-1;
  
  movement movements;
  while( ros::ok()  )
  {
    flagOnce = 1; 
    while(params.run) 
    {
      get_light_values(lecturas_light);
      get_lidar_values(lecturas_lidar);
      switch ( params.behavior)
      {
        case 1:
          sm_light_follower(lecturas_light,&movements);
        break;

        case 2:
          if(flagOnce)
          {
            est_sig = 0;
            flagOnce = 0;
          }
          sm_avoid_obstacles(quantize_inputs(lecturas_lidar,params.laser_num_sensors,params.laser_value),&movements,&est_sig ,params.robot_max_advance ,params.robot_turn_angle);
          
        break;
        case 3:
          if(flagOnce)
          {
            est_sig = 0;
            flagOnce = 0;
          }
          sm_avoidance_destination(quantize_light(lecturas_light),quantize_inputs(lecturas_lidar,params.laser_num_sensors,params.laser_value),&movements,&est_sig ,params.robot_max_advance ,params.robot_turn_angle);
        break;
        case 4:
          if(flagOnce)
          {
            for(i = 0; i < 200; i++)steps[i].node=-1;
            dijkstra(params.robot_x ,params.robot_y ,params.light_x ,params.light_y ,params.world_name,steps);
            i=0;
            while(steps[i].node != -1)
            {
              printf("%d  %d  \n",i,steps[i].node);
              i++;
            }
            print_algorithm_graph (steps);
            flagOnce = 0;
          }
          movements.twist = 3.1415; 
          movements.advance = 0;
      
        break;

        case 5:
        
          if(flagOnce)
          {
            for(i = 0; i < 200; i++)steps[i].node=-1;
            dfs(params.robot_x ,params.robot_y ,params.light_x ,params.light_y ,params.world_name,steps);
            i=0;
            while(steps[i].node != -1)
            {
              printf("%d  %d  \n",i,steps[i].node);
              i++;
            }
            print_algorithm_graph (steps);
            flagOnce = 0;
          }

          movements.twist = 3.1415; 
          movements.advance = 0;
        break;
        case 6:
          movements.twist = 0.5; 
          movements.advance = .1;
        break;

        default:
          movements.twist = 1.5707; 
          movements.advance = .1;
        break;
    
      }
      //printf("-- %f  %f \n",movements.twist ,movements.advance  );
      move_robot(movements.twist,movements.advance);
      ros::spinOnce();
      new_simulation =0;
      //params = get_params();
    }
    ros::spinOnce();
 
  }

}