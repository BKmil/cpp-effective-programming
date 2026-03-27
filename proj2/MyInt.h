//
// Created by kamil on 06/11/2025.
//

#ifndef PROJ2_MYINT_H
#define PROJ2_MYINT_H


class MyInt {
public:
    MyInt();
    MyInt(int n);
    ~MyInt();
    int x;

    int operator[](int n);
};


#endif //PROJ2_MYINT_H