cmake_minimum_required(VERSION 2.8)

project(Threads)
find_package(pthread)
add_executable(${PROJECT_NAME} "main.c")
TARGET_LINK_LIBRARIES(${PROJECT_NAME} pthread.so)
