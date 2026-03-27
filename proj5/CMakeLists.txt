cmake_minimum_required(VERSION 4.0)
project(proj5)

set(CMAKE_CXX_STANDARD 11)

add_executable(proj5 main.cpp
        CTree/CTree.cpp
        CTree/CTree.h
        CTree/CNode.cpp
        CTree/CNode.h
        CTree/CVarList.cpp
        CTree/CVarList.h
        CTree/CTokenizer.cpp
        CTree/CTokenizer.h
        CTree/CInterface.cpp
        CTree/CInterface.h
        CTree/constants.h
        CTree/CErrorMessage.cpp
        CTree/CErrorMessage.h
        CTree/CError.cpp
        CTree/CError.h
        CTree/CResult.tpp
        CTree/CResult.hpp
        CTree/CResultSaver.cpp
        CTree/CResultSaver.tpp
        CTree/CResultSaver.h
        CTree/CTreeCreator.cpp
        CTree/CTreeCreator.h
        CMySmartPointer.tpp
        CMySmartPointer.hpp
        CRefCounter.cpp
        CRefCounter.h
        CRegistry.cpp
        CRegistry.h)
