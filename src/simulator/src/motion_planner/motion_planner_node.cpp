#include "ros/ros.h"
#include "../utilities/simulator_structures.h"
#include "motion_planner_utilities.h"

#include "../state_machines/st_light_follower.h"

int main(int argc ,char **argv)
{  
  ros::init(argc ,argv ,"simulator_motion_planner_node");
  ros::NodeHandle n;
  float lecturas_lidar[1024];
  float lecturas_light[8];
  int sensor;
  movement movements;
  while(ros::ok())
  {
    simulation_init();// It waits for button "Run simulation"
    for(int i = 0; i < 10; i++) 
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