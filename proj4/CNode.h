//
// Created by kamil on 22/11/2025.
//

#ifndef PROJ3_CNODE_H
#define PROJ3_CNODE_H

#include <string>
#include "CTokenizer.h"
#include "CVarList.h"

class CNode {
    std::string value;

    enum NodeType {UNDEFINED, OPERATOR, NUMBER, VARIABLE};
    NodeType type;

    CNode* children;
    int childCount;

    public:
    CNode();
    ~CNode();
    CNode(const CNode& other);
    CNode& operator=(const CNode& other);

    void join(const CNode& other);

    void insert(const CNode& other);

    NodeType detectType();
    bool setType();

    void resize(int len);

    bool isOperator();
    bool isNumber();
    bool isVariable();

    std::string insert(CTokenizer& tokenizer);
    std::string printLower();

    void insertToVarlist(CVarList& list);

    double comp(CVarList &list);
    double getValue(const CVarList &list) const;
};

#endif //PROJ3_CNODE_H