#include "ros/ros.h"
#include "../utilities/simulator_structures.h"
#include "motion_planner_utilities.h"
#include "simulator/simulator_robot_step.h"
#include "simulator/simulator_parameters.h"
#include <string.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "simulator_motion_planner_node");
  parameters params;

  params = wait_start();

  for(int i=0; i<10; i++) 
    move_gui(1.5707,200);
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
  
  return 0;
}


/*




  */