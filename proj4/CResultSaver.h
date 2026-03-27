//
// Created by kamil on 09/12/2025.
//

#ifndef PROJ4_CRESULTSAVER_H
#define PROJ4_CRESULTSAVER_H

#include <string>
#include <fstream>
#include "CError.h"
#include "CResult.hpp"
#include "CTree.h"

class CResultSaver {
public:
    template<typename T>
    static void save(const CResult<T, CError>& result, const std::string& filename);

    static void save(const CResult<void, CError>& result, const std::string& filename);

    static void save(const CResult<CTree*, CError>& result, const std::string& filename);
};


#endif //PROJ4_CRESULTSAVER_H