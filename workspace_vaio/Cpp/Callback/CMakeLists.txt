cmake_minimum_required(VERSION 2.8)

project(Callback)
find_package (Threads)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
