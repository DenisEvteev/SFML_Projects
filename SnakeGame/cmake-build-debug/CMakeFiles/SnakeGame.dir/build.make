# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/denis/CLionProjects/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/denis/CLionProjects/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/denis/CLionProjects/SnakeGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denis/CLionProjects/SnakeGame/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SnakeGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SnakeGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SnakeGame.dir/flags.make

CMakeFiles/SnakeGame.dir/main.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/CLionProjects/SnakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SnakeGame.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/main.cpp.o -c /home/denis/CLionProjects/SnakeGame/main.cpp

CMakeFiles/SnakeGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/CLionProjects/SnakeGame/main.cpp > CMakeFiles/SnakeGame.dir/main.cpp.i

CMakeFiles/SnakeGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/CLionProjects/SnakeGame/main.cpp -o CMakeFiles/SnakeGame.dir/main.cpp.s

CMakeFiles/SnakeGame.dir/Game.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/CLionProjects/SnakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SnakeGame.dir/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/Game.cpp.o -c /home/denis/CLionProjects/SnakeGame/Game.cpp

CMakeFiles/SnakeGame.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/CLionProjects/SnakeGame/Game.cpp > CMakeFiles/SnakeGame.dir/Game.cpp.i

CMakeFiles/SnakeGame.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/CLionProjects/SnakeGame/Game.cpp -o CMakeFiles/SnakeGame.dir/Game.cpp.s

CMakeFiles/SnakeGame.dir/Snake.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/Snake.cpp.o: ../Snake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/CLionProjects/SnakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SnakeGame.dir/Snake.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/Snake.cpp.o -c /home/denis/CLionProjects/SnakeGame/Snake.cpp

CMakeFiles/SnakeGame.dir/Snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/Snake.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/CLionProjects/SnakeGame/Snake.cpp > CMakeFiles/SnakeGame.dir/Snake.cpp.i

CMakeFiles/SnakeGame.dir/Snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/Snake.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/CLionProjects/SnakeGame/Snake.cpp -o CMakeFiles/SnakeGame.dir/Snake.cpp.s

CMakeFiles/SnakeGame.dir/Fruit.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/Fruit.cpp.o: ../Fruit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/CLionProjects/SnakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SnakeGame.dir/Fruit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/Fruit.cpp.o -c /home/denis/CLionProjects/SnakeGame/Fruit.cpp

CMakeFiles/SnakeGame.dir/Fruit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/Fruit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/CLionProjects/SnakeGame/Fruit.cpp > CMakeFiles/SnakeGame.dir/Fruit.cpp.i

CMakeFiles/SnakeGame.dir/Fruit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/Fruit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/CLionProjects/SnakeGame/Fruit.cpp -o CMakeFiles/SnakeGame.dir/Fruit.cpp.s

CMakeFiles/SnakeGame.dir/Shape.cpp.o: CMakeFiles/SnakeGame.dir/flags.make
CMakeFiles/SnakeGame.dir/Shape.cpp.o: ../Shape.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/CLionProjects/SnakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SnakeGame.dir/Shape.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SnakeGame.dir/Shape.cpp.o -c /home/denis/CLionProjects/SnakeGame/Shape.cpp

CMakeFiles/SnakeGame.dir/Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SnakeGame.dir/Shape.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/CLionProjects/SnakeGame/Shape.cpp > CMakeFiles/SnakeGame.dir/Shape.cpp.i

CMakeFiles/SnakeGame.dir/Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SnakeGame.dir/Shape.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/CLionProjects/SnakeGame/Shape.cpp -o CMakeFiles/SnakeGame.dir/Shape.cpp.s

# Object files for target SnakeGame
SnakeGame_OBJECTS = \
"CMakeFiles/SnakeGame.dir/main.cpp.o" \
"CMakeFiles/SnakeGame.dir/Game.cpp.o" \
"CMakeFiles/SnakeGame.dir/Snake.cpp.o" \
"CMakeFiles/SnakeGame.dir/Fruit.cpp.o" \
"CMakeFiles/SnakeGame.dir/Shape.cpp.o"

# External object files for target SnakeGame
SnakeGame_EXTERNAL_OBJECTS =

SnakeGame: CMakeFiles/SnakeGame.dir/main.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/Game.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/Snake.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/Fruit.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/Shape.cpp.o
SnakeGame: CMakeFiles/SnakeGame.dir/build.make
SnakeGame: /home/denis/CLionProjects/SFML-2.5.1/lib/libsfml-audio.so.2.5.1
SnakeGame: /home/denis/CLionProjects/SFML-2.5.1/lib/libsfml-graphics.so.2.5.1
SnakeGame: /home/denis/CLionProjects/SFML-2.5.1/lib/libsfml-window.so.2.5.1
SnakeGame: /home/denis/CLionProjects/SFML-2.5.1/lib/libsfml-system.so.2.5.1
SnakeGame: CMakeFiles/SnakeGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/denis/CLionProjects/SnakeGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable SnakeGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SnakeGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SnakeGame.dir/build: SnakeGame

.PHONY : CMakeFiles/SnakeGame.dir/build

CMakeFiles/SnakeGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SnakeGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SnakeGame.dir/clean

CMakeFiles/SnakeGame.dir/depend:
	cd /home/denis/CLionProjects/SnakeGame/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denis/CLionProjects/SnakeGame /home/denis/CLionProjects/SnakeGame /home/denis/CLionProjects/SnakeGame/cmake-build-debug /home/denis/CLionProjects/SnakeGame/cmake-build-debug /home/denis/CLionProjects/SnakeGame/cmake-build-debug/CMakeFiles/SnakeGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SnakeGame.dir/depend

