#include "ros/ros.h"
#include "../utilities/simulator_structures.h"
#include "motion_planner_utilities.h"

#include "../state_machines/st_light_follower.h"
#include "../state_machines/dijkstra.h"
#include "../state_machines/dfs.h"

int main(int argc ,char **argv)
{  
  ros::init(argc ,argv ,"simulator_motion_planner_node");
  ros::NodeHandle n;
  float lecturas_lidar[1024];
  float lecturas_light[8];
  step steps[200];
  int sensor;
  int i;
  int flagOnce;
  for(i = 0; i < 200; i++)steps[i].node=-1;
  
  movement movements;
  while( ros::ok()  )
  {
    simulation_init();// It waits for button "Run simulation"
    flagOnce = 1;

    while(params.run ) 
    {
      printf("%f \n",params.robot_x );
      get_lidar_values(lecturas_lidar);
      get_light_values(lecturas_light);
    
      switch ( params.behavior)
      {
        case 1:
          sm_light_follower(lecturas_light,&movements);
        break;

        case 2:
          movements.twist = 0.5; 
          movements.advance = .1;
        break;
        case 3:
          movements.twist = 0.5; 
          movements.advance = -.1;
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

        default:
          movements.twist = 1.5707; 
          movements.advance = .1;
        break;
    
      }
      move_robot(movements.twist,movements.advance);
      ros::spinOnce();
      new_simulation =0;
      params = get_params();
    }
    ros::spinOnce();
 
  }

}