cmake_minimum_required(VERSION 2.8)
project(algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FIND_PACKAGE(OpenCV REQUIRED)

aux_source_directory(. SOURCE_FILES)

#set(SOURCE_FILES main.cpp  GreedyAlgo.cpp  unit_test.cpp chineseAndnumber.cpp)
add_executable(algorithms ${SOURCE_FILES})

target_link_libraries(algorithms ${OpenCV_LIBS})
