cmake_minimum_required(VERSION 2.8)

project(LinkedList)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(SOURCE_FILES append.cpp main.cpp delete.cpp node.h node.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
