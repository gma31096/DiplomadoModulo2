#include "ros/ros.h"
#include "simulator/Parameters.h"
#include "simulator/robot_step.h"

//ros::ServiceClient *clientPtr; //pointer for a client

/*
void getParameters(const simulator::Parameters::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->world_name.c_str());

  simulator::move_test srv;
  srv.request.theta = 1.5707; //just some variables to give the service some structure.
  srv.request.distance = 300;

  ros::ServiceClient client = (ros::ServiceClient)*clientPtr; //dereference the clientPtr

  if(client.call(srv)) //request service from the client
  {
      printf("Success = %d", (int)srv.response.success);
  }   
  else
  {
      printf("Failed to call service from motor_control_node");    
  }


}*/

int main(int argc, char **argv)
{
  ros::init(argc, argv, "motion_planner");
  ros::NodeHandle n;
  //ros::Subscriber sub = n.subscribe("/parameters", 1, getParameters);
  printf("1: %f \n",atof(argv[1]));
  ros::ServiceClient client = n.serviceClient<simulator::robot_step>("robot_step"); //create the client
  //clientPtr = &client; //give the address of the client to the clientPtr
  //ros::spin();
  simulator::robot_step srv;
  srv.request.theta = atof(argv[1]); //just some variables to give the service some structure.
  srv.request.distance = atof(argv[2]);

  //ros::ServiceClient client = (ros::ServiceClient)//*clientPtr; //dereference the clientPtr

  if(client.call(srv)) //request service from the client
  {
      printf("Success = %d \n", (int)srv.response.success);
  }   
  else
  {
      printf("Failed to call service from motor_control_node");    
  }

  return 0;
}