# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/biratbc/Socket-C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/biratbc/Socket-C/build

# Include any dependencies generated for this target.
include client/CMakeFiles/client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include client/CMakeFiles/client.dir/compiler_depend.make

# Include the progress variables for this target.
include client/CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include client/CMakeFiles/client.dir/flags.make

client/CMakeFiles/client.dir/main.c.o: client/CMakeFiles/client.dir/flags.make
client/CMakeFiles/client.dir/main.c.o: /home/biratbc/Socket-C/client/main.c
client/CMakeFiles/client.dir/main.c.o: client/CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/biratbc/Socket-C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object client/CMakeFiles/client.dir/main.c.o"
	cd /home/biratbc/Socket-C/build/client && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT client/CMakeFiles/client.dir/main.c.o -MF CMakeFiles/client.dir/main.c.o.d -o CMakeFiles/client.dir/main.c.o -c /home/biratbc/Socket-C/client/main.c

client/CMakeFiles/client.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/client.dir/main.c.i"
	cd /home/biratbc/Socket-C/build/client && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/biratbc/Socket-C/client/main.c > CMakeFiles/client.dir/main.c.i

client/CMakeFiles/client.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/client.dir/main.c.s"
	cd /home/biratbc/Socket-C/build/client && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/biratbc/Socket-C/client/main.c -o CMakeFiles/client.dir/main.c.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/main.c.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client/client: client/CMakeFiles/client.dir/main.c.o
client/client: client/CMakeFiles/client.dir/build.make
client/client: socketutil/libsocketutil.a
client/client: client/CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/biratbc/Socket-C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable client"
	cd /home/biratbc/Socket-C/build/client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
client/CMakeFiles/client.dir/build: client/client
.PHONY : client/CMakeFiles/client.dir/build

client/CMakeFiles/client.dir/clean:
	cd /home/biratbc/Socket-C/build/client && $(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : client/CMakeFiles/client.dir/clean

client/CMakeFiles/client.dir/depend:
	cd /home/biratbc/Socket-C/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/biratbc/Socket-C /home/biratbc/Socket-C/client /home/biratbc/Socket-C/build /home/biratbc/Socket-C/build/client /home/biratbc/Socket-C/build/client/CMakeFiles/client.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : client/CMakeFiles/client.dir/depend

