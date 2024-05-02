cmake_minimum_required(VERSION 3.15.0)

project(LAB_03_220226)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} ContainerUnit.h Container.h Container.cpp Geometry.h Geometry.cpp Ball.h Ball.cpp Cone.h Cone.cpp Pyramid.h Pyramid.cpp main.cpp)