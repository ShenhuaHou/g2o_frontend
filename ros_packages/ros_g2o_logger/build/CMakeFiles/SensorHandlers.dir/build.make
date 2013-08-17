# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/build

# Include any dependencies generated for this target.
include CMakeFiles/SensorHandlers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SensorHandlers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SensorHandlers.dir/flags.make

CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: CMakeFiles/SensorHandlers.dir/flags.make
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: ../src/SensorHandlerRGBDCamera.cpp
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: ../manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/geometry_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/sensor_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/roslang/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/roscpp/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/stacks/vision_opencv/opencv2/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/stacks/vision_opencv/cv_bridge/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/message_filters/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/std_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/pcl/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/stacks/bullet/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/rosconsole/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/stacks/geometry/angles/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/rospy/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/rostest/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/share/roswtf/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/stacks/geometry/tf/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/stacks/geometry/tf/msg_gen/generated
CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o: /opt/ros/fuerte/stacks/geometry/tf/srv_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o -c /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerRGBDCamera.cpp

CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerRGBDCamera.cpp > CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.i

CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerRGBDCamera.cpp -o CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.s

CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o.requires:
.PHONY : CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o.requires

CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o.provides: CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o.requires
	$(MAKE) -f CMakeFiles/SensorHandlers.dir/build.make CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o.provides.build
.PHONY : CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o.provides

CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o.provides.build: CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o

CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: CMakeFiles/SensorHandlers.dir/flags.make
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: ../src/SensorHandlerLaserRobot.cpp
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: ../manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/geometry_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/sensor_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/roslang/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/roscpp/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/stacks/vision_opencv/opencv2/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/stacks/vision_opencv/cv_bridge/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/message_filters/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/std_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/pcl/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/stacks/bullet/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/rosconsole/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/stacks/geometry/angles/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/rospy/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/rostest/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/share/roswtf/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/stacks/geometry/tf/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/stacks/geometry/tf/msg_gen/generated
CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o: /opt/ros/fuerte/stacks/geometry/tf/srv_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o -c /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerLaserRobot.cpp

CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerLaserRobot.cpp > CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.i

CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerLaserRobot.cpp -o CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.s

CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o.requires:
.PHONY : CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o.requires

CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o.provides: CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o.requires
	$(MAKE) -f CMakeFiles/SensorHandlers.dir/build.make CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o.provides.build
.PHONY : CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o.provides

CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o.provides.build: CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o

CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: CMakeFiles/SensorHandlers.dir/flags.make
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: ../src/SensorHandlerOmnicam.cpp
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: ../manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/geometry_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/sensor_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/roslang/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/roscpp/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/stacks/vision_opencv/opencv2/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/stacks/vision_opencv/cv_bridge/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/message_filters/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/std_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/pcl/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/stacks/bullet/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/rosconsole/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/stacks/geometry/angles/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/rospy/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/rostest/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/share/roswtf/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/stacks/geometry/tf/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/stacks/geometry/tf/msg_gen/generated
CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o: /opt/ros/fuerte/stacks/geometry/tf/srv_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o -c /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerOmnicam.cpp

CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerOmnicam.cpp > CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.i

CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerOmnicam.cpp -o CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.s

CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o.requires:
.PHONY : CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o.requires

CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o.provides: CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o.requires
	$(MAKE) -f CMakeFiles/SensorHandlers.dir/build.make CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o.provides.build
.PHONY : CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o.provides

CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o.provides.build: CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o

CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: CMakeFiles/SensorHandlers.dir/flags.make
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: ../src/SensorHandlerImu.cpp
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: ../manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/geometry_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/sensor_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/roslang/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/roscpp/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/stacks/vision_opencv/opencv2/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/stacks/vision_opencv/cv_bridge/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/message_filters/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/std_msgs/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/pcl/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/stacks/bullet/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/rosconsole/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/stacks/geometry/angles/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/rospy/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/rostest/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/share/roswtf/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/stacks/geometry/tf/manifest.xml
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/stacks/geometry/tf/msg_gen/generated
CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o: /opt/ros/fuerte/stacks/geometry/tf/srv_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o -c /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerImu.cpp

CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerImu.cpp > CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.i

CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -DBT_USE_DOUBLE_PRECISION -DBT_EULER_DEFAULT_ZYX -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/src/SensorHandlerImu.cpp -o CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.s

CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o.requires:
.PHONY : CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o.requires

CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o.provides: CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o.requires
	$(MAKE) -f CMakeFiles/SensorHandlers.dir/build.make CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o.provides.build
.PHONY : CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o.provides

CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o.provides.build: CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o

# Object files for target SensorHandlers
SensorHandlers_OBJECTS = \
"CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o" \
"CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o" \
"CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o" \
"CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o"

# External object files for target SensorHandlers
SensorHandlers_EXTERNAL_OBJECTS =

../lib/libSensorHandlers.so: CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o
../lib/libSensorHandlers.so: CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o
../lib/libSensorHandlers.so: CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o
../lib/libSensorHandlers.so: CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o
../lib/libSensorHandlers.so: CMakeFiles/SensorHandlers.dir/build.make
../lib/libSensorHandlers.so: CMakeFiles/SensorHandlers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../lib/libSensorHandlers.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SensorHandlers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SensorHandlers.dir/build: ../lib/libSensorHandlers.so
.PHONY : CMakeFiles/SensorHandlers.dir/build

CMakeFiles/SensorHandlers.dir/requires: CMakeFiles/SensorHandlers.dir/src/SensorHandlerRGBDCamera.o.requires
CMakeFiles/SensorHandlers.dir/requires: CMakeFiles/SensorHandlers.dir/src/SensorHandlerLaserRobot.o.requires
CMakeFiles/SensorHandlers.dir/requires: CMakeFiles/SensorHandlers.dir/src/SensorHandlerOmnicam.o.requires
CMakeFiles/SensorHandlers.dir/requires: CMakeFiles/SensorHandlers.dir/src/SensorHandlerImu.o.requires
.PHONY : CMakeFiles/SensorHandlers.dir/requires

CMakeFiles/SensorHandlers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SensorHandlers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SensorHandlers.dir/clean

CMakeFiles/SensorHandlers.dir/depend:
	cd /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/build /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/build /home/giorgio/src/g2o_frontend/ros_packages/ros_g2o_logger/build/CMakeFiles/SensorHandlers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SensorHandlers.dir/depend
