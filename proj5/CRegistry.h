//
// Created by kamil on 15/01/2026.
//

#ifndef PROJ5_CREGISTRY_H
#define PROJ5_CREGISTRY_H
#include <vector>


class CRegistry {
    std::vector<void*> addresses;
    std::vector<int> numbers;
public:
    void append(void* address);
    int getNumber(void* address);
    void remove(void* address);
    void dec(void* address);
};


#endif //PROJ5_CREGISTRY_H