//
// Created by kamil on 22/11/2025.
//

#include "CNode.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <sstream>
#include "constants.h"

CNode::CNode(): type(UNDEFINED), children(new CNode[0]), childCount(0) {}

CNode::~CNode() {
    delete[] children;
}

CNode::CNode(const CNode& other):
value(other.value), type(other.type), childCount(other.childCount) {
    children = new CNode[childCount];
    for (int i = 0; i < childCount; i++) {
        children[i] = other.children[i];
    }
}

CNode& CNode::operator=(const CNode& other) {
    if (this == &other) {
        return *this;
    }
    this->value = other.value;
    this->type = other.type;
    this->childCount = other.childCount;
    delete[] children;
    children = new CNode[this->childCount];
    for (int i = 0; i < this->childCount; i++) {
        this->children[i] = other.children[i];
    }
    return *this;
}

void CNode::join(const CNode& other) {
    if (this->childCount == 0) {
        *this = other;
        return;
    }
    this->children[0].join(other);
}

void CNode::insert(const CNode& other) {
    if (childCount == 0) {
        *this = other;
        return;
    }

    if (childCount == 1) {
        children[0] = other;
        return;
    }

    if (childCount == 2) {

        if (children[0].type == UNDEFINED) {
            children[0] = other;
            return;
        }
        children[1] = other;
    }
}

CNode::NodeType CNode::detectType() {
    if (isVariable())
        return VARIABLE;
    if (isNumber())
        return NUMBER;
    if (isOperator())
        return OPERATOR;
    return UNDEFINED;
}

bool CNode::setType() {
    this->type = detectType();
    if (this->type == OPERATOR) {
        if (this->value == OPERATOR_SIN || this->value == OPERATOR_COS) {
            resize(1);
        }
        else {
            resize(2);
        }
        return false;
    }
    bool ifFixed = false;
    if (this->type == VARIABLE) {
        std::string cleaned;

        for (int i = 0; i < this->value.size(); ++i) {
            char c = this->value[i];
            if (std::isalnum(static_cast<unsigned char>(c))) {
                cleaned += c;
            }
            else {
                ifFixed = true;
            }
        }
        this->value = cleaned.empty() ? DEFAULT_FILL : cleaned;
        this->type = detectType();
    }
    resize(0);
    return ifFixed;
}

void CNode::resize(int len) {
    if (this->childCount == len)
        return;

    CNode* newChildren = new CNode[len];
    int copyCount = (len < childCount) ? len : childCount;

    for (int i = 0; i < copyCount; ++i) {
        newChildren[i] = children[i];
    }

    delete[] children;
    children = newChildren;
    childCount = len;
}

bool CNode::isOperator() {
    if (this->value == OPERATOR_ADDITION || this->value == OPERATOR_SUBSTRACTION || this->value == OPERATOR_MULTIPLICATION || this->value == OPERATOR_DIVISION
        || this->value == OPERATOR_SIN || this->value == OPERATOR_COS)
    {
        return true;
    }
    return false;
}

bool CNode::isNumber() {
    if (isOperator() || value.empty()) {
        return false;
    }
    for (int i = 0; i < this->value.size(); i++) {
        if (!isdigit(this->value[i])) {
            return false;
        }
    }
    return true;
}

bool CNode::isVariable() {
    if (isOperator() || isNumber() || value.empty()) {
        return false;
    }
    return true;
}

// input

std::string CNode::insert(CTokenizer& tokenizer) {
    this->value = tokenizer.next();
    if (this->setType()) {
        tokenizer.appendErrorMessage(ERROR_VAR);
    }
    for (int i = 0; i < childCount; i++) {
        this->children[i].insert(tokenizer);
    }
    return tokenizer.hasMore() ? ERROR_TRIM : "";
}

std::string CNode::printLower() {
    std::string res = this->value;
    std::string tmp;
    for (int i = 0; i < this->childCount; i++) {
        tmp += " " + this->children[i].printLower();
    }
    return res + tmp;
}

void CNode::insertToVarlist(CVarList& list) {
    if (this->type == VARIABLE) {
        if (!list.insert(this->value)) {
            list.appendErrorMessage(ERROR_FILL);
        }
    }
    for (int i = 0; i < childCount; i++) {
        this->children[i].insertToVarlist(list);
    }
}

double CNode::comp(CVarList& list) {
    if (this->type == OPERATOR) {
        if (this->value == OPERATOR_ADDITION) {
            return this->children[0].comp(list) + this->children[1].comp(list);
        }
        if (this->value == OPERATOR_SUBSTRACTION) {
            return this->children[0].comp(list) - this->children[1].comp(list);
        }
        if (this->value == OPERATOR_MULTIPLICATION) {
            return this->children[0].comp(list) * this->children[1].comp(list);
        }
        if (this->value == OPERATOR_DIVISION) {
            double divisor = this->children[1].comp(list);
            if (divisor == 0) {
                list.appendErrorMessage(ERROR_DIV);
                CNode temp;
                temp.value = DEFAULT_FILL;
                temp.setType();
                return this->children[0].comp(list) / temp.comp(list);
            }
            return this->children[0].comp(list) / divisor;
        }
        if (this->value == OPERATOR_SIN) {
            return sin(this->children[0].comp(list));
        }
        if (this->value == OPERATOR_COS) {
            return cos(this->children[0].comp(list));
        }
    }
    return getValue(list);
}

double CNode::getValue(const CVarList& list) const {
    double val = 0;
    if (this->type == NUMBER) {
        std::stringstream ss(this->value);
        ss >> val;
    }
    else if (this->type == VARIABLE) {
        val = list.getValue(this->value);
    }
    return val;
}
