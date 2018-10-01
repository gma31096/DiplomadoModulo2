
void sm_light_follower(float *light_values,movement *movements)
{
	int sensor = 0;
	for(int i = 1; i < 8; i++)
	{
		if( light_values[i] < light_values[sensor])
			sensor = i;
	}
	if(sensor>4)
		sensor=-(8 - sensor);	


	movements->twist = sensor * 3.1315 / 4;
	movements->advance = .1;


}