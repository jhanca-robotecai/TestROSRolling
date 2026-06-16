#!/bin/bash
# Build the TestROSRolling O3DE project.
# Builds into build/${ROS_DISTRO} so multiple distro builds coexist without conflict.
set -e

source /opt/ros/${ROS_DISTRO}/setup.bash

PROJECT_PATH=/data/workspace/Project
BUILD_DIR=build/${ROS_DISTRO}

cd $PROJECT_PATH

# Generate a per-distro user preset that inherits 'development' but uses build/${ROS_DISTRO}
cat > CMakeUserPresets.json << EOF
{
    "version": 3,
    "configurePresets": [
        {
            "name": "development-${ROS_DISTRO}",
            "inherits": "development",
            "binaryDir": "\${sourceDir}/${BUILD_DIR}"
        }
    ],
    "buildPresets": [
        {
            "name": "build-all-${ROS_DISTRO}",
            "configurePreset": "development-${ROS_DISTRO}",
            "targets": ["all"]
        }
    ]
}
EOF

echo "=== Configuring (build dir: ${BUILD_DIR}) ==="
cmake --preset development-${ROS_DISTRO}

echo "=== Building (build dir: ${BUILD_DIR}) ==="
cmake --build --preset build-all-${ROS_DISTRO}

echo "=== Build complete ==="
