# CMake generated Testfile for 
# Source directory: /home/luis/Turtlebot-Project/src/m-explore/map_merge
# Build directory: /home/luis/Turtlebot-Project/build/m-explore/map_merge
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_multirobot_map_merge_gtest_test_merging_pipeline "/home/luis/Turtlebot-Project/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/luis/Turtlebot-Project/build/test_results/multirobot_map_merge/gtest-test_merging_pipeline.xml" "--return-code" "/home/luis/Turtlebot-Project/devel/lib/multirobot_map_merge/test_merging_pipeline --gtest_output=xml:/home/luis/Turtlebot-Project/build/test_results/multirobot_map_merge/gtest-test_merging_pipeline.xml")
add_test(_ctest_multirobot_map_merge_roslaunch-check_launch_map_merge.launch "/home/luis/Turtlebot-Project/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/luis/Turtlebot-Project/build/test_results/multirobot_map_merge/roslaunch-check_launch_map_merge.launch.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/luis/Turtlebot-Project/build/test_results/multirobot_map_merge" "/opt/ros/melodic/share/roslaunch/cmake/../scripts/roslaunch-check -o \"/home/luis/Turtlebot-Project/build/test_results/multirobot_map_merge/roslaunch-check_launch_map_merge.launch.xml\" \"/home/luis/Turtlebot-Project/src/m-explore/map_merge/launch/map_merge.launch\" ")
add_test(_ctest_multirobot_map_merge_roslaunch-check_launch_experiments "/home/luis/Turtlebot-Project/build/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/luis/Turtlebot-Project/build/test_results/multirobot_map_merge/roslaunch-check_launch_experiments.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/luis/Turtlebot-Project/build/test_results/multirobot_map_merge" "/opt/ros/melodic/share/roslaunch/cmake/../scripts/roslaunch-check -o \"/home/luis/Turtlebot-Project/build/test_results/multirobot_map_merge/roslaunch-check_launch_experiments.xml\" \"/home/luis/Turtlebot-Project/src/m-explore/map_merge/launch/experiments\" ")
