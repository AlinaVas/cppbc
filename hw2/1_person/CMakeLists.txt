cmake_minimum_required(VERSION 2.8)

project(myProj)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++11")

set(SOURCES main.cpp Person.cpp)

add_executable(myapp ${SOURCES})
