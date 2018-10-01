#include "ros/ros.h"
#include "../utilities/simulator_structures.h"
#include "../utilities/utilities.h"
#include "simulator/simulator_light.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


parameters params;

bool get_intensities(simulator::simulator_light::Request  &req ,simulator::simulator_light::Response &res)
{
 
	
	float x,y;
	int sensor;
	float step = 3.1415/4; 
	float values[8];
	params = wait_start();

	for(int i = 0; i < 8; i++)
	{
		x = params.robot_radio * cos( params.robot_theta + i * step) + params.robot_x;
		y = params.robot_radio * sin( params.robot_theta + i * step) + params.robot_y;
		printf("%d %f %f\n",i,x,y );
		res.values[i] = values[i] = sqrt( pow(x - params.light_x ,2) + pow(y - params.light_y,2));
		printf("%d: %f \n",i,values[i] );
	}

	sensor = 0;

	

	for(int i = 1; i < 8; i++)
	{
		if( values[i] < values[sensor])
			sensor = i;
	}
	printf("El sensor %d \n",sensor );


	return true;

}

int main(int argc, char *argv[])
{	
	ros::init(argc, argv, "simulator_light_node");
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("simulator_light",get_intensities);	
	ros::spin();

	return 0;
}