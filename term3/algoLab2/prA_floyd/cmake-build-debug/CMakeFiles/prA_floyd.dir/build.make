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
CMAKE_SOURCE_DIR = C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/prA_floyd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prA_floyd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prA_floyd.dir/flags.make

CMakeFiles/prA_floyd.dir/main.cpp.obj: CMakeFiles/prA_floyd.dir/flags.make
CMakeFiles/prA_floyd.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prA_floyd.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\prA_floyd.dir\main.cpp.obj -c C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd\main.cpp

CMakeFiles/prA_floyd.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prA_floyd.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd\main.cpp > CMakeFiles\prA_floyd.dir\main.cpp.i

CMakeFiles/prA_floyd.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prA_floyd.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd\main.cpp -o CMakeFiles\prA_floyd.dir\main.cpp.s

# Object files for target prA_floyd
prA_floyd_OBJECTS = \
"CMakeFiles/prA_floyd.dir/main.cpp.obj"

# External object files for target prA_floyd
prA_floyd_EXTERNAL_OBJECTS =

prA_floyd.exe: CMakeFiles/prA_floyd.dir/main.cpp.obj
prA_floyd.exe: CMakeFiles/prA_floyd.dir/build.make
prA_floyd.exe: CMakeFiles/prA_floyd.dir/linklibs.rsp
prA_floyd.exe: CMakeFiles/prA_floyd.dir/objects1.rsp
prA_floyd.exe: CMakeFiles/prA_floyd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prA_floyd.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\prA_floyd.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prA_floyd.dir/build: prA_floyd.exe

.PHONY : CMakeFiles/prA_floyd.dir/build

CMakeFiles/prA_floyd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\prA_floyd.dir\cmake_clean.cmake
.PHONY : CMakeFiles/prA_floyd.dir/clean

CMakeFiles/prA_floyd.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd\cmake-build-debug C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd\cmake-build-debug C:\Users\lizzka239\CLionProjects\algoLab2\prA_floyd\cmake-build-debug\CMakeFiles\prA_floyd.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prA_floyd.dir/depend

