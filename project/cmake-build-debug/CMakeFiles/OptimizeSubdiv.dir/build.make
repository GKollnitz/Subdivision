# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/gunkol-5/clion-2017.2.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/gunkol-5/clion-2017.2.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OptimizeSubdiv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OptimizeSubdiv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OptimizeSubdiv.dir/flags.make

CMakeFiles/OptimizeSubdiv.dir/main.cpp.o: CMakeFiles/OptimizeSubdiv.dir/flags.make
CMakeFiles/OptimizeSubdiv.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OptimizeSubdiv.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OptimizeSubdiv.dir/main.cpp.o -c /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/main.cpp

CMakeFiles/OptimizeSubdiv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OptimizeSubdiv.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/main.cpp > CMakeFiles/OptimizeSubdiv.dir/main.cpp.i

CMakeFiles/OptimizeSubdiv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OptimizeSubdiv.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/main.cpp -o CMakeFiles/OptimizeSubdiv.dir/main.cpp.s

CMakeFiles/OptimizeSubdiv.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/OptimizeSubdiv.dir/main.cpp.o.requires

CMakeFiles/OptimizeSubdiv.dir/main.cpp.o.provides: CMakeFiles/OptimizeSubdiv.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/OptimizeSubdiv.dir/build.make CMakeFiles/OptimizeSubdiv.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/OptimizeSubdiv.dir/main.cpp.o.provides

CMakeFiles/OptimizeSubdiv.dir/main.cpp.o.provides.build: CMakeFiles/OptimizeSubdiv.dir/main.cpp.o


CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o: CMakeFiles/OptimizeSubdiv.dir/flags.make
CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o: ../HE_Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o -c /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/HE_Mesh.cpp

CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/HE_Mesh.cpp > CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.i

CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/HE_Mesh.cpp -o CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.s

CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o.requires:

.PHONY : CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o.requires

CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o.provides: CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/OptimizeSubdiv.dir/build.make CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o.provides.build
.PHONY : CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o.provides

CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o.provides.build: CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o


# Object files for target OptimizeSubdiv
OptimizeSubdiv_OBJECTS = \
"CMakeFiles/OptimizeSubdiv.dir/main.cpp.o" \
"CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o"

# External object files for target OptimizeSubdiv
OptimizeSubdiv_EXTERNAL_OBJECTS =

OptimizeSubdiv: CMakeFiles/OptimizeSubdiv.dir/main.cpp.o
OptimizeSubdiv: CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o
OptimizeSubdiv: CMakeFiles/OptimizeSubdiv.dir/build.make
OptimizeSubdiv: CMakeFiles/OptimizeSubdiv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OptimizeSubdiv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OptimizeSubdiv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OptimizeSubdiv.dir/build: OptimizeSubdiv

.PHONY : CMakeFiles/OptimizeSubdiv.dir/build

CMakeFiles/OptimizeSubdiv.dir/requires: CMakeFiles/OptimizeSubdiv.dir/main.cpp.o.requires
CMakeFiles/OptimizeSubdiv.dir/requires: CMakeFiles/OptimizeSubdiv.dir/HE_Mesh.cpp.o.requires

.PHONY : CMakeFiles/OptimizeSubdiv.dir/requires

CMakeFiles/OptimizeSubdiv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OptimizeSubdiv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OptimizeSubdiv.dir/clean

CMakeFiles/OptimizeSubdiv.dir/depend:
	cd /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/cmake-build-debug /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/cmake-build-debug /home/gunkol-5/Documents/git/gunkol-5/S0017D/OptimizeSubdiv/cmake-build-debug/CMakeFiles/OptimizeSubdiv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OptimizeSubdiv.dir/depend

