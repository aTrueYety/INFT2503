cmake_minimum_required(VERSION 3.10)

project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(test main.cpp)
