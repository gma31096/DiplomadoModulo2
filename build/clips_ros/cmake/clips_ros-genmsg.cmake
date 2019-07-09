# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "clips_ros: 6 messages, 4 services")

set(MSG_I_FLAGS "-Iclips_ros:/home/gerardo/catkin_ws/src/clips_ros/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(clips_ros_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/RecognizedSpeech.msg" NAME_WE)
add_custom_target(_clips_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clips_ros" "/home/gerardo/catkin_ws/src/clips_ros/msg/RecognizedSpeech.msg" ""
)

get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/clearKDB.srv" NAME_WE)
add_custom_target(_clips_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clips_ros" "/home/gerardo/catkin_ws/src/clips_ros/srv/clearKDB.srv" ""
)

get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/StrQueryKDB.srv" NAME_WE)
add_custom_target(_clips_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clips_ros" "/home/gerardo/catkin_ws/src/clips_ros/srv/StrQueryKDB.srv" ""
)

get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/RepeatedSentence.msg" NAME_WE)
add_custom_target(_clips_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clips_ros" "/home/gerardo/catkin_ws/src/clips_ros/msg/RepeatedSentence.msg" ""
)

get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdSend.msg" NAME_WE)
add_custom_target(_clips_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clips_ros" "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdSend.msg" ""
)

get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg" NAME_WE)
add_custom_target(_clips_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clips_ros" "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg" ""
)

get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/planning_cmd.srv" NAME_WE)
add_custom_target(_clips_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clips_ros" "/home/gerardo/catkin_ws/src/clips_ros/srv/planning_cmd.srv" ""
)

get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdClips.msg" NAME_WE)
add_custom_target(_clips_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clips_ros" "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdClips.msg" ""
)

get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCFR.msg" NAME_WE)
add_custom_target(_clips_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clips_ros" "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCFR.msg" "clips_ros/CFRParams"
)

get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/InitKDB.srv" NAME_WE)
add_custom_target(_clips_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "clips_ros" "/home/gerardo/catkin_ws/src/clips_ros/srv/InitKDB.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/RecognizedSpeech.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
)
_generate_msg_cpp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/RepeatedSentence.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
)
_generate_msg_cpp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdSend.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
)
_generate_msg_cpp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
)
_generate_msg_cpp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdClips.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
)
_generate_msg_cpp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCFR.msg"
  "${MSG_I_FLAGS}"
  "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
)

### Generating Services
_generate_srv_cpp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/planning_cmd.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
)
_generate_srv_cpp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/clearKDB.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
)
_generate_srv_cpp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/StrQueryKDB.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
)
_generate_srv_cpp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/InitKDB.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
)

### Generating Module File
_generate_module_cpp(clips_ros
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(clips_ros_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(clips_ros_generate_messages clips_ros_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/RecognizedSpeech.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_cpp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/clearKDB.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_cpp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/StrQueryKDB.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_cpp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/RepeatedSentence.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_cpp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdSend.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_cpp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_cpp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/planning_cmd.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_cpp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdClips.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_cpp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCFR.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_cpp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/InitKDB.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_cpp _clips_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(clips_ros_gencpp)
add_dependencies(clips_ros_gencpp clips_ros_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS clips_ros_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/RecognizedSpeech.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
)
_generate_msg_lisp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/RepeatedSentence.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
)
_generate_msg_lisp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdSend.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
)
_generate_msg_lisp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
)
_generate_msg_lisp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdClips.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
)
_generate_msg_lisp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCFR.msg"
  "${MSG_I_FLAGS}"
  "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
)

### Generating Services
_generate_srv_lisp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/planning_cmd.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
)
_generate_srv_lisp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/clearKDB.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
)
_generate_srv_lisp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/StrQueryKDB.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
)
_generate_srv_lisp(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/InitKDB.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
)

### Generating Module File
_generate_module_lisp(clips_ros
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(clips_ros_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(clips_ros_generate_messages clips_ros_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/RecognizedSpeech.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_lisp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/clearKDB.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_lisp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/StrQueryKDB.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_lisp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/RepeatedSentence.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_lisp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdSend.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_lisp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_lisp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/planning_cmd.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_lisp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdClips.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_lisp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCFR.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_lisp _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/InitKDB.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_lisp _clips_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(clips_ros_genlisp)
add_dependencies(clips_ros_genlisp clips_ros_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS clips_ros_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/RecognizedSpeech.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
)
_generate_msg_py(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/RepeatedSentence.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
)
_generate_msg_py(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdSend.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
)
_generate_msg_py(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
)
_generate_msg_py(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdClips.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
)
_generate_msg_py(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCFR.msg"
  "${MSG_I_FLAGS}"
  "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
)

### Generating Services
_generate_srv_py(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/planning_cmd.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
)
_generate_srv_py(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/clearKDB.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
)
_generate_srv_py(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/StrQueryKDB.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
)
_generate_srv_py(clips_ros
  "/home/gerardo/catkin_ws/src/clips_ros/srv/InitKDB.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
)

### Generating Module File
_generate_module_py(clips_ros
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(clips_ros_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(clips_ros_generate_messages clips_ros_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/RecognizedSpeech.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_py _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/clearKDB.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_py _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/StrQueryKDB.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_py _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/RepeatedSentence.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_py _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdSend.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_py _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/CFRParams.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_py _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/planning_cmd.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_py _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCmdClips.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_py _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/msg/PlanningCFR.msg" NAME_WE)
add_dependencies(clips_ros_generate_messages_py _clips_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/gerardo/catkin_ws/src/clips_ros/srv/InitKDB.srv" NAME_WE)
add_dependencies(clips_ros_generate_messages_py _clips_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(clips_ros_genpy)
add_dependencies(clips_ros_genpy clips_ros_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS clips_ros_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/clips_ros
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(clips_ros_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(clips_ros_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/clips_ros
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(clips_ros_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(clips_ros_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/clips_ros
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(clips_ros_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(clips_ros_generate_messages_py geometry_msgs_generate_messages_py)
endif()
