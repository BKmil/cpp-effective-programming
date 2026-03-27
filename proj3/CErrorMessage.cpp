//
// Created by kamil on 24/11/2025.
//

#include "CErrorMessage.h"

#include <complex>

#include "constants.h"

CErrorMessage::CErrorMessage(): fill_error(false), var_error(false), trim_error(false), div_error(false), args_error(false) {}


void CErrorMessage::appendErrorMessage(std::string str) {
    if (str == ERROR_FILL) {
        fill_error = true;
    }
    else if (str == ERROR_VAR) {
        var_error = true;
    }
    else if (str == ERROR_TRIM) {
        trim_error = true;
    }
    else if (str == ERROR_DIV) {
        div_error = true;
    }
    else if (str == ERROR_ARGS) {
        args_error = true;
    }
}

void CErrorMessage::clearErrorMessage() {
    fill_error = false;
    var_error = false;
    trim_error = false;
    div_error = false;
    args_error = false;
}

std::string CErrorMessage::getErrorMessage() const {
    std::string result;
    result += var_error ? ERROR_VAR : "";
    result += fill_error ? ERROR_FILL : "";
    result += trim_error ? ERROR_TRIM : "";
    result += div_error ? ERROR_DIV : "";
    result += args_error ? ERROR_ARGS : "";
    return result;
}
