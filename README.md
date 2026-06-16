# TestROSRolling

This project provides a containerized test environment for running [O3DE](https://o3de.org/) simulation with ROS 2 (using the [ROS 2 Gem](https://github.com/o3de/o3de-extras) from o3de-extras) inside Docker. It supports multiple ROS 2 distros (default: **lyrical**).

**All persistent data lives on the host**, not inside the container. The following directories are mounted as Docker volumes:

| Host path  | Container path            | Contents                                                     |
| ---------- | ------------------------- | ------------------------------------------------------------ |
| `Project/` | `/data/workspace/Project` | O3DE project source and build output (`build/<ROS_DISTRO>/`) |
| `ros_ws/`  | `/data/workspace/ros_ws`  | ROS 2 workspace source and colcon build output               |
| `o3de/`    | `/data/workspace/o3de`    | o3de-extras submodule (ROS 2 Gem)                            |

This means project edits and build artifacts persist across container restarts and are directly accessible from the host. O3DE project builds are isolated per distro under `Project/build/<ROS_DISTRO>/`. The ROS 2 workspace (`ros_ws`) is shared — `build_ros_ws.sh` always cleans and rebuilds it for the active distro.

The ROS 2 workspace (`ros_ws/`) contains the [`simulation_interfaces`](https://github.com/ros-simulation/simulation_interfaces) package as a git submodule. It is **built from source** inside the container by `build_ros_ws.sh` — no pre-built binary is used. [o3de-extras](https://github.com/o3de/o3de-extras) repository is a submodule as well, as it is meant for development.

## Prerequisites

- Docker (with NVIDIA Container Toolkit for GPU-accelerated O3DE rendering)
- An X11 display server (for O3DE editor/launcher)
- Git LFS (`git lfs install`)
- O3DE `.deb` package placed at `tmp/o3de_latest.deb` in the repository root (see below)

### Cloning the repository

Clone with submodules in one step:

```bash
git clone --recurse-submodules <repo-url>
git lfs pull
```

If you already cloned without submodules:

```bash
git submodule update --init --recursive
git lfs pull
```

### Downloading the O3DE package

The Docker image installs O3DE from a local `.deb` file. Download it before building (this example show 2605 stabilization):

```bash
mkdir -p tmp
curl -L https://o3debinaries.org/stabilization-26050/Latest/Linux/o3de_latest.deb -o tmp/o3de_latest.deb
```

## Quick Start

```bash
# Build the Docker image (default: ROS 2 lyrical)
docker compose build

# To use a different ROS 2 distro:
ROS_DISTRO=jazzy docker compose build

# Run an interactive container
docker compose run --rm simulation
```

Inside the container:

```bash
# Optional: build the ROS 2 workspace (cleans and rebuilds from scratch)
# Use dot-source so the install overlay stays active in the current shell
. build_ros_ws.sh

# Optional: source the ROS 2 workspace (builds automatically if not yet built)
. source_ros_ws.sh

# Build the O3DE project (into build/<ROS_DISTRO>/)
build_project.sh
```

### Useful commands

```bash
# Build and run container for a specific ROS 2 distro
ROS_DISTRO=lyrical docker compose build
ROS_DISTRO=lyrical docker compose run --rm simulation

ROS_DISTRO=jazzy docker compose build
ROS_DISTRO=jazzy docker compose run --rm simulation

# Build and source the ROS 2 workspace (always cleans first)
. /usr/local/bin/build_ros_ws.sh

# Source the ROS 2 workspace (auto-builds if not present)
. /usr/local/bin/source_ros_ws.sh

# Build the O3DE project (output: Project/build/<ROS_DISTRO>/)
build_project.sh

# Register Gems (needed for tests) and run tests
/opt/O3DE/26.05/scripts/o3de.sh register --all-gems-path /data/workspace/o3de/o3de-extras/Gems/
ctest --test-dir /data/workspace/Project/build/${ROS_DISTRO}/ -I 1,8
```
