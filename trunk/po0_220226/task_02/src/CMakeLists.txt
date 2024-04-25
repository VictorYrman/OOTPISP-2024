cmake_minimum_required(VERSION 3.15.0)

project(LAB_02_220226)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} Car.h Car.cpp Express.h Express.cpp Train.h Train.cpp Transport_Vehicle.h Transport_Vehicle.cpp main.cpp)