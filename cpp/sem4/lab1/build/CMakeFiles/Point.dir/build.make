# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/stud2021/1kolanko/AGH/cpp/sem4/lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stud2021/1kolanko/AGH/cpp/sem4/lab1/build

# Include any dependencies generated for this target.
include CMakeFiles/Point.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Point.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Point.dir/flags.make

CMakeFiles/Point.dir/Main.cpp.o: CMakeFiles/Point.dir/flags.make
CMakeFiles/Point.dir/Main.cpp.o: ../Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stud2021/1kolanko/AGH/cpp/sem4/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Point.dir/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Point.dir/Main.cpp.o -c /home/stud2021/1kolanko/AGH/cpp/sem4/lab1/Main.cpp

CMakeFiles/Point.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Point.dir/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stud2021/1kolanko/AGH/cpp/sem4/lab1/Main.cpp > CMakeFiles/Point.dir/Main.cpp.i

CMakeFiles/Point.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Point.dir/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stud2021/1kolanko/AGH/cpp/sem4/lab1/Main.cpp -o CMakeFiles/Point.dir/Main.cpp.s

# Object files for target Point
Point_OBJECTS = \
"CMakeFiles/Point.dir/Main.cpp.o"

# External object files for target Point
Point_EXTERNAL_OBJECTS =

Point: CMakeFiles/Point.dir/Main.cpp.o
Point: CMakeFiles/Point.dir/build.make
Point: CMakeFiles/Point.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stud2021/1kolanko/AGH/cpp/sem4/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Point"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Point.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Point.dir/build: Point

.PHONY : CMakeFiles/Point.dir/build

CMakeFiles/Point.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Point.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Point.dir/clean

CMakeFiles/Point.dir/depend:
	cd /home/stud2021/1kolanko/AGH/cpp/sem4/lab1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stud2021/1kolanko/AGH/cpp/sem4/lab1 /home/stud2021/1kolanko/AGH/cpp/sem4/lab1 /home/stud2021/1kolanko/AGH/cpp/sem4/lab1/build /home/stud2021/1kolanko/AGH/cpp/sem4/lab1/build /home/stud2021/1kolanko/AGH/cpp/sem4/lab1/build/CMakeFiles/Point.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Point.dir/depend

