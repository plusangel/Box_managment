cmake_minimum_required(VERSION 3.12)
project(Truckload)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_subdirectory(lib)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_library(box include/Box.h)
set_target_properties(box PROPERTIES LINKER_LANGUAGE CXX)
add_library(package include/Package.h)
set_target_properties(package PROPERTIES LINKER_LANGUAGE CXX)
add_library(truck src/Truckload.cpp)
set_target_properties(truck PROPERTIES LINKER_LANGUAGE CXX)
add_library(truck_nested src/Truckload_nested.cpp)
set_target_properties(truck_nested PROPERTIES LINKER_LANGUAGE CXX)

add_executable(Truckload main.cpp)
target_link_libraries(Truckload truck)

add_executable(TruckloadUnitTests tests/testgtest.cpp)
target_link_libraries(TruckloadUnitTests gtest gtest_main)
add_test(TruckloadUnitTests TruckloadUnitTests)