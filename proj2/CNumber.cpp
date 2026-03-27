//
// Created by kamil on 26/10/2025.
//

#include "CNumber.h"
#include <algorithm>
#include <iostream>
#include <sstream>

CNumber::CNumber(): i_length(DEFAULT_LENGTH), pi_number(new int[DEFAULT_LENGTH]), b_positive(true) {}

CNumber::CNumber(const CNumber& other): i_length(DEFAULT_LENGTH), pi_number(new int[DEFAULT_LENGTH]), b_positive(true) {
    copy(other);
}

CNumber::CNumber(int len, bool positive = true): i_length(len), pi_number(new int[len]), b_positive(positive) {}

CNumber::~CNumber() {
    delete[] pi_number;
}

void CNumber::copy(const CNumber &other) {
    i_length = other.i_length;
    b_positive = other.b_positive;
    delete[] pi_number;
    pi_number = new int[i_length];
    for (int i = 0; i < i_length; i++)
        pi_number[i] = other.pi_number[i];
}


// operators with CNumbers

CNumber& CNumber::operator=(CNumber pcOther) {
    std::swap(i_length, pcOther.i_length);
    std::swap(pi_number, pcOther.pi_number);
    std::swap(b_positive, pcOther.b_positive);
    return *this;
}

CNumber CNumber::operator+(const CNumber &pcOther) const {
    CNumber first = *this;
    CNumber second = pcOther;
    if (first.b_positive != second.b_positive) {
        second.b_positive = true;
        return (first.b_positive) ? first - second : second - first;
    }
    if (second.getLength() > first.getLength()) {
        std::swap(first, second);
    }
    int table[first.getLength() + 1];
    int carry = 0;

    for (int i = 0; i < second.getLength(); i++) {
        table[i] = first.pi_number[i] + second.pi_number[i] + carry;
        carry = table[i] / NUMERAL_SYSTEM;
        table[i] %= NUMERAL_SYSTEM;
    }
    if (first.getLength() > second.getLength()) {
        for (int i = second.getLength(); i < first.getLength(); i++) {
            table[i] = first.pi_number[i] + carry;
            carry = table[i] / NUMERAL_SYSTEM;
            table[i] %= NUMERAL_SYSTEM;
        }
    }

    table[first.getLength()] = carry;
    int len = table[first.getLength()]>0 ? first.getLength()+1 : first.getLength();

    CNumber temp;

    temp.fromArray(table, len, b_positive);
    temp.trimLeadingZeros();

    return temp;
}

CNumber CNumber::operator-(const CNumber &pcOther) const {
    CNumber first = *this;
    CNumber second = pcOther;

    if (first.b_positive != second.b_positive) {
        if (first.b_positive) {
            second.b_positive = true;
        }
        else {
            first.b_positive = false;
        }
        return first + second;
    }


    CNumber temp;

    // we want it to be first - second
    if (second.getLength() > first.getLength() || (first.getLength() == second.getLength() && second.pi_number[second.getLength()-1] > first.pi_number[first.getLength()-1])) {
        std::swap(first, second);
        temp.b_positive = false;
    }
    int table[first.getLength()];
    int carry = 0;

    for (int i = 0; i < second.getLength(); i++) {
        table[i] = first.pi_number[i] - second.pi_number[i] - carry;
        if (table[i] < 0) {
            table[i] += NUMERAL_SYSTEM;
            carry = 1;
        }
        else {
            carry = 0;
        }
    }
    for (int i = second.getLength(); i<first.getLength(); i++) {
        table[i] = first.pi_number[i] - carry;
        carry = 0;
    }

    int len = first.getLength();
    while (len>1 && table[len-1] == 0) {
        len--;
    }

    temp.fromArray(table, len, temp.b_positive);
    temp.trimLeadingZeros();

    return temp;
}

CNumber CNumber::operator*(const CNumber &pcOther) const {
    CNumber first = *this;
    CNumber second = pcOther;
    CNumber temp;

    if (second.getLength() > first.getLength()) {
        std::swap(first, second);
    }

    int table[first.getLength() * 2];

    for (int i = 0; i < first.getLength()*2; i++) {
        table[i] = 0;
    }

    for (int i = 0; i < second.getLength(); i++) {
        for (int j = 0; j < first.getLength(); j++) {
            table[i+j] += first.pi_number[j] * second.pi_number[i];
        }
    }

    int carry = 0;
    for (int i = 0; i < first.getLength()*2; i++) {
        table[i] += carry;
        carry = table[i] / NUMERAL_SYSTEM;
        table[i] %= NUMERAL_SYSTEM;
    }

    int len = first.getLength()*2;
    while (len>1 && table[len-1] == 0) {
        len--;
    }

    if (temp.i_length == 1 && temp.pi_number[0] == 0) {
        temp.b_positive = true;
    }
    else temp.b_positive = this->b_positive==pcOther.b_positive;

    temp.fromArray(table, len, temp.b_positive);
    temp.trimLeadingZeros();

    return temp;
}

CNumber CNumber::operator/(const CNumber &pcOther) const {
    CNumber temp;

    if ((pcOther.getLength() == 1 && pcOther.pi_number[0] == 0) || absCompare(pcOther) == -1) {
        temp.setLength(1);
        temp.pi_number[0] = 0;
        return temp;
    }

    CNumber remaining = *this;

    int qlen = this->getLength() - pcOther.getLength() + 1;

    temp.setLength(qlen);
    for (int i = 0; i < qlen; ++i) temp.pi_number[i] = 0;

    CNumber divisor;

    for (int i = qlen - 1; i >= 0; --i) {
        divisor.setLength(pcOther.getLength() + i);
        for (int j = 0; j < pcOther.getLength() + i; ++j)
            divisor.pi_number[j] = (j < i) ? 0 : pcOther.pi_number[j - i];

        int low = 0, high = NUMERAL_SYSTEM - 1, n = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            CNumber fits = divisor * mid;
            if (fits.absCompare(remaining) <= 0) {
                n = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        remaining = remaining - divisor * n;
        temp.pi_number[i] = n;
    }

    temp.b_positive = this->b_positive==pcOther.b_positive;

    return temp;
}

// operators with ints

CNumber& CNumber::operator=(int iNewVal) {
    b_positive = iNewVal >= 0;
    int iTemp = abs(iNewVal);
    int len = 0;
    int copy = iTemp;
    while (copy > 0) {
        len++;
        copy /= NUMERAL_SYSTEM;
    }
    if (len == 0) {
        len = 1;
    }

    i_length = len;
    delete[] pi_number;
    pi_number = new int[len];

    for (int i = 0; i < len; i++) {
        pi_number[i] = (iTemp/power(NUMERAL_SYSTEM, i))%NUMERAL_SYSTEM;
    }

    return *this;
}

CNumber CNumber::operator+(int iNewVal) const {
    CNumber temp = iNewVal;
    return *this+temp;
}

CNumber CNumber::operator-(int iNewVal) const {
    CNumber temp = iNewVal;
    return *this-temp;
}

CNumber CNumber::operator*(int iNewVal) const {
    CNumber temp = iNewVal;
    return *this*temp;
}

CNumber CNumber::operator/(int iNewVal) const {
    CNumber temp = iNewVal;
    return *this/temp;
}


// setters and getters

int CNumber::getLength() const {
    return i_length;
}

int CNumber::getNumber() const {
    int iTemp = 0;
    for (int i = 0; i < i_length; i++) {
        iTemp += pi_number[i]*power(NUMERAL_SYSTEM, i);
    }
    if (!b_positive) iTemp *= -1;
    return iTemp;
}

std::string CNumber::sToStr() const {
    if (i_length == 0) return "";
    std::ostringstream oss("");
    if (!b_positive) {
        oss << "-";
    }
    for (int i = i_length-1; i >= 0; i--) {
        oss << pi_number[i];
    }
    return oss.str();
}

// private functions

bool CNumber::setLength(const int iNewVal) {
    if (iNewVal <= 0)
        return false;

    int* newTable = new int[iNewVal];
    for (int i = 0; i < iNewVal; i++) {
        if (i < i_length) newTable[i] = pi_number[i];
        else newTable[i] = 0;
    }


    delete[] pi_number;
    pi_number = newTable;
    i_length = iNewVal;

    return true;
}

void CNumber::trimLeadingZeros() {
    while (i_length > 1 && pi_number[i_length - 1] == 0)
        i_length--;
}

void CNumber::fromArray(const int* arr, int len, bool positive) {
    setLength(len);
    for (int i = 0; i < len; i++) {
        pi_number[i] = arr[i];
    }
    b_positive = positive;
}

int CNumber::absCompare(const CNumber &pcOther) const {
    if (this->getLength() == pcOther.getLength()) {
        for (int i = this->getLength()-1; i>=0; i--) {
            if (this->pi_number[i] != pcOther.pi_number[i]) {
                return this->pi_number[i] > pcOther.pi_number[i] ? 1 : -1;
            }
        }
        return 0;
    }
    return this->getLength() > pcOther.getLength() ? 1 : -1;
}

int power(const int base, const int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// modification

MyInt CNumber::operator[](int iIndex) const {
    MyInt n(pi_number[iIndex]);
    return n;
}