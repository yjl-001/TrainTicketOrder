# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "D:\Clion\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Clion\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C_code\TrainTicketOrder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C_code\TrainTicketOrder\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TrainTicketOrder.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/TrainTicketOrder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrainTicketOrder.dir/flags.make

CMakeFiles/TrainTicketOrder.dir/main.cpp.obj: CMakeFiles/TrainTicketOrder.dir/flags.make
CMakeFiles/TrainTicketOrder.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C_code\TrainTicketOrder\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TrainTicketOrder.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TrainTicketOrder.dir\main.cpp.obj -c D:\C_code\TrainTicketOrder\main.cpp

CMakeFiles/TrainTicketOrder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrainTicketOrder.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C_code\TrainTicketOrder\main.cpp > CMakeFiles\TrainTicketOrder.dir\main.cpp.i

CMakeFiles/TrainTicketOrder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrainTicketOrder.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C_code\TrainTicketOrder\main.cpp -o CMakeFiles\TrainTicketOrder.dir\main.cpp.s

# Object files for target TrainTicketOrder
TrainTicketOrder_OBJECTS = \
"CMakeFiles/TrainTicketOrder.dir/main.cpp.obj"

# External object files for target TrainTicketOrder
TrainTicketOrder_EXTERNAL_OBJECTS =

TrainTicketOrder.exe: CMakeFiles/TrainTicketOrder.dir/main.cpp.obj
TrainTicketOrder.exe: CMakeFiles/TrainTicketOrder.dir/build.make
TrainTicketOrder.exe: CMakeFiles/TrainTicketOrder.dir/linklibs.rsp
TrainTicketOrder.exe: CMakeFiles/TrainTicketOrder.dir/objects1.rsp
TrainTicketOrder.exe: CMakeFiles/TrainTicketOrder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C_code\TrainTicketOrder\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TrainTicketOrder.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TrainTicketOrder.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrainTicketOrder.dir/build: TrainTicketOrder.exe
.PHONY : CMakeFiles/TrainTicketOrder.dir/build

CMakeFiles/TrainTicketOrder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TrainTicketOrder.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TrainTicketOrder.dir/clean

CMakeFiles/TrainTicketOrder.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C_code\TrainTicketOrder D:\C_code\TrainTicketOrder D:\C_code\TrainTicketOrder\cmake-build-debug D:\C_code\TrainTicketOrder\cmake-build-debug D:\C_code\TrainTicketOrder\cmake-build-debug\CMakeFiles\TrainTicketOrder.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TrainTicketOrder.dir/depend

