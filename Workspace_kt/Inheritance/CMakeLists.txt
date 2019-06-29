cmake_minimum_required(VERSION 2.8)

project(Inheritance)
set(HEADERS include/person.h include/employee.h)
set(SOURCES main.c person.c employee.c)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
