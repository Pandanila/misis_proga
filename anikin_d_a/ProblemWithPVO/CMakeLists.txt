cmake_minimum_required(VERSION 3.24)
project(ProblemWithPVO)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(geom)

add_executable(main main.cpp)

target_link_libraries(main geom)
