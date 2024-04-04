cmake_minimum_required(VERSION 3.15.0)

project(LAB_01_220226)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} Person.h main.cpp Person.cpp)