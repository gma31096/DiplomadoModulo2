#!/usr/bin/env python
from MobileRobotSimulator import *
from simulator.msg import Parameters
from simulator.srv import *
import time
import rospy


gui=MobileRobotSimulator()

def handle_service(req):
	
	gui.handle_service(req.theta,req.distance)
	print ("DONE")
	return robot_stepResponse(1)

def ros():

	rospy.init_node('Gui_simulator', anonymous=True)
	pub = rospy.Publisher('/parameters', Parameters, queue_size=10)
	s = rospy.Service('robot_step', robot_step, handle_service)

	rate = rospy.Rate(10) # 10hz
	msg = Parameters()
	while not gui.stopped:
		parameters= gui.get_parameters()
		msg.robot_x = parameters[0]
		msg.robot_y = parameters[1]
		msg.robot_theta = parameters[2]
		msg.robot_radio = parameters[3]
		msg.robot_max_advance = parameters[4]
		msg.robot_turn_angle = parameters[5]
		msg.laser_num_sensors = parameters[6]
		msg.laser_origin = parameters[7]
		msg.laser_range = parameters[8]
		msg.laser_value = parameters[9]
		msg.world_name = parameters[10]
		msg.noise = parameters[11]
		pub.publish(msg)

		for  item in parameters:
			if item ==' ':
				parameters[parameters.index(item)]=0
		#parameters[:] = [x if x != '' else 0 for x in parameters ]

		rate.sleep()

ros()

#if __name__ == "__main__":
#	rospy.init_node('parameters', anonymous=True)
#	s = rospy.Service('move_test', move_test, handle_service)
#	time.sleep(5)
#	while 1:
#
#		gui.move_robot(3.14,200)
#		time.sleep(1)
#
#
#	rospy.spin()
    #ros()
    #add_two_ints_server()