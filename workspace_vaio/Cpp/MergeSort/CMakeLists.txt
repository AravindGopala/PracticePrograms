cmake_minimum_required(VERSION 2.8)

project(MergeSort)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(SOURCE_FILES  main.cpp merge.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
