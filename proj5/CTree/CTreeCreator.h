//
// Created by kamil on 09/12/2025.
//

#ifndef PROJ4_CTREECREATOR_H
#define PROJ4_CTREECREATOR_H
#include "CError.h"
#include "CResult.hpp"
#include "CTree.h"


CResult<CTree*, CError> createTree(const std::string& formula);

#endif //PROJ4_CTREECREATOR_H