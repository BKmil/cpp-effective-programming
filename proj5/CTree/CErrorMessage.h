//
// Created by kamil on 24/11/2025.
//

#ifndef PROJ3_CERRORMESSAGE_H
#define PROJ3_CERRORMESSAGE_H
#include <string>


class CErrorMessage {
    bool fill_error;
    bool var_error;
    bool trim_error;
    bool div_error;
    bool args_error;

    public:

    CErrorMessage();

    void appendErrorMessage(std::string str);
    void clearErrorMessage();

    std::string getErrorMessage() const;
};


#endif //PROJ3_CERRORMESSAGE_H