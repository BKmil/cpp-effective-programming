//
// Created by kamil on 23/11/2025.
//

#include "CTokenizer.h"
#include "constants.h"

#include <sstream>

CTokenizer::CTokenizer(): pos(0) {}

void CTokenizer::insert(const std::string &str) {
    tokens.clear();
    pos = 0;

    std::stringstream ss(str);
    std::string token;

    while (ss >> token) {
        tokens.push_back(token);
    }
}

std::string CTokenizer::next() {
    if (hasMore()) {
        std::string token = tokens[pos];
        pos++;
        return token;
    }
    appendErrorMessage(ERROR_FILL);
    return DEFAULT_FILL;
}

bool CTokenizer::hasMore() {
    return pos < tokens.size();
}

bool CTokenizer::atEnd() {
    return pos >= tokens.size() - 1;
}

std::vector<int> CTokenizer::asIntList() {
    std::vector<int> values;
    for (int i = 0; i < tokens.size(); i++) {
        std::stringstream ss(tokens[i]);
        int num;
        if (ss >> num) {
            values.push_back(num);
        }
    }
    return values;
}

void CTokenizer::appendErrorMessage(const std::string &str) {
    this->err.appendErrorMessage(str);
}

void CTokenizer::clearErrorMessage() {
    this->err.clearErrorMessage();
}

std::string CTokenizer::getErrorMessage() const {
    return this->err.getErrorMessage();
}
