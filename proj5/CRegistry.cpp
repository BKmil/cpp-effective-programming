//
// Created by kamil on 15/01/2026.
//

#include "CRegistry.h"


void CRegistry::append(void* address) {
    for (int i = 0; i < addresses.size(); i++) {
        if (addresses[i] == address) {
            numbers[i]+=1;
            return;
        }
    }
    addresses.push_back(address);
    numbers.push_back(1);
}

int CRegistry::getNumber(void* address) {
    for (int i = 0; i < addresses.size(); i++) {
        if (addresses[i] == address) {
            return i;
        }
    }
    return -1;
}

void CRegistry::remove(void* address) {
    for (int i = 0; i < addresses.size(); i++) {
        if (addresses[i] == address) {
            addresses.erase(addresses.begin() + i);
            numbers.erase(numbers.begin() + i);
        }
    }
}

void CRegistry::dec(void* address) {
    for (int i = 0; i < addresses.size(); i++) {
        if (addresses[i] == address) {
            numbers[i]--;
        }
    }
}