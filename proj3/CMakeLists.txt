cmake_minimum_required(VERSION 4.0)
project(proj3)

set(CMAKE_CXX_STANDARD 98)

add_executable(proj3 main.cpp
        CTree.cpp
        CTree.h
        CNode.cpp
        CNode.h
        CVarList.cpp
        CVarList.h
        CTokenizer.cpp
        CTokenizer.h
        CInterface.cpp
        CInterface.h
        constants.h
        CErrorMessage.cpp
        CErrorMessage.h
)
