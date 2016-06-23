cmake_minimum_required(VERSION 3.5)
project(algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GreedyAlgo.h GreedyAlgo.cpp unit_test.h unit_test.cpp)
add_executable(algorithms ${SOURCE_FILES})