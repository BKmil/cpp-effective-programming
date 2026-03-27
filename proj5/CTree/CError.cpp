//
// Created by kamil on 09/12/2025.
//

#include "CError.h"

CError::CError(const std::string &desc): description(desc) {}

std::string CError::sGetDescription() {
    return this->description;
}