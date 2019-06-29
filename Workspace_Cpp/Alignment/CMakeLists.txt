cmake_minimum_required(VERSION 2.8)


project(Alignment)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCES
One.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
