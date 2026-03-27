#include <iostream>
#include "CNumber.h"

int main() {
    CNumber *number = new CNumber();
    CNumber *number2 = new CNumber();
    CNumber *res = new CNumber();

    *number = 75;
    *number2 = 12;

    *res = *number + *number2;
    std::cout << res->sToStr()<< std::endl;
    *res = *number - *number2;
    std::cout << res->sToStr()<< std::endl;
    *res = *number * *number2;
    std::cout << res->sToStr()<< std::endl;
    *res = *number / *number2;
    std::cout << res->sToStr()<< std::endl;

    std::cout << std::endl;

    *number = 6;
    *number2 = -12;

    *res = *number + *number2;
    std::cout << res->sToStr() << std::endl;
    *res = *number - *number2;
    std::cout << res->sToStr() << std::endl;
    *res = *number * *number2;
    std::cout << res->sToStr() << std::endl;
    *res = *number / *number2;
    std::cout << res->sToStr() << std::endl;

    std::cout << std::endl;

    *number = -9;
    *number2 = 0;

    *res = *number + *number2;
    std::cout << res->sToStr() << std::endl;
    *res = *number - *number2;
    std::cout << res->sToStr() << std::endl;
    *res = *number * *number2;
    std::cout << res->sToStr() << std::endl;
    *res = *number / *number2;
    std::cout << res->sToStr() << std::endl;

    std::cout << std::endl;

    delete number;
    delete res;

    return 0;
}