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
include depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/depend.make

# Include the progress variables for this target.
include depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/progress.make

# Include the compile flags for this target's objects.
include depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/flags.make

depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o: depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/flags.make
depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o: ../depends/libsnark/libsnark/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hanyun/Desktop/598NB_final/tutorial/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/libsnark && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o -c /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/libsnark/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp

depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.i"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/libsnark && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/libsnark/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp > CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.i

depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.s"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/libsnark && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/libsnark/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp -o CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.s

depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o.requires:
.PHONY : depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o.requires

depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o.provides: depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o.requires
	$(MAKE) -f depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/build.make depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o.provides.build
.PHONY : depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o.provides

depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o.provides.build: depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o

# Object files for target gadgetlib1_r1cs_ppzksnark_verifier_gadget_test
gadgetlib1_r1cs_ppzksnark_verifier_gadget_test_OBJECTS = \
"CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o"

# External object files for target gadgetlib1_r1cs_ppzksnark_verifier_gadget_test
gadgetlib1_r1cs_ppzksnark_verifier_gadget_test_EXTERNAL_OBJECTS =

depends/libsnark/libsnark/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test: depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o
depends/libsnark/libsnark/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test: depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/build.make
depends/libsnark/libsnark/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test: depends/libsnark/libsnark/libsnark.a
depends/libsnark/libsnark/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test: depends/libsnark/depends/libff/libff/libff.a
depends/libsnark/libsnark/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test: /usr/lib/x86_64-linux-gnu/libgmp.so
depends/libsnark/libsnark/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test: /usr/lib/x86_64-linux-gnu/libgmp.so
depends/libsnark/libsnark/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test: /usr/lib/x86_64-linux-gnu/libgmpxx.so
depends/libsnark/libsnark/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test: depends/libsnark/depends/libzm.a
depends/libsnark/libsnark/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test: depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable gadgetlib1_r1cs_ppzksnark_verifier_gadget_test"
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/libsnark && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/build: depends/libsnark/libsnark/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test
.PHONY : depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/build

depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/requires: depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/gadgetlib1/gadgets/verifiers/tests/test_r1cs_ppzksnark_verifier_gadget.cpp.o.requires
.PHONY : depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/requires

depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/clean:
	cd /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/libsnark && $(CMAKE_COMMAND) -P CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/cmake_clean.cmake
.PHONY : depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/clean

depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/depend:
	cd /home/hanyun/Desktop/598NB_final/tutorial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hanyun/Desktop/598NB_final/tutorial /home/hanyun/Desktop/598NB_final/tutorial/depends/libsnark/libsnark /home/hanyun/Desktop/598NB_final/tutorial/build /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/libsnark /home/hanyun/Desktop/598NB_final/tutorial/build/depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : depends/libsnark/libsnark/CMakeFiles/gadgetlib1_r1cs_ppzksnark_verifier_gadget_test.dir/depend

