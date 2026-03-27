cmake_minimum_required(VERSION 4.0)
project(proj2)

set(CMAKE_CXX_STANDARD 98)

add_executable(proj2 main.cpp
        CNumber.cpp
        CNumber.h
        MyInt.cpp
        MyInt.h)
