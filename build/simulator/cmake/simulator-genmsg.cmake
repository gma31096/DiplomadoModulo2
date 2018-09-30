# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "simulator: 1 messages, 5 services")

set(MSG_I_FLAGS "-Isimulator:/home/diego/catkin_ws/src/simulator/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(simulator_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_laser.srv" NAME_WE)
add_custom_target(_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simulator" "/home/diego/catkin_ws/src/simulator/srv/simulator_laser.srv" ""
)

get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_laser_values.srv" NAME_WE)
add_custom_target(_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simulator" "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_laser_values.srv" ""
)

get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_base.srv" NAME_WE)
add_custom_target(_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simulator" "/home/diego/catkin_ws/src/simulator/srv/simulator_base.srv" ""
)

get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_parameters.srv" NAME_WE)
add_custom_target(_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simulator" "/home/diego/catkin_ws/src/simulator/srv/simulator_parameters.srv" ""
)

get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/msg/Parameters.msg" NAME_WE)
add_custom_target(_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simulator" "/home/diego/catkin_ws/src/simulator/msg/Parameters.msg" ""
)

get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_step.srv" NAME_WE)
add_custom_target(_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simulator" "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_step.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(simulator
  "/home/diego/catkin_ws/src/simulator/msg/Parameters.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simulator
)

### Generating Services
_generate_srv_cpp(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_laser_values.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simulator
)
_generate_srv_cpp(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_laser.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simulator
)
_generate_srv_cpp(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_step.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simulator
)
_generate_srv_cpp(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_parameters.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simulator
)
_generate_srv_cpp(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_base.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simulator
)

### Generating Module File
_generate_module_cpp(simulator
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simulator
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(simulator_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(simulator_generate_messages simulator_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_laser.srv" NAME_WE)
add_dependencies(simulator_generate_messages_cpp _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_laser_values.srv" NAME_WE)
add_dependencies(simulator_generate_messages_cpp _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_base.srv" NAME_WE)
add_dependencies(simulator_generate_messages_cpp _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_parameters.srv" NAME_WE)
add_dependencies(simulator_generate_messages_cpp _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/msg/Parameters.msg" NAME_WE)
add_dependencies(simulator_generate_messages_cpp _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_step.srv" NAME_WE)
add_dependencies(simulator_generate_messages_cpp _simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simulator_gencpp)
add_dependencies(simulator_gencpp simulator_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simulator_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(simulator
  "/home/diego/catkin_ws/src/simulator/msg/Parameters.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simulator
)

### Generating Services
_generate_srv_lisp(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_laser_values.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simulator
)
_generate_srv_lisp(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_laser.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simulator
)
_generate_srv_lisp(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_step.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simulator
)
_generate_srv_lisp(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_parameters.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simulator
)
_generate_srv_lisp(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_base.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simulator
)

### Generating Module File
_generate_module_lisp(simulator
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simulator
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(simulator_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(simulator_generate_messages simulator_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_laser.srv" NAME_WE)
add_dependencies(simulator_generate_messages_lisp _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_laser_values.srv" NAME_WE)
add_dependencies(simulator_generate_messages_lisp _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_base.srv" NAME_WE)
add_dependencies(simulator_generate_messages_lisp _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_parameters.srv" NAME_WE)
add_dependencies(simulator_generate_messages_lisp _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/msg/Parameters.msg" NAME_WE)
add_dependencies(simulator_generate_messages_lisp _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_step.srv" NAME_WE)
add_dependencies(simulator_generate_messages_lisp _simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simulator_genlisp)
add_dependencies(simulator_genlisp simulator_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simulator_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(simulator
  "/home/diego/catkin_ws/src/simulator/msg/Parameters.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simulator
)

### Generating Services
_generate_srv_py(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_laser_values.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simulator
)
_generate_srv_py(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_laser.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simulator
)
_generate_srv_py(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_step.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simulator
)
_generate_srv_py(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_parameters.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simulator
)
_generate_srv_py(simulator
  "/home/diego/catkin_ws/src/simulator/srv/simulator_base.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simulator
)

### Generating Module File
_generate_module_py(simulator
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simulator
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(simulator_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(simulator_generate_messages simulator_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_laser.srv" NAME_WE)
add_dependencies(simulator_generate_messages_py _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_laser_values.srv" NAME_WE)
add_dependencies(simulator_generate_messages_py _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_base.srv" NAME_WE)
add_dependencies(simulator_generate_messages_py _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_parameters.srv" NAME_WE)
add_dependencies(simulator_generate_messages_py _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/msg/Parameters.msg" NAME_WE)
add_dependencies(simulator_generate_messages_py _simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/diego/catkin_ws/src/simulator/srv/simulator_robot_step.srv" NAME_WE)
add_dependencies(simulator_generate_messages_py _simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simulator_genpy)
add_dependencies(simulator_genpy simulator_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simulator_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simulator
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(simulator_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simulator
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(simulator_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simulator)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simulator\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simulator
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(simulator_generate_messages_py std_msgs_generate_messages_py)
endif()
