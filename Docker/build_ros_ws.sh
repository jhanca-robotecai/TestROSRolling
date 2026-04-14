#!/bin/bash
# Build the ROS 2 workspace and source the install overlay.
set -e

source /opt/ros/${ROS_DISTRO}/setup.bash

cd /data/workspace/ros_ws

echo "=== Building ROS 2 workspace ==="
colcon build --symlink-install

echo "=== Sourcing install overlay ==="
source install/setup.bash

echo "=== ros_ws build complete ==="
