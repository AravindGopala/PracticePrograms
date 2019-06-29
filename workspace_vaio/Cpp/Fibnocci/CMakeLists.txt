cmake_minimum_required(VERSION 2.8)

project(Fibnocci)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
add_executable(${PROJECT_NAME} "main.cpp")
