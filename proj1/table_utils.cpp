#include "table_utils.h"
#include <iostream>

void v_alloc_table_fill_34(int iSize) { // not recommended method, containing a so-called magic number
    if (iSize <= 0) {
        std::cout<<"Invalid table size: "<<iSize<<std::endl;
        return;
    }

    const int FILL_VALUE = 34;

    int *piTable = new int[iSize];

    for (int i = 0; i < iSize; i++) {
        piTable[i] = FILL_VALUE;
    }

    std::cout<<"Created table: "<<piTable<<std::endl;

    for (int i = 0; i < iSize; i++) {
        std::cout<<piTable[i]<<" ";
    }
    std::cout<<std::endl;

    delete[] piTable;
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeX <= 0 || iSizeY <= 0) {
        return false;
    }

    *piTable = new int*[iSizeX];

    for (int i = 0; i < iSizeX; i++) {
        (*piTable)[i] = new int[iSizeY];

        for (int j = 0; j < iSizeY; j++) {
            (*piTable)[i][j] = 0;
        }
    }

    return true;
}

bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) { // iSizeY is not needed, it is not used
    if (!piTable || !*piTable || iSizeX <= 0 || iSizeY <= 0) {
        return false;
    }

    for (int i = 0; i < iSizeX; i++) {
        delete[] (*piTable)[i];
    }

    delete[] (*piTable);

    return true;
}