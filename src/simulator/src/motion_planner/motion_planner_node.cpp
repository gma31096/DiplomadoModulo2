#include "ros/ros.h"
#include "../utilities/simulator_structures.h"
#include "motion_planner_utilities.h"
#include "simulator/simulator_robot_step.h"
#include "simulator/simulator_parameters.h"
#include "simulator/simulator_base.h"
#include <string.h>


float check_collision(float x1 ,float y1, float theta ,float distance )
{
  float final_distance=0;
  ros::NodeHandle n;
  ros::ServiceClient client;
  simulator::simulator_base srv;
  client = n.serviceClient<simulator::simulator_base>("simulator_base"); //create the client
  
  srv.request.x1 = x1;
  srv.request.y1 = y1;
  srv.request.theta = theta;
  srv.request.distance = distance;
 
    if (client.call(srv))
    {
      final_distance = srv.response.distance;
  
    }
    else
    {
      ROS_ERROR("Failed to call service get_parameters");
      
    }

    return final_distance;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "simulator_motion_planner_node");
  parameters params;
  float res;
  next_position next;
  while(1)
  {
    params = wait_start();

    next.robot_x = params.robot_x; 
    next.robot_y = params.robot_y;

    for(int i=0; i<10; i++) 
      {
        res= check_collision(next.robot_x ,next.robot_y,.7,.1 );
        printf("check_collision %f :\n",res);
        move_gui(0.7,res,&next);
        printf("%f %f %f\n",next.robot_x,next.robot_y,next.robot_theta );
        //wait_start();
      }
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
  
  return 0;
}


/*




  */