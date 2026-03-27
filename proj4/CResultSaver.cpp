//
// Created by kamil on 09/12/2025.
//

#include "CResultSaver.h"


void CResultSaver::save(const CResult<void, CError>& result, const std::string& filename) {
    std::ofstream out(filename.c_str());
    if (!out) {
        return;
    }

    if (result.bIsSuccess()) {
        out << "Success" << std::endl;
    } else {
        std::vector<CError*> errors = result.vGetErrors();
        for (size_t i = 0; i < errors.size(); i++) {
            if (errors[i]) {
                out << "Error: " << errors[i]->sGetDescription() << std::endl;
            }
        }
    }
    out.close();
}

void CResultSaver::save(const CResult<CTree*, CError>& result, const std::string& filename) {
    std::ofstream out(filename.c_str());
    if (!out) {
        return;
    }

    if (!result.bIsSuccess()) {
        std::vector<CError*> errors = result.vGetErrors();
        for (size_t i = 0; i < errors.size(); i++) {
            if (errors[i]) {
                out << "Error: " << errors[i]->sGetDescription() << std::endl;
            }
        }
    } else {
        CTree* tree = result.cGetValue();
        out << tree->print() << std::endl;
    }

    out.close();
}