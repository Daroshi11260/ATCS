# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\yoshi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\yoshi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MarkovChain.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MarkovChain.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MarkovChain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MarkovChain.dir/flags.make

CMakeFiles/MarkovChain.dir/main.cpp.obj: CMakeFiles/MarkovChain.dir/flags.make
CMakeFiles/MarkovChain.dir/main.cpp.obj: C:/Users/yoshi/Downloads/ATCS/Unit_2/MarkovChain2023/main.cpp
CMakeFiles/MarkovChain.dir/main.cpp.obj: CMakeFiles/MarkovChain.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MarkovChain.dir/main.cpp.obj"
	C:\Users\yoshi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MarkovChain.dir/main.cpp.obj -MF CMakeFiles\MarkovChain.dir\main.cpp.obj.d -o CMakeFiles\MarkovChain.dir\main.cpp.obj -c C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023\main.cpp

CMakeFiles/MarkovChain.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarkovChain.dir/main.cpp.i"
	C:\Users\yoshi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023\main.cpp > CMakeFiles\MarkovChain.dir\main.cpp.i

CMakeFiles/MarkovChain.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarkovChain.dir/main.cpp.s"
	C:\Users\yoshi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\232.9559.58\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023\main.cpp -o CMakeFiles\MarkovChain.dir\main.cpp.s

# Object files for target MarkovChain
MarkovChain_OBJECTS = \
"CMakeFiles/MarkovChain.dir/main.cpp.obj"

# External object files for target MarkovChain
MarkovChain_EXTERNAL_OBJECTS =

C:/Users/yoshi/Downloads/ATCS/Unit_2/MarkovChain2023/MarkovChain.exe: CMakeFiles/MarkovChain.dir/main.cpp.obj
C:/Users/yoshi/Downloads/ATCS/Unit_2/MarkovChain2023/MarkovChain.exe: CMakeFiles/MarkovChain.dir/build.make
C:/Users/yoshi/Downloads/ATCS/Unit_2/MarkovChain2023/MarkovChain.exe: CMakeFiles/MarkovChain.dir/linkLibs.rsp
C:/Users/yoshi/Downloads/ATCS/Unit_2/MarkovChain2023/MarkovChain.exe: CMakeFiles/MarkovChain.dir/objects1.rsp
C:/Users/yoshi/Downloads/ATCS/Unit_2/MarkovChain2023/MarkovChain.exe: CMakeFiles/MarkovChain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023\MarkovChain.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MarkovChain.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MarkovChain.dir/build: C:/Users/yoshi/Downloads/ATCS/Unit_2/MarkovChain2023/MarkovChain.exe
.PHONY : CMakeFiles/MarkovChain.dir/build

CMakeFiles/MarkovChain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MarkovChain.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MarkovChain.dir/clean

CMakeFiles/MarkovChain.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023 C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023 C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023\cmake-build-debug C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023\cmake-build-debug C:\Users\yoshi\Downloads\ATCS\Unit_2\MarkovChain2023\cmake-build-debug\CMakeFiles\MarkovChain.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MarkovChain.dir/depend

