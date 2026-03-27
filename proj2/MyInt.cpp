//
// Created by kamil on 06/11/2025.
//

#include "MyInt.h"

MyInt::MyInt()
: x(0)
{}

MyInt::MyInt(int n) {
    x = n;
}

MyInt::~MyInt() {}

int MyInt::operator[](int n) {
    if (n>3) {return 0;}
    int binary[4];
    int copy = x;
    for (int i = 0; i < 4; i++) {
        binary[i] = copy%2;
        copy = copy/2;
    }
    return binary[n];
}
