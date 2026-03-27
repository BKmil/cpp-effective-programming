//
// Created by kamil on 22/11/2025.
//

#include "CTree.h"

#include <sstream>
#include "constants.h"

#include "CTokenizer.h"

CTree::CTree(): root(new CNode) {}

CTree::CTree(const CTree& other): root(other.root) {}

CTree::CTree(CTree&& other): root(std::move(other.root)) {}

CTree::~CTree() = default;

CTree &CTree::operator=(const CTree &other) {
    if (this == &other) {
        return *this;
    }
    this->root = other.root;
    return *this;
}

CTree &CTree::operator=(CTree &&other) {
    if (this != &other) {
        root = std::move(other.root);
    }
    return *this;
}

CTree CTree::operator+(const CTree& other) const {
    CTree newTree;
    *newTree.root = *this->root;
    newTree.root->join(*other.root);
    return newTree;
}

std::string CTree::insert(const std::string &str) {
    CTokenizer tokenizer;
    tokenizer.insert(str);
    std::string returnMessage = root->insert(tokenizer);
    returnMessage += tokenizer.getErrorMessage();
    return returnMessage;
}

std::string CTree::print() {
    return root->printLower();
}

CVarList CTree::varList() {
    CVarList list;
    this->root->insertToVarlist(list);
    return list;
}

std::string CTree::comp(const std::string &arg) {
    CVarList list = varList();
    std::stringstream ss("");

    if (!list.insertInts(arg)) {
        ss << ERROR_FILL;
    }
    ss << root->comp(list);
    return list.getErrorMessage() + ss.str();
}