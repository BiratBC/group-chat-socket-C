# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Define the project name and version
project(SocketC VERSION 1.0)

# Set the C standard to 99
set(CMAKE_C_STANDARD 99)

# Add the subdirectories for client and socketutil
add_subdirectory(socketutil)  # Add socketutil folder as a subdirectory
add_subdirectory(client)      # Add client folder as a subdirectory
add_subdirectory(server)

# Optionally, you can add other configurations or targets here