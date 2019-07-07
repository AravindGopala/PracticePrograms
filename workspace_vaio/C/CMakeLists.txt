cmake_minimum_required(VERSION 2.8)

project(Assignment)
find_package (Threads)
set (SOURCES 
main.c
ISerialFilterService.h
SerialFilter.c)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
