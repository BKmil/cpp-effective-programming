//
// Created by kamil on 23/11/2025.
//

#ifndef PROJ3_CONSTANTS_H
#define PROJ3_CONSTANTS_H

#include <string>

const std::string DEFAULT_FILL = "1";

// OPERATORS

const std::string OPERATOR_ADDITION = "+";
const std::string OPERATOR_SUBSTRACTION = "-";
const std::string OPERATOR_MULTIPLICATION = "*";
const std::string OPERATOR_DIVISION = "/";
const std::string OPERATOR_SIN = "sin";
const std::string OPERATOR_COS = "cos";

// ERRORS

const std::string ERROR_TRIM = "Provided too much arguments! Trimming the expression.\n";
const std::string ERROR_ARGS = "Provided too much arguments! Using only the needed amount.\n";
const std::string ERROR_FILL = "Wrong amount of ints! Remaining fields filled with the value: " + DEFAULT_FILL + ".\n";
const std::string ERROR_VAR = "Wrong variable name detected! Naming fixed.\n";
const std::string ERROR_DIV = "Division by 0! Result of the branch fixed to the value: " + DEFAULT_FILL + ".\n";

#endif //PROJ3_CONSTANTS_H