#!/usr/bin/env python
from MobileRobotSimulator import *
from simulator.srv import *
import time
import rospy

gui=MobileRobotSimulator()


def handle_get_parameters(req):
	
	resp = simulator_parametersResponse()
	parameters = gui.get_parameters()
	resp.robot_x = parameters[0]
	resp.robot_y = parameters[1]
	resp.robot_theta = parameters[2]
	resp.robot_radio = parameters[3]
	resp.robot_max_advance = parameters[4]
	resp.robot_turn_angle = parameters[5]
	resp.laser_num_sensors = parameters[6]
	resp.laser_origin = parameters[7]
	resp.laser_range = parameters[8]
	resp.laser_value = parameters[9]
	resp.world_name = parameters[10]
	resp.noise = parameters[11]
	resp.light_x = parameters[12]
	resp.light_y = parameters[13]
	resp.run = parameters[14]
	resp.behavior = parameters[15]

	return resp


def handle_robot_step(req):

	resp = simulator_robot_stepResponse()
	gui.handle_service(req.theta,req.distance)
	parameters = gui.get_parameters()
	resp.robot_x = parameters[0]
	resp.robot_y = parameters[1]
	resp.theta = parameters[2]
	print ("DONE")

	return resp

def handle_print_graph(req):

	resp = simulator_algorithm_resultResponse()
	gui.handle_print_graph(req.nodes_algorithm)
	resp.success=1;
	print ("DONE3")
	return resp

def handle_robot_laser_values(req):

	resp = simulator_robot_laser_valuesResponse()
	resp.success=1;
	gui.sensors_value=req.sensors;
	
	print ("DONE2")

	return resp

def ros():

	rospy.init_node('simulator_gui_node')
	s = rospy.Service('simulator_robot_step', simulator_robot_step, handle_robot_step)
	s = rospy.Service('simulator_get_parameters', simulator_parameters, handle_get_parameters)
	s = rospy.Service('simulator_robot_laser_values', simulator_robot_laser_values, handle_robot_laser_values)
	s = rospy.Service('simulator_print_graph', simulator_algorithm_result, handle_print_graph)
	
	rospy.spin()

if __name__ == "__main__":
    ros()


