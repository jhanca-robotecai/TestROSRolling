#!/bin/bash
# Build the TestROSRolling O3DE project using the development->build-all CMake preset chain.
set -e

source /opt/ros/rolling/setup.bash

PROJECT_PATH=/data/workspace/Project

cd $PROJECT_PATH

echo "=== Configuring (development preset) ==="
cmake --preset development

echo "=== Building (build-all preset) ==="
cmake --build --preset build-all

echo "=== Build complete ==="
