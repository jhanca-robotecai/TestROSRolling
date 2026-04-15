#!/bin/bash
source /opt/ros/${ROS_DISTRO}/setup.bash

# Quickfix for tests
export LD_LIBRARY_PATH=/data/workspace/Project/build/dev/bin/profile:${LD_LIBRARY_PATH}

exec /bin/bash
