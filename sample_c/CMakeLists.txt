cmake_minimum_required(VERSION 2.8.3)
project(sample_c)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  trajectory_msgs
  message_generation
  geometry_msgs
)


add_message_files(
  FILES
  sample_message.msg
)

generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime roscpp std_msgs message_runtime ${MSG_DEPS}
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(seed_command_publisher src/sample_c_publisher14.cpp)
add_executable(seed_command_publisher2 src/sample_c_publisher15.cpp)
add_executable(seed_command_publisher3 src/sample_c_publisher16.cpp)
target_link_libraries(seed_command_publisher ${catkin_LIBRARIES})
target_link_libraries(seed_command_publisher2 ${catkin_LIBRARIES})
target_link_libraries(seed_command_publisher3 ${catkin_LIBRARIES})

