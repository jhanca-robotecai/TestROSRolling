# TestROSRolling

A containerized test environment for running [O3DE](https://o3de.org/) simulation with [ROS 2 Rolling](https://docs.ros.org/en/rolling/) inside Docker.

## Purpose

This project provides a reproducible Docker-based setup to develop and validate ROS 2 Rolling integration with O3DE, using the [ROS 2 Gem](https://github.com/o3de/o3de-extras) from o3de-extras.

## Prerequisites

- Docker (with NVIDIA Container Toolkit for GPU-accelerated O3DE rendering)
- An X11 display server (for O3DE editor/launcher)
- O3DE `.deb` package placed at `tmp/o3de_latest.deb` in the repository root (see below)

### Downloading the O3DE package

The Docker image installs O3DE from a local `.deb` file. Download it before building (this example show 2605 stabilization):

```bash
mkdir -p tmp
curl -L https://o3debinaries.org/stabilization-26050/Latest/Linux/o3de_latest.deb -o tmp/o3de_latest.deb
```

## Quick Start

```bash
# Build the Docker image (default: ROS 2 Rolling)
docker compose build

# To use a different ROS 2 distro (humble, jazzy):
ROS_DISTRO=jazzy docker compose build

# Run an interactive container
docker compose run --rm simulation
```

Inside the container:

```bash
# Source ROS 2 Rolling
source /opt/ros/rolling/setup.bash

# Optional: build the ROS 2 workspace when testing SimulationInterfaces
cd /workspace/ros_ws
colcon build --symlink-install
source install/setup.bash

# Build the simulation
build_project.sh
```
