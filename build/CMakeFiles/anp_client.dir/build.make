# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daan1809/ANPProject/anp-2024-skeleton-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daan1809/ANPProject/anp-2024-skeleton-main/build

# Include any dependencies generated for this target.
include CMakeFiles/anp_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/anp_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/anp_client.dir/flags.make

CMakeFiles/anp_client.dir/server-client/tcp_client.c.o: CMakeFiles/anp_client.dir/flags.make
CMakeFiles/anp_client.dir/server-client/tcp_client.c.o: ../server-client/tcp_client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daan1809/ANPProject/anp-2024-skeleton-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/anp_client.dir/server-client/tcp_client.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/anp_client.dir/server-client/tcp_client.c.o   -c /home/daan1809/ANPProject/anp-2024-skeleton-main/server-client/tcp_client.c

CMakeFiles/anp_client.dir/server-client/tcp_client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/anp_client.dir/server-client/tcp_client.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daan1809/ANPProject/anp-2024-skeleton-main/server-client/tcp_client.c > CMakeFiles/anp_client.dir/server-client/tcp_client.c.i

CMakeFiles/anp_client.dir/server-client/tcp_client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/anp_client.dir/server-client/tcp_client.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daan1809/ANPProject/anp-2024-skeleton-main/server-client/tcp_client.c -o CMakeFiles/anp_client.dir/server-client/tcp_client.c.s

CMakeFiles/anp_client.dir/server-client/common.c.o: CMakeFiles/anp_client.dir/flags.make
CMakeFiles/anp_client.dir/server-client/common.c.o: ../server-client/common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daan1809/ANPProject/anp-2024-skeleton-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/anp_client.dir/server-client/common.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/anp_client.dir/server-client/common.c.o   -c /home/daan1809/ANPProject/anp-2024-skeleton-main/server-client/common.c

CMakeFiles/anp_client.dir/server-client/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/anp_client.dir/server-client/common.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daan1809/ANPProject/anp-2024-skeleton-main/server-client/common.c > CMakeFiles/anp_client.dir/server-client/common.c.i

CMakeFiles/anp_client.dir/server-client/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/anp_client.dir/server-client/common.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daan1809/ANPProject/anp-2024-skeleton-main/server-client/common.c -o CMakeFiles/anp_client.dir/server-client/common.c.s

# Object files for target anp_client
anp_client_OBJECTS = \
"CMakeFiles/anp_client.dir/server-client/tcp_client.c.o" \
"CMakeFiles/anp_client.dir/server-client/common.c.o"

# External object files for target anp_client
anp_client_EXTERNAL_OBJECTS =

anp_client: CMakeFiles/anp_client.dir/server-client/tcp_client.c.o
anp_client: CMakeFiles/anp_client.dir/server-client/common.c.o
anp_client: CMakeFiles/anp_client.dir/build.make
anp_client: CMakeFiles/anp_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daan1809/ANPProject/anp-2024-skeleton-main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable anp_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/anp_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/anp_client.dir/build: anp_client

.PHONY : CMakeFiles/anp_client.dir/build

CMakeFiles/anp_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/anp_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/anp_client.dir/clean

CMakeFiles/anp_client.dir/depend:
	cd /home/daan1809/ANPProject/anp-2024-skeleton-main/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daan1809/ANPProject/anp-2024-skeleton-main /home/daan1809/ANPProject/anp-2024-skeleton-main /home/daan1809/ANPProject/anp-2024-skeleton-main/build /home/daan1809/ANPProject/anp-2024-skeleton-main/build /home/daan1809/ANPProject/anp-2024-skeleton-main/build/CMakeFiles/anp_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/anp_client.dir/depend

