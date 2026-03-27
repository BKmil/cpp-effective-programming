//
// Created by kamil on 23/11/2025.
//

#ifndef PROJ3_CTOKENIZER_H
#define PROJ3_CTOKENIZER_H

#include <vector>
#include <string>

#include "CErrorMessage.h"

class CTokenizer {
    std::vector<std::string> tokens;
    int pos;
    CErrorMessage err;

    public:
    CTokenizer();
    void insert(const std::string &str);

    std::string next();
    bool hasMore();
    bool atEnd();

    std::vector<int> asIntList();

    void clearErrorMessage();
    void appendErrorMessage(const std::string &str);
    std::string getErrorMessage() const;
};


#endif //PROJ3_CTOKENIZER_H