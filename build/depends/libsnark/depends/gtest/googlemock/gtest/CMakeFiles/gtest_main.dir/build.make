# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/hanyun/Desktop/598NB_final/tutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hanyun/Desktop/598NB_final/tutorial/build

# Include any dependencies generated for this target.
include depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/flags.make

depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/flags.make
depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: ../depends/libsnark/depends/gtest/googletest/src/gtest_main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hanyun/Desktop/598NB_final/tutorial/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends/gtest/googlemock/gtest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends/gtest/googletest/src/gtest_main.cc

depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends/gtest/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends/gtest/googletest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends/gtest/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends/gtest/googletest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires:
.PHONY : depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides: depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
	$(MAKE) -f depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/build.make depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build
.PHONY : depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides

depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build: depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

depends/libsnark/depends/gtest/googlemock/gtest/libgtest_main.a: depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
depends/libsnark/depends/gtest/googlemock/gtest/libgtest_main.a: depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/build.make
depends/libsnark/depends/gtest/googlemock/gtest/libgtest_main.a: depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgtest_main.a"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends/gtest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends/gtest/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/build: depends/libsnark/depends/gtest/googlemock/gtest/libgtest_main.a
.PHONY : depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/build

depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/requires: depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
.PHONY : depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/requires

depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/clean:
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends/gtest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/clean

depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/depend:
	cd /home/hanyun/Desktop/598NB_final/tutorial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hanyun/Desktop/598NB_final/tutorial /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends/gtest/googletest /home/hanyun/Desktop/598NB_final/tutorial/build /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends/gtest/googlemock/gtest /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : depends/libsnark/depends/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/depend

