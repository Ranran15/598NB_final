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
include depends/libsnark/depends/CMakeFiles/zm.dir/depend.make

# Include the progress variables for this target.
include depends/libsnark/depends/CMakeFiles/zm.dir/progress.make

# Include the compile flags for this target's objects.
include depends/libsnark/depends/CMakeFiles/zm.dir/flags.make

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o: depends/libsnark/depends/CMakeFiles/zm.dir/flags.make
depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o: ../depends/libsnark/depends/ate-pairing/src/zm.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hanyun/Desktop/598NB_final/tutorial/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o -c /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends/ate-pairing/src/zm.cpp

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.i"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends/ate-pairing/src/zm.cpp > CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.i

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.s"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends/ate-pairing/src/zm.cpp -o CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.s

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o.requires:
.PHONY : depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o.requires

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o.provides: depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o.requires
	$(MAKE) -f depends/libsnark/depends/CMakeFiles/zm.dir/build.make depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o.provides.build
.PHONY : depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o.provides

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o.provides.build: depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o: depends/libsnark/depends/CMakeFiles/zm.dir/flags.make
depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o: ../depends/libsnark/depends/ate-pairing/src/zm2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hanyun/Desktop/598NB_final/tutorial/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o -c /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends/ate-pairing/src/zm2.cpp

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.i"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends/ate-pairing/src/zm2.cpp > CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.i

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.s"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends/ate-pairing/src/zm2.cpp -o CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.s

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o.requires:
.PHONY : depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o.requires

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o.provides: depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o.requires
	$(MAKE) -f depends/libsnark/depends/CMakeFiles/zm.dir/build.make depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o.provides.build
.PHONY : depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o.provides

depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o.provides.build: depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o

# Object files for target zm
zm_OBJECTS = \
"CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o" \
"CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o"

# External object files for target zm
zm_EXTERNAL_OBJECTS =

depends/libsnark/depends/libzm.a: depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o
depends/libsnark/depends/libzm.a: depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o
depends/libsnark/depends/libzm.a: depends/libsnark/depends/CMakeFiles/zm.dir/build.make
depends/libsnark/depends/libzm.a: depends/libsnark/depends/CMakeFiles/zm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libzm.a"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends && $(CMAKE_COMMAND) -P CMakeFiles/zm.dir/cmake_clean_target.cmake
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
depends/libsnark/depends/CMakeFiles/zm.dir/build: depends/libsnark/depends/libzm.a
.PHONY : depends/libsnark/depends/CMakeFiles/zm.dir/build

depends/libsnark/depends/CMakeFiles/zm.dir/requires: depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm.cpp.o.requires
depends/libsnark/depends/CMakeFiles/zm.dir/requires: depends/libsnark/depends/CMakeFiles/zm.dir/ate-pairing/src/zm2.cpp.o.requires
.PHONY : depends/libsnark/depends/CMakeFiles/zm.dir/requires

depends/libsnark/depends/CMakeFiles/zm.dir/clean:
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends && $(CMAKE_COMMAND) -P CMakeFiles/zm.dir/cmake_clean.cmake
.PHONY : depends/libsnark/depends/CMakeFiles/zm.dir/clean

depends/libsnark/depends/CMakeFiles/zm.dir/depend:
	cd /home/hanyun/Desktop/598NB_final/tutorial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hanyun/Desktop/598NB_final/tutorial /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/depends /home/hanyun/Desktop/598NB_final/tutorial/build /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/depends/CMakeFiles/zm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : depends/libsnark/depends/CMakeFiles/zm.dir/depend

