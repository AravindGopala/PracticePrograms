cmake_minimum_required(VERSION 2.8)

project(Observer_Pattern)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set (SOURCES
  IObserver.h
  ISubject.h
  WeatherStation.h
  WeatherStation.cpp
  main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
