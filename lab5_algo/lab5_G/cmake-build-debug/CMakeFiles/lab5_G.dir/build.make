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
CMAKE_SOURCE_DIR = C:\Users\1123085\CLionProjects\lab5_algo\lab5_G

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\1123085\CLionProjects\lab5_algo\lab5_G\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab5_G.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab5_G.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab5_G.dir/flags.make

CMakeFiles/lab5_G.dir/main.cpp.obj: CMakeFiles/lab5_G.dir/flags.make
CMakeFiles/lab5_G.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\1123085\CLionProjects\lab5_algo\lab5_G\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab5_G.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab5_G.dir\main.cpp.obj -c C:\Users\1123085\CLionProjects\lab5_algo\lab5_G\main.cpp

CMakeFiles/lab5_G.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_G.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\1123085\CLionProjects\lab5_algo\lab5_G\main.cpp > CMakeFiles\lab5_G.dir\main.cpp.i

CMakeFiles/lab5_G.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_G.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\1123085\CLionProjects\lab5_algo\lab5_G\main.cpp -o CMakeFiles\lab5_G.dir\main.cpp.s

# Object files for target lab5_G
lab5_G_OBJECTS = \
"CMakeFiles/lab5_G.dir/main.cpp.obj"

# External object files for target lab5_G
lab5_G_EXTERNAL_OBJECTS =

lab5_G.exe: CMakeFiles/lab5_G.dir/main.cpp.obj
lab5_G.exe: CMakeFiles/lab5_G.dir/build.make
lab5_G.exe: CMakeFiles/lab5_G.dir/linklibs.rsp
lab5_G.exe: CMakeFiles/lab5_G.dir/objects1.rsp
lab5_G.exe: CMakeFiles/lab5_G.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\1123085\CLionProjects\lab5_algo\lab5_G\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab5_G.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab5_G.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab5_G.dir/build: lab5_G.exe

.PHONY : CMakeFiles/lab5_G.dir/build

CMakeFiles/lab5_G.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab5_G.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab5_G.dir/clean

CMakeFiles/lab5_G.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\1123085\CLionProjects\lab5_algo\lab5_G C:\Users\1123085\CLionProjects\lab5_algo\lab5_G C:\Users\1123085\CLionProjects\lab5_algo\lab5_G\cmake-build-debug C:\Users\1123085\CLionProjects\lab5_algo\lab5_G\cmake-build-debug C:\Users\1123085\CLionProjects\lab5_algo\lab5_G\cmake-build-debug\CMakeFiles\lab5_G.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab5_G.dir/depend

