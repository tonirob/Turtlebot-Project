cmake_minimum_required(VERSION 2.8.3)
project(decision_maker)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  std_msgs
  poi_database
  move_base_msgs
  actionlib
)


## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )


## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   geometry_msgs
#   std_msgs
# )

 SET(SRCS
        src/decision_maker_main.cpp
        src/decision_maker.cpp)

catkin_package(
  CATKIN_DEPENDS geometry_msgs roscpp std_msgs message_runtime poi_database  move_base_msgs actionlib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(decision ${SRCS})


add_dependencies(decision database_gencpp)

target_link_libraries(decision
   ${catkin_LIBRARIES}
 )