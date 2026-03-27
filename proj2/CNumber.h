//
// Created by kamil on 26/10/2025.
//

#ifndef PROJ2_CNUMBER_H
#define PROJ2_CNUMBER_H
#include <string>

#include "MyInt.h"


class CNumber {
    int i_length;
    int *pi_number;
    bool b_positive;

    static const int NUMERAL_SYSTEM = 10;
    static const int DEFAULT_LENGTH = 1;

    bool setLength(int iNewVal);

    void trimLeadingZeros();
    void fromArray(const int* arr, int len, bool positive);
    int absCompare(const CNumber &pcOther) const;

public:
    CNumber();
    CNumber(const CNumber& other);
    CNumber(int len, bool positive);
    ~CNumber();

    void copy(const CNumber& other);

    CNumber& operator=(CNumber pcOther);
    CNumber operator+(const CNumber &pcOther) const;
    CNumber operator*(const CNumber &pcOther) const;
    CNumber operator-(const CNumber &pcOther) const;
    CNumber operator/(const CNumber &pcOther) const;

    CNumber& operator=(int iNewVal);
    CNumber operator+(int iNewVal) const;
    CNumber operator*(int iNewVal) const;
    CNumber operator-(int iNewVal) const;
    CNumber operator/(int iNewVal) const;

    MyInt operator[](int iNewVal) const;

    int getLength() const;
    int getNumber() const;
    std::string sToStr() const;
};

int power(int base, int exp);

#endif //PROJ2_CNUMBER_H