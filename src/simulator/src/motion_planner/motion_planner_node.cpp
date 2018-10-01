#include "ros/ros.h"
#include "../utilities/simulator_structures.h"
#include "motion_planner_utilities.h"

int main(int argc ,char **argv)
{  
  ros::init(argc ,argv ,"simulator_motion_planner_node");
  ros::NodeHandle n;
  float lecturas[1024];
  
  while(ros::ok())
  {
    simulation_init();// It waits for button "Run simulation"
    for(int i = 0; i < 10; i++) 
    {
      get_lidar_values(lecturas);
      move_robot(.5 ,.1);
      ros::spinOnce();
      new_simulation =0;
    }
      ros::spinOnce();
  }
  return 0;
}






 /* sensors_laser = get_sensors_laser();
  sensor_light = get_sensor_light();

  while( params.steps--  )
  {
    switch ( params.behavior )
    {
      case 1:
            answer=state_machine_one(sensors_laser,sensor_light,state);
      break;
      case 2:
            answer=state_machine_one(sensors_laser,sensor_light,state);
      break;
    
    }

     gui(new_pos = move_robot(answer));


  }
  */