//
// Created by kamil on 22/11/2025.
//

#ifndef PROJ3_CTREE_H
#define PROJ3_CTREE_H
#include "CNode.h"
#include "CVarList.h"

class CTree {
    CNode* root;

    public:
    CTree();
    CTree(const CTree& other);
    ~CTree();
    CTree& operator=(const CTree& other);

    CTree operator+(const CTree& other) const;

    std::string insert(const std::string &str);
    std::string print();

    CVarList varList();

    std::string comp(const std::string &arg);
};


#endif //PROJ3_CTREE_H