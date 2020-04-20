cmake_minimum_required(VERSION 3.12)
project(Truckload)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    include
    ${gtest_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR}
)

add_subdirectory(lib)
enable_testing()

add_library(truck src/Truckload.cpp)

add_executable(Truckload main.cpp)
target_link_libraries(Truckload truck)

add_executable(Truckload2 tests/test2.cpp)
target_link_libraries(Truckload2 gtest gtest_main)
add_test(Truckload2 Truckload2)

add_executable(Truckload1 tests/test1.cpp)
target_link_libraries(Truckload1 truck)