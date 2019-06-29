cmake_minimum_required(VERSION 2.8)


project(AdapterPattern)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCES
    Duck.h
    FlyBehavior.h
    MallardDuck.h
    ModelDuck.h
    NoWings.h
    QuackBehavior.h
    Quack.h
    Squeak.h
    Wings.h
    Simulator.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
