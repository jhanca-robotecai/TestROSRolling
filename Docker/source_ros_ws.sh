#!/bin/bash
# Source the ROS 2 workspace overlay.
# If the workspace has not been built yet, build it first.

ROS_WS=/data/workspace/ros_ws

if [ ! -d "${ROS_WS}/install" ]; then
    echo "ros_ws not built — building now..."
    source /usr/local/bin/build_ros_ws.sh
else
    source /opt/ros/${ROS_DISTRO}/setup.bash
    source ${ROS_WS}/install/setup.bash
    echo "=== ros_ws overlay sourced ==="
fi
