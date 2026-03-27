//
// Created by kamil on 09/12/2025.
//

#ifndef PROJ4_CERROR_H
#define PROJ4_CERROR_H
#include <string>


class CError {
    std::string description;

public:
    CError(const std::string& desc);
    std::string sGetDescription();
};


#endif //PROJ4_CERROR_H