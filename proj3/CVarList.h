//
// Created by kamil on 22/11/2025.
//

#ifndef PROJ3_CVARLIST_H
#define PROJ3_CVARLIST_H

#include <vector>
#include <string>

#include "CErrorMessage.h"

class CVarList {
    bool insert(const std::vector<int> &values);
    CErrorMessage err;

    public:
    std::vector<std::string> variables;
    std::vector<int> values;

    bool insert(const std::string &var);

    bool insertInts(const std::string &str);

    int getValue(const std::string &var) const;

    std::string toString() const;

    void clearErrorMessage();
    void appendErrorMessage(const std::string &str);
    std::string getErrorMessage() const;
};


#endif //PROJ3_CVARLIST_H