typedef struct parameters_
{
	float robot_x;
	float robot_y;
	float robot_theta;
	float robot_radio;
	float robot_max_advance;
	float robot_turn_angle;
	int   laser_num_sensors;
	float laser_origin;
	float laser_range;
	float laser_value;
	char  world_name[20];
	bool    noise;
	bool    run;
	float light_x;
	float light_y;
	int behavior;
} parameters;



