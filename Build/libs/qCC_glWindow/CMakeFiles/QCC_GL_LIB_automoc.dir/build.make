# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ds/3rdPart/CloudCompareTool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ds/3rdPart/CloudCompareTool/Build

# Utility rule file for QCC_GL_LIB_automoc.

# Include the progress variables for this target.
include libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc.dir/progress.make

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ds/3rdPart/CloudCompareTool/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic moc for target QCC_GL_LIB"
	cd /home/ds/3rdPart/CloudCompareTool/Build/libs/qCC_glWindow && /usr/bin/cmake -E cmake_autogen /home/ds/3rdPart/CloudCompareTool/Build/libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc.dir/ Debug

QCC_GL_LIB_automoc: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc
QCC_GL_LIB_automoc: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc.dir/build.make

.PHONY : QCC_GL_LIB_automoc

# Rule to build all files generated by this target.
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc.dir/build: QCC_GL_LIB_automoc

.PHONY : libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc.dir/build

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc.dir/clean:
	cd /home/ds/3rdPart/CloudCompareTool/Build/libs/qCC_glWindow && $(CMAKE_COMMAND) -P CMakeFiles/QCC_GL_LIB_automoc.dir/cmake_clean.cmake
.PHONY : libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc.dir/clean

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc.dir/depend:
	cd /home/ds/3rdPart/CloudCompareTool/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ds/3rdPart/CloudCompareTool /home/ds/3rdPart/CloudCompareTool/libs/qCC_glWindow /home/ds/3rdPart/CloudCompareTool/Build /home/ds/3rdPart/CloudCompareTool/Build/libs/qCC_glWindow /home/ds/3rdPart/CloudCompareTool/Build/libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB_automoc.dir/depend
