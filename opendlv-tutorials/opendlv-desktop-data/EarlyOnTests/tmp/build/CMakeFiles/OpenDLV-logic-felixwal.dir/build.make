# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/opendlv/data/opendlv-logic-felixwal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/opendlv/data/opendlv-logic-felixwal/build

# Include any dependencies generated for this target.
include CMakeFiles/OpenDLV-logic-felixwal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenDLV-logic-felixwal.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenDLV-logic-felixwal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenDLV-logic-felixwal.dir/flags.make

opendlv-message-standard.hpp: ../opendlv-message-standard-1.0.odvd
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/opendlv/data/opendlv-logic-felixwal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating opendlv-message-standard.hpp"
	cluon-msc --cpp --out=/home/opendlv/data/opendlv-logic-felixwal/build/opendlv-message-standard.hpp /home/opendlv/data/opendlv-logic-felixwal/opendlv-message-standard-1.0.odvd

CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.o: CMakeFiles/OpenDLV-logic-felixwal.dir/flags.make
CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.o: ../main.cpp
CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.o: CMakeFiles/OpenDLV-logic-felixwal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/opendlv/data/opendlv-logic-felixwal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.o -MF CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.o.d -o CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.o -c /home/opendlv/data/opendlv-logic-felixwal/main.cpp

CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/opendlv/data/opendlv-logic-felixwal/main.cpp > CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.i

CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/opendlv/data/opendlv-logic-felixwal/main.cpp -o CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.s

# Object files for target OpenDLV-logic-felixwal
OpenDLV__logic__felixwal_OBJECTS = \
"CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.o"

# External object files for target OpenDLV-logic-felixwal
OpenDLV__logic__felixwal_EXTERNAL_OBJECTS =

OpenDLV-logic-felixwal: CMakeFiles/OpenDLV-logic-felixwal.dir/main.cpp.o
OpenDLV-logic-felixwal: CMakeFiles/OpenDLV-logic-felixwal.dir/build.make
OpenDLV-logic-felixwal: CMakeFiles/OpenDLV-logic-felixwal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/opendlv/data/opendlv-logic-felixwal/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OpenDLV-logic-felixwal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenDLV-logic-felixwal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenDLV-logic-felixwal.dir/build: OpenDLV-logic-felixwal
.PHONY : CMakeFiles/OpenDLV-logic-felixwal.dir/build

CMakeFiles/OpenDLV-logic-felixwal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenDLV-logic-felixwal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenDLV-logic-felixwal.dir/clean

CMakeFiles/OpenDLV-logic-felixwal.dir/depend: opendlv-message-standard.hpp
	cd /home/opendlv/data/opendlv-logic-felixwal/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/opendlv/data/opendlv-logic-felixwal /home/opendlv/data/opendlv-logic-felixwal /home/opendlv/data/opendlv-logic-felixwal/build /home/opendlv/data/opendlv-logic-felixwal/build /home/opendlv/data/opendlv-logic-felixwal/build/CMakeFiles/OpenDLV-logic-felixwal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenDLV-logic-felixwal.dir/depend

