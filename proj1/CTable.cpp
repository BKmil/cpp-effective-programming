#include "CTable.h"

#include <iostream>
#include <ostream>
#include <string>

const std::string CTable::DEFAULT_NAME = "Table";
const int CTable::DEFAULT_TABLE_LENGTH = 0;

CTable::CTable() : s_name(DEFAULT_NAME), length(DEFAULT_TABLE_LENGTH), pcTable(new int[DEFAULT_TABLE_LENGTH]) {
    std::cout<<"nonp: "<<s_name<<std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
    s_name = sName;
    if (iTableLen <= 0) {
        length = DEFAULT_TABLE_LENGTH;
    }
    else {
        length = iTableLen;

    }
    pcTable = new int[iTableLen];
    for (int i = 0; i < length; i++) {
        pcTable[i] = 0;
    }
    std::cout<<"parameter: "<<s_name<<std::endl;
}

CTable::CTable(const CTable &pcOther) {
    this->s_name = pcOther.s_name+"_copy";
    this->length = pcOther.length;
    this->pcTable = new int[length];
    for (int i = 0; i < length; i++) pcTable[i] = pcOther.pcTable[i];
    std::cout<<"copy: "<<s_name<<std::endl;
}

CTable::~CTable() {
    delete[] pcTable;
    std::cout<<"deleting: "<<s_name<<std::endl;
}

int CTable::iGetValue(int elementNumber) {
    if (elementNumber >= length || elementNumber < 0) return -1;
    return pcTable[elementNumber];
}

int CTable::iGetLength() {
    return length;
}

bool CTable::bSetValue(int elementNumber, int value) {
    if (elementNumber < 0 || elementNumber >= length) return false;
    pcTable[elementNumber] = value;
    return true;
}

void CTable::vSetName(std::string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen <= 0)
        return false;

    int* newTable = new int[iTableLen];
    for (int i = 0; i < iTableLen; i++) {
        if (i < length) newTable[i] = pcTable[i];
        else newTable[i] = 0;
    }


    delete[] pcTable;
    pcTable = newTable;
    length = iTableLen;

    return true;
}

CTable *CTable::pcClone() {
    CTable *newTable = new CTable(*this);
    return newTable;
}

CTable CTable::cutOut(int position, int size) {
    if (position < 0 || size < 0 || position + size >= this->length) return CTable();
    CTable temp = CTable(this->s_name+"_cutout", size);
    for (int i = position; i < this->length; i++) {
        if (i < position + size)
            temp.pcTable[i-position] = this->pcTable[i];
        this->pcTable[i] = this->pcTable[i + size];
    }

    this->bSetNewSize(this->length - size);

    return temp;
}

void v_mod_tab(CTable *pcTab, int iNewSize) {  // object modified
    pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) { // creates a copy, object is not modified
    cTab.bSetNewSize(iNewSize);
}
