# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/stuffe/Projects/SchoolProjs/ci/exercise3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stuffe/Projects/SchoolProjs/ci/exercise3/build

# Include any dependencies generated for this target.
include CMakeFiles/greet_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/greet_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/greet_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/greet_test.dir/flags.make

CMakeFiles/greet_test.dir/greet.cpp.o: CMakeFiles/greet_test.dir/flags.make
CMakeFiles/greet_test.dir/greet.cpp.o: /home/stuffe/Projects/SchoolProjs/ci/exercise3/greet.cpp
CMakeFiles/greet_test.dir/greet.cpp.o: CMakeFiles/greet_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/stuffe/Projects/SchoolProjs/ci/exercise3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/greet_test.dir/greet.cpp.o"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/greet_test.dir/greet.cpp.o -MF CMakeFiles/greet_test.dir/greet.cpp.o.d -o CMakeFiles/greet_test.dir/greet.cpp.o -c /home/stuffe/Projects/SchoolProjs/ci/exercise3/greet.cpp

CMakeFiles/greet_test.dir/greet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/greet_test.dir/greet.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stuffe/Projects/SchoolProjs/ci/exercise3/greet.cpp > CMakeFiles/greet_test.dir/greet.cpp.i

CMakeFiles/greet_test.dir/greet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/greet_test.dir/greet.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stuffe/Projects/SchoolProjs/ci/exercise3/greet.cpp -o CMakeFiles/greet_test.dir/greet.cpp.s

CMakeFiles/greet_test.dir/test.cpp.o: CMakeFiles/greet_test.dir/flags.make
CMakeFiles/greet_test.dir/test.cpp.o: /home/stuffe/Projects/SchoolProjs/ci/exercise3/test.cpp
CMakeFiles/greet_test.dir/test.cpp.o: CMakeFiles/greet_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/stuffe/Projects/SchoolProjs/ci/exercise3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/greet_test.dir/test.cpp.o"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/greet_test.dir/test.cpp.o -MF CMakeFiles/greet_test.dir/test.cpp.o.d -o CMakeFiles/greet_test.dir/test.cpp.o -c /home/stuffe/Projects/SchoolProjs/ci/exercise3/test.cpp

CMakeFiles/greet_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/greet_test.dir/test.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stuffe/Projects/SchoolProjs/ci/exercise3/test.cpp > CMakeFiles/greet_test.dir/test.cpp.i

CMakeFiles/greet_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/greet_test.dir/test.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stuffe/Projects/SchoolProjs/ci/exercise3/test.cpp -o CMakeFiles/greet_test.dir/test.cpp.s

# Object files for target greet_test
greet_test_OBJECTS = \
"CMakeFiles/greet_test.dir/greet.cpp.o" \
"CMakeFiles/greet_test.dir/test.cpp.o"

# External object files for target greet_test
greet_test_EXTERNAL_OBJECTS =

greet_test: CMakeFiles/greet_test.dir/greet.cpp.o
greet_test: CMakeFiles/greet_test.dir/test.cpp.o
greet_test: CMakeFiles/greet_test.dir/build.make
greet_test: CMakeFiles/greet_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/stuffe/Projects/SchoolProjs/ci/exercise3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable greet_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/greet_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/greet_test.dir/build: greet_test
.PHONY : CMakeFiles/greet_test.dir/build

CMakeFiles/greet_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/greet_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/greet_test.dir/clean

CMakeFiles/greet_test.dir/depend:
	cd /home/stuffe/Projects/SchoolProjs/ci/exercise3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stuffe/Projects/SchoolProjs/ci/exercise3 /home/stuffe/Projects/SchoolProjs/ci/exercise3 /home/stuffe/Projects/SchoolProjs/ci/exercise3/build /home/stuffe/Projects/SchoolProjs/ci/exercise3/build /home/stuffe/Projects/SchoolProjs/ci/exercise3/build/CMakeFiles/greet_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/greet_test.dir/depend

