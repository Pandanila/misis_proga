cmake_minimum_required(VERSION 3.24)
project(problem)

add_subdirectory(geom)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)
target_link_libraries(main geom)
