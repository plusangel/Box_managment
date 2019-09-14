cmake_minimum_required(VERSION 3.14)
project(Truckload)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(box include/Box.h)
add_library(package include/Package.h)
add_library(truck src/Truckload.cpp)
add_library(truck_nested src/Truckload_nested.cpp)

add_executable(Truckload main.cpp)
target_link_libraries(Truckload truck_nested)