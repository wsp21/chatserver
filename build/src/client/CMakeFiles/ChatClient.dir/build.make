# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/wsp/code/Chat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wsp/code/Chat/build

# Include any dependencies generated for this target.
include src/client/CMakeFiles/ChatClient.dir/depend.make

# Include the progress variables for this target.
include src/client/CMakeFiles/ChatClient.dir/progress.make

# Include the compile flags for this target's objects.
include src/client/CMakeFiles/ChatClient.dir/flags.make

src/client/CMakeFiles/ChatClient.dir/main.cpp.o: src/client/CMakeFiles/ChatClient.dir/flags.make
src/client/CMakeFiles/ChatClient.dir/main.cpp.o: ../src/client/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsp/code/Chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/client/CMakeFiles/ChatClient.dir/main.cpp.o"
	cd /home/wsp/code/Chat/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChatClient.dir/main.cpp.o -c /home/wsp/code/Chat/src/client/main.cpp

src/client/CMakeFiles/ChatClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatClient.dir/main.cpp.i"
	cd /home/wsp/code/Chat/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsp/code/Chat/src/client/main.cpp > CMakeFiles/ChatClient.dir/main.cpp.i

src/client/CMakeFiles/ChatClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatClient.dir/main.cpp.s"
	cd /home/wsp/code/Chat/build/src/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsp/code/Chat/src/client/main.cpp -o CMakeFiles/ChatClient.dir/main.cpp.s

# Object files for target ChatClient
ChatClient_OBJECTS = \
"CMakeFiles/ChatClient.dir/main.cpp.o"

# External object files for target ChatClient
ChatClient_EXTERNAL_OBJECTS =

../bin/ChatClient: src/client/CMakeFiles/ChatClient.dir/main.cpp.o
../bin/ChatClient: src/client/CMakeFiles/ChatClient.dir/build.make
../bin/ChatClient: src/client/CMakeFiles/ChatClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wsp/code/Chat/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/ChatClient"
	cd /home/wsp/code/Chat/build/src/client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChatClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/client/CMakeFiles/ChatClient.dir/build: ../bin/ChatClient

.PHONY : src/client/CMakeFiles/ChatClient.dir/build

src/client/CMakeFiles/ChatClient.dir/clean:
	cd /home/wsp/code/Chat/build/src/client && $(CMAKE_COMMAND) -P CMakeFiles/ChatClient.dir/cmake_clean.cmake
.PHONY : src/client/CMakeFiles/ChatClient.dir/clean

src/client/CMakeFiles/ChatClient.dir/depend:
	cd /home/wsp/code/Chat/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wsp/code/Chat /home/wsp/code/Chat/src/client /home/wsp/code/Chat/build /home/wsp/code/Chat/build/src/client /home/wsp/code/Chat/build/src/client/CMakeFiles/ChatClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/client/CMakeFiles/ChatClient.dir/depend

