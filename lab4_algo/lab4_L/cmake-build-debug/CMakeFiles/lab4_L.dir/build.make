# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\1123085\CLionProjects\lab4_algo\lab4_L

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\1123085\CLionProjects\lab4_algo\lab4_L\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab4_L.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab4_L.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab4_L.dir/flags.make

CMakeFiles/lab4_L.dir/main.cpp.obj: CMakeFiles/lab4_L.dir/flags.make
CMakeFiles/lab4_L.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\1123085\CLionProjects\lab4_algo\lab4_L\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab4_L.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab4_L.dir\main.cpp.obj -c C:\Users\1123085\CLionProjects\lab4_algo\lab4_L\main.cpp

CMakeFiles/lab4_L.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4_L.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\1123085\CLionProjects\lab4_algo\lab4_L\main.cpp > CMakeFiles\lab4_L.dir\main.cpp.i

CMakeFiles/lab4_L.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4_L.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\1123085\CLionProjects\lab4_algo\lab4_L\main.cpp -o CMakeFiles\lab4_L.dir\main.cpp.s

# Object files for target lab4_L
lab4_L_OBJECTS = \
"CMakeFiles/lab4_L.dir/main.cpp.obj"

# External object files for target lab4_L
lab4_L_EXTERNAL_OBJECTS =

lab4_L.exe: CMakeFiles/lab4_L.dir/main.cpp.obj
lab4_L.exe: CMakeFiles/lab4_L.dir/build.make
lab4_L.exe: CMakeFiles/lab4_L.dir/linklibs.rsp
lab4_L.exe: CMakeFiles/lab4_L.dir/objects1.rsp
lab4_L.exe: CMakeFiles/lab4_L.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\1123085\CLionProjects\lab4_algo\lab4_L\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab4_L.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab4_L.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab4_L.dir/build: lab4_L.exe

.PHONY : CMakeFiles/lab4_L.dir/build

CMakeFiles/lab4_L.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab4_L.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab4_L.dir/clean

CMakeFiles/lab4_L.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\1123085\CLionProjects\lab4_algo\lab4_L C:\Users\1123085\CLionProjects\lab4_algo\lab4_L C:\Users\1123085\CLionProjects\lab4_algo\lab4_L\cmake-build-debug C:\Users\1123085\CLionProjects\lab4_algo\lab4_L\cmake-build-debug C:\Users\1123085\CLionProjects\lab4_algo\lab4_L\cmake-build-debug\CMakeFiles\lab4_L.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab4_L.dir/depend

