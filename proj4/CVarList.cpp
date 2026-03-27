//
// Created by kamil on 22/11/2025.
//

#include "CVarList.h"

#include <sstream>

#include "constants.h"
#include "CTokenizer.h"

bool CVarList::insert(const std::string &var) {
    for (int i = 0; i < variables.size(); i++) {
        if (variables[i] == var)
            return false;
    }
    variables.push_back(var);
    return true;
}

bool CVarList::insert(const std::vector<int> &val) {
    this->values.clear();
    bool ifCorrect = true;

    for (int i = 0; i < variables.size(); i++) {
        if (i<val.size()) {
            this->values.push_back(val[i]);
        }
        else {
            this->values.push_back(1);
            ifCorrect = false;
        }
    }

    if (val.size() > variables.size()) {
        appendErrorMessage(ERROR_ARGS);
    }

    return ifCorrect;
}

bool CVarList::insertInts(const std::string &str) {
    CTokenizer tokenizer;
    tokenizer.insert(str);
    std::vector<int> val = tokenizer.asIntList();
    return insert(val);
}

int CVarList::getValue(const std::string &var) const {
    for (int i = 0; i < variables.size(); i++) {
        if (variables[i] == var) {
            return values[i];
        }
    }
    return -1;
}

std::string CVarList::toString() const {
    std::stringstream ss("");
    for (int i = 0; i < variables.size(); i++) {
        ss << variables[i]<<" ";
    }
    return ss.str();
}

void CVarList::appendErrorMessage(const std::string &str) {
    this->err.appendErrorMessage(str);
}

void CVarList::clearErrorMessage() {
    this->err.clearErrorMessage();
}

std::string CVarList::getErrorMessage() const {
    return this->err.getErrorMessage();
}