cmake_minimum_required(VERSION 3.15.0)

project(LAB_04_220227)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} List.h Pair.h Pair.cpp main.cpp)