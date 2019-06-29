cmake_minimum_required(VERSION 2.8)

project(CopyConstructor)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-elide-constructors")
add_executable(${PROJECT_NAME} "main.cpp")
