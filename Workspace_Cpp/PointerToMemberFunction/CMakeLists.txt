cmake_minimum_required(VERSION 3.5)

project(PMF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCES
PMF.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
