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
  for(i = 0; i < 200; i++)steps[i].node=-1;
  
  movement movements;
  while(ros::ok())
  {
    simulation_init();// It waits for button "Run simulation"
    for(int k = 0; k < 2; k++) 
    {
      
      get_lidar_values(lecturas_lidar);
      get_light_values(lecturas_light);
    
      switch ( params.behavior )
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
          for(i = 0; i < 200; i++)steps[i].node=-1;
          movements.twist = 3.1415; 
          movements.advance = .1;
          dijkstra(17,20,params.world_name,steps);
          i=0;
          while(steps[i].node != -1)
          {
            printf("%d  %d  \n",i,steps[i].node);
            i++;
          }
          print_algorithm_graph (steps);

        break;

        case 5:
          for(i = 0; i < 200; i++)steps[i].node=-1;
          movements.twist = 3.1415; 
          movements.advance = -.1;
          dfs(17,20,params.world_name,steps);
          i=0;
          while(steps[i].node != -1)
          {
            printf("%d  %d  \n",i,steps[i].node);
            i++;
          }
          print_algorithm_graph (steps);

        break;

        default:
          movements.twist = 1.5707; 
          movements.advance = .1;
        break;
    
      }
      move_robot(movements.twist,movements.advance);
      ros::spinOnce();
      new_simulation =0;
      ros::spinOnce();
    }
    ros::spinOnce();
  }
  return 0;
}