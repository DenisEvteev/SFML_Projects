cmake_minimum_required(VERSION 3.14)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "/home/denis/CLionProjects/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS audio graphics window system network REQUIRED)

add_executable(SnakeGame main.cpp Game.cpp Game.hpp Snake.cpp Snake.hpp Fruit.cpp Fruit.hpp Shape.cpp Shape.hpp)

target_link_libraries(SnakeGame sfml-audio sfml-graphics sfml-window sfml-system)