# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/prI_cycleGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prI_cycleGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prI_cycleGame.dir/flags.make

CMakeFiles/prI_cycleGame.dir/main.cpp.obj: CMakeFiles/prI_cycleGame.dir/flags.make
CMakeFiles/prI_cycleGame.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prI_cycleGame.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\prI_cycleGame.dir\main.cpp.obj -c C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame\main.cpp

CMakeFiles/prI_cycleGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prI_cycleGame.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame\main.cpp > CMakeFiles\prI_cycleGame.dir\main.cpp.i

CMakeFiles/prI_cycleGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prI_cycleGame.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame\main.cpp -o CMakeFiles\prI_cycleGame.dir\main.cpp.s

# Object files for target prI_cycleGame
prI_cycleGame_OBJECTS = \
"CMakeFiles/prI_cycleGame.dir/main.cpp.obj"

# External object files for target prI_cycleGame
prI_cycleGame_EXTERNAL_OBJECTS =

prI_cycleGame.exe: CMakeFiles/prI_cycleGame.dir/main.cpp.obj
prI_cycleGame.exe: CMakeFiles/prI_cycleGame.dir/build.make
prI_cycleGame.exe: CMakeFiles/prI_cycleGame.dir/linklibs.rsp
prI_cycleGame.exe: CMakeFiles/prI_cycleGame.dir/objects1.rsp
prI_cycleGame.exe: CMakeFiles/prI_cycleGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prI_cycleGame.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\prI_cycleGame.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prI_cycleGame.dir/build: prI_cycleGame.exe

.PHONY : CMakeFiles/prI_cycleGame.dir/build

CMakeFiles/prI_cycleGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\prI_cycleGame.dir\cmake_clean.cmake
.PHONY : CMakeFiles/prI_cycleGame.dir/clean

CMakeFiles/prI_cycleGame.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame\cmake-build-debug C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame\cmake-build-debug C:\Users\lizzka239\CLionProjects\algoLab2\prI-cycleGame\cmake-build-debug\CMakeFiles\prI_cycleGame.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prI_cycleGame.dir/depend

