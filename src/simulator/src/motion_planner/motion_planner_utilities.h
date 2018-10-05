#include "ros/ros.h"
#include "simulator/simulator_robot_step.h"
#include "simulator/simulator_parameters.h"
#include "simulator/simulator_robot_laser_values.h"
#include "simulator/simulator_base.h"
#include "simulator/simulator_laser.h"
#include "simulator/simulator_light.h"
#include "simulator/simulator_algorithm_result.h"
#include <string.h>

parameters wait_start();
int move_gui(float angle ,float distance ,next_position *next );
int laser_gui(float *lasers );
float check_collision(float theta ,float distance ,int new_simulation );
void get_lidar_values(float *lectures );
int move_robot(float theta,float advance);
int get_light_values();

next_position next;
int new_simulation = 1;
parameters params;


parameters get_params()
{
  parameters params;

  ros::NodeHandle n;
  ros::ServiceClient client;
  simulator::simulator_parameters srv;
  client = n.serviceClient<simulator::simulator_parameters>("simulator_get_parameters"); //create the client
  
  srv.request.request=1;
  params.run=0;

    if (client.call(srv))
    {
      params.robot_x             = srv.response.robot_x   ;
      params.robot_y             = srv.response.robot_y   ;
      params.robot_theta         = srv.response.robot_theta   ;    
      params.robot_radio         = srv.response.robot_radio   ;    
      params.robot_max_advance   = srv.response.robot_max_advance   ;          
      params.robot_turn_angle    = srv.response.robot_turn_angle   ;         
      params.laser_num_sensors   = srv.response.laser_num_sensors   ;          
      params.laser_origin        = srv.response.laser_origin         ;     
      params.laser_range         = srv.response.laser_range   ;    
      params.laser_value         = srv.response.laser_value   ;    
      strcpy(params.world_name,srv.response.world_name.c_str());       
      params.noise               = srv.response.noise   ;   
      params.run                 = srv.response.run   ; 
      params.light_x             = srv.response.light_x;
      params.light_y             = srv.response.light_y;
      params.behavior            = srv.response.behavior;
      params.steps               = srv.response.steps; 
    }
    else
    {
      ROS_ERROR("Failed to call service get_parameters");
      
    }
  
  return params;
}


void simulation_init()
{
  params = wait_start();
  next.robot_x = params.robot_x; 
  next.robot_y = params.robot_y;
  next.robot_theta = params.robot_theta;
  new_simulation = 1;
}

parameters wait_start()
{
  parameters params;

  ros::NodeHandle n;
  ros::ServiceClient client;
  simulator::simulator_parameters srv;
  client = n.serviceClient<simulator::simulator_parameters>("simulator_get_parameters"); //create the client
  
  srv.request.request=1;
  params.run=0;

  while(! params.run)
  {
    if (client.call(srv))
    {
      params.robot_x             = srv.response.robot_x   ;
      params.robot_y             = srv.response.robot_y   ;
      params.robot_theta         = srv.response.robot_theta   ;    
      params.robot_radio         = srv.response.robot_radio   ;    
      params.robot_max_advance   = srv.response.robot_max_advance   ;          
      params.robot_turn_angle    = srv.response.robot_turn_angle   ;         
      params.laser_num_sensors   = srv.response.laser_num_sensors   ;          
      params.laser_origin        = srv.response.laser_origin         ;     
      params.laser_range         = srv.response.laser_range   ;    
      params.laser_value         = srv.response.laser_value   ;    
      strcpy(params.world_name,srv.response.world_name.c_str());       
      params.noise               = srv.response.noise   ;   
      params.run                 = srv.response.run   ; 
      params.light_x             = srv.response.light_x;
      params.light_y             = srv.response.light_y;
      params.behavior            = srv.response.behavior; 
    }
    else
    {
      ROS_ERROR("Failed to call service get_parameters");
      
    }
  }

    printf("Inicial parameters:\n" );
  printf("robot_x %f \n",params.robot_x )       ;   
  printf("robot_y %f \n",params.robot_y )      ;
  printf("robot_theta %f \n",params.robot_theta             );
  printf("robot_radio %f \n",params.robot_radio             );
  printf("robot_max_advance %f \n",params.robot_max_advance  );           
  printf("robot_turn_angle %f \n",params.robot_turn_angle  );           
  printf("laser_num_sensors %d \n",params.laser_num_sensors);             
  printf("laser_origin %f \n",params.laser_origin        )        ;     
  printf("laser_range %f \n",params.laser_range        );    
  printf("laser_value %f \n",params.laser_value        );    
  printf("world_name %s \n",params.world_name);       
  printf("noise %d \n",params.noise  );   
  printf("run %d \n",params.run    ) ;     
  printf("light_x %f \n",params.light_x    );
  printf("light_y %f \n",params.light_y   );
  printf("behavior %d \n",params.behavior ); 
  printf("Steps %d \n",params.steps ); 


  return params;
}


int move_gui(float angle ,float distance ,next_position *next )
{
  ros::NodeHandle n;
  ros::ServiceClient client;
  simulator::simulator_robot_step srv;
  client = n.serviceClient<simulator::simulator_robot_step>("simulator_robot_step"); //create the client
  
  srv.request.theta=angle;
  srv.request.distance=distance;
  
  if (client.call(srv))
  {     
      next->robot_x = srv.response.robot_x;
      next->robot_y = srv.response.robot_y;
      next->robot_theta =srv.response.theta;
      //printf("%s\n","Hecho" );
  }
  else
  {
    ROS_ERROR("Failed to call service simulator_robot_step");
    
  }
  return 1;
}

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
    ROS_ERROR("Failed to call service simulator_robot_laser_values");
    
  }
  return 1;
}

float check_collision(float theta ,float distance ,int new_simulation )
{
  float final_distance=0;
  ros::NodeHandle n;
  ros::ServiceClient client;
  simulator::simulator_base srv;
  client = n.serviceClient<simulator::simulator_base>("simulator_base"); //create the client
  
  srv.request.x1 = next.robot_x;
  srv.request.y1 = next.robot_y;
  srv.request.theta = next.robot_theta+theta;
  srv.request.distance = distance;
  srv.request.new_simulation =new_simulation;
 
  if (client.call(srv))
  {
    final_distance = srv.response.distance;
  }
  else
  {
    ROS_ERROR("Failed to call service simulator_base");    
  }

  return final_distance;
}

void get_lidar_values(float *lectures )
{
  ros::NodeHandle n;
  ros::ServiceClient client;
  simulator::simulator_laser srv;
  client = n.serviceClient<simulator::simulator_laser>("simulator_laser"); //create the client
  srv.request.robot_x = next.robot_x ;
  srv.request.robot_y = next.robot_y ;
  srv.request.robot_theta = next.robot_theta;
  srv.request.new_simulation =new_simulation;

 
  if (client.call(srv))
  {
    
    for(int i=0;i<1024;i++)
      //printf("Valor : %f \n",lectures[i] = srv.response.sensors[i]);
      lectures[i] = srv.response.sensors[i];
    laser_gui(lectures);
  }
  else
  {
    ROS_ERROR("Failed to call service simulator_laser"); 
  }
}


int move_robot(float theta,float advance)
{
  float res;
  res = check_collision(theta ,advance ,new_simulation);
  move_gui(theta ,res ,&next);
  ros::spinOnce();
  return 1;
}



int get_light_values(float *values)
{
  ros::NodeHandle n;
  ros::ServiceClient client;
  simulator::simulator_light srv;
  client = n.serviceClient<simulator::simulator_light>("simulator_light"); //create the client
  srv.request.req=1;

 
  if (client.call(srv))
  {
      for(int i=0;i<8;i++)
         values[i]=srv.response.values[i];
  }
  else
  {
    ROS_ERROR("Failed to call service  simulator_light"); 
  } 
}



int print_algorithm_graph (step *steps )
{
  ros::NodeHandle n;
  ros::ServiceClient client;
  simulator::simulator_algorithm_result srv;
  client = n.serviceClient<simulator::simulator_algorithm_result>("simulator_print_graph"); //create the client
  
  for(int i=0;i<200;i++)
    srv.request.nodes_algorithm[i] = steps[i].node;

  if (client.call(srv))
  {          
      //printf("%s\n","Hecho" );
  }
  else
  {
    ROS_ERROR("Failed to call service simulator_print_graph");
    
  }
  return 1;
}