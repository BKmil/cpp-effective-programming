#ifndef PROJ1_CTABLE_H
#define PROJ1_CTABLE_H
#include <string>

class CTable {
    private:
    std::string s_name;
    int *pcTable;
    int length;

    static const int DEFAULT_TABLE_LENGTH;
    static const std::string DEFAULT_NAME;

    public:
    CTable();
    CTable (std::string sName, int iTableLen);
    CTable (const CTable &pcOther);

    ~CTable();

    bool bSetValue(int elementNumber, int value);
    int iGetValue(int elementNumber);
    int iGetLength();

    void vSetName(std::string sName);
    bool bSetNewSize(int iTableLen);

    CTable *pcClone();

    CTable cutOut(int position, int size);
};

void v_mod_tab(CTable *pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);


#endif //PROJ1_CTABLE_H