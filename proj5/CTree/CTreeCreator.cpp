//
// Created by kamil on 09/12/2025.
//

#include "CTreeCreator.h"

CResult<CTree*, CError> createTree(const std::string& formula) {
    std::vector<CError*> errors;

    CTree* tree = new CTree();

    std::string insertResult = tree->insert(formula);

    if (!insertResult.empty()) {
        errors.push_back(new CError(insertResult));
        delete tree;
        return CResult<CTree*, CError>(errors);
    }

    return CResult<CTree*, CError>(tree);
}
