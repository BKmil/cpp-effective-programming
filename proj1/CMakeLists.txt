cmake_minimum_required(VERSION 4.0)
project(proj1)

set(CMAKE_CXX_STANDARD 98)

add_executable(proj1 main.cpp
        table_utils.cpp
        table_utils.h
        CTable.cpp
        CTable.h
)
