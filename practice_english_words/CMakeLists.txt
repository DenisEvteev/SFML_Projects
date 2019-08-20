cmake_minimum_required(VERSION 3.14)
project(practice_english_words)

set(CMAKE_CXX_STANDARD 14)

set(STRING_LIB "/home/denis/CLionProjects/String_Lib/String.cpp")

set(Exceptions "/home/denis/CLionProjects/MyExceptions/My_Exception.cpp")

set(Alloc "/home/denis/CLionProjects/vec_lib/TrackingAllocator.hpp")

set(SFML_DIR "/home/denis/CLionProjects/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS audio graphics window system network REQUIRED)

add_executable(practice_english_words main.cpp Eng_Practice.cpp Eng_Practice.hpp
${STRING_LIB} ${Exceptions} ${Alloc})

target_link_libraries(practice_english_words sfml-audio sfml-graphics sfml-window sfml-system)