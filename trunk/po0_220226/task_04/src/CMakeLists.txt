cmake_minimum_required(VERSION 3.15.0)

project(LAB_04_220226)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} List.h Cash.h Cash.cpp main.cpp)