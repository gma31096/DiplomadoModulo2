#include "ros/ros.h"
#include "../utilities/simulator_structures.h"
#include "../utilities/utilities.h"

#include "simulator/simulator_robot_laser_values.h"
#include "simulator/simulator_robot_step.h"
#include "simulator/simulator_parameters.h"
#include "simulator/simulator_laser.h"
#include <string.h>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

parameters params;


int laser_gui(float *lasers)
{
  
  ros::NodeHandle n;
  ros::ServiceClient client;
  simulator::simulator_robot_laser_values srv;
  client = n.serviceClient<simulator::simulator_robot_laser_values>("simulator_robot_laser_values"); //create the client
  
   for(int i=0;i<1024;i++)
      srv.request.sensors[i]=lasers[i];
        
  if (client.call(srv))
  {     
      //printf("%s\n","Hecho lasers" );
  }
  else
  {
    ROS_ERROR("Failed to call service simulator_robot_step");
    
  }
  return 1;
}


void get_lidar_values(float *lectures )
{
  ros::NodeHandle n;
  ros::ServiceClient client;
  simulator::simulator_laser srv;
  client = n.serviceClient<simulator::simulator_laser>("simulator_laser"); //create the client
  srv.request.robot_x =params.robot_x ;
  srv.request.robot_y =params.robot_y ;
  srv.request.robot_theta = params.robot_theta;
  srv.request.new_simulation =0;

 
  if (client.call(srv))
  {
    
    for(int i=0;i<1024;i++)
      //printf("Valor : %f \n",lectures[i] = srv.response.sensors[i]);
      lectures[i] = srv.response.sensors[i];
    laser_gui(lectures);
  }
  else
  {
    ROS_ERROR("Failed to call service get_parameters"); 
  }
}

int main(int argc, char *argv[])
{	
	ros::init(argc, argv, "simulator_pub_node");
	ros::NodeHandle n;
	
	float lecturas[1024];

	while(ros::ok())
	{
	params = wait_start();
    get_lidar_values(lecturas);

	ros::spinOnce();
	
	}
	return 0;
}