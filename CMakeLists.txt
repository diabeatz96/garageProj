cmake_minimum_required(VERSION 3.21)
project(garageProj)

set(CMAKE_CXX_STANDARD 14)

add_executable(garageProj main.cpp Garage.cpp Garage.h Stack.cpp Stack.h)
