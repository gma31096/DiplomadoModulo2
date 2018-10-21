#!/usr/bin/env python
import rospy
from simulator.msg import Parameters

def callback(data):
    rospy.loginfo("%s is age: %d" % (data.robot_x, data.robot_y))

def listener():
    rospy.init_node('custom_listener', anonymous=True)
    rospy.Subscriber("simulator_parameters_pub", Parameters, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()