#!/bin/bash
source /opt/ros/${ROS_DISTRO}/setup.bash

# Quickfix for tests
export LD_LIBRARY_PATH=/data/workspace/Project/build/${ROS_DISTRO}/bin/profile:${LD_LIBRARY_PATH}

exec /bin/bash
