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
CMAKE_SOURCE_DIR = /home/stud2021/1kolanko/laby/sem3/lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stud2021/1kolanko/laby/sem3/lab5/build

# Utility rule file for test2.

# Include the progress variables for this target.
include CMakeFiles/test2.dir/progress.make

CMakeFiles/test2:
	./main ala_ma_kota ala_ma_kota

test2: CMakeFiles/test2
test2: CMakeFiles/test2.dir/build.make

.PHONY : test2

# Rule to build all files generated by this target.
CMakeFiles/test2.dir/build: test2

.PHONY : CMakeFiles/test2.dir/build

CMakeFiles/test2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test2.dir/clean

CMakeFiles/test2.dir/depend:
	cd /home/stud2021/1kolanko/laby/sem3/lab5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stud2021/1kolanko/laby/sem3/lab5 /home/stud2021/1kolanko/laby/sem3/lab5 /home/stud2021/1kolanko/laby/sem3/lab5/build /home/stud2021/1kolanko/laby/sem3/lab5/build /home/stud2021/1kolanko/laby/sem3/lab5/build/CMakeFiles/test2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test2.dir/depend
