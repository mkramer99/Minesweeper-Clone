cmake_minimum_required(VERSION 3.21)
project(untitled9)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/build/lib")

add_executable(untitled9 main.cpp)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(untitled9 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)