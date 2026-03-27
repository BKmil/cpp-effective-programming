#include <iostream>
#include <ostream>

#include "CMySmartPointer.hpp"

int main() {
    int* x = new int(7);
    CMySmartPointer<int> x1(x);
    CMySmartPointer<int> x2(x1);
    std::cout << *x2 << std::endl;
    CMySmartPointer<int> x3(x);
    std::cout << *x3 << std::endl;


}