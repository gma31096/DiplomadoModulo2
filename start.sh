#!/bin/bash
#Script to start the ros simulations 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscore" 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash && roscd simulator/src/gui/ && python simulator_node.py" 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash  && rosrun simulator light_node" 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash  && rosrun simulator laser_node" 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash  && rosrun simulator base_node" 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash  && rosrun simulator simulator_pub" 
xterm -hold -e ". ~/catkin_ws/devel/setup.bash  && rosrun simulator motion_planner_node" 
