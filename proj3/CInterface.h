//
// Created by kamil on 23/11/2025.
//

#ifndef PROJ3_CINTERFACE_H
#define PROJ3_CINTERFACE_H

#include "CTree.h"

class CInterface {
    CTree *tree;

    public:
    CInterface();
    ~CInterface();

    void stream();

    void enter(const std::string &);
    void vars();
    void print();
    void comp(const std::string &);
    void join(const std::string &);
};

#endif //PROJ3_CINTERFACE_H