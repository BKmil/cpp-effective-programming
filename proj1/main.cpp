#include <iostream>
#include "table_utils.h"
#include "CTable.h"

int main() {
    // // table_utils
    //
    // v_alloc_table_fill_34(5);
    //
    // int **pi_table;
    // if (b_alloc_table_2_dim(&pi_table, 5, 3)) {
    //     std::cout<<"Created table: "<<pi_table<<std::endl;
    //     for (int i = 0; i < 5; i++) {
    //         for (int j = 0; j < 3; j++) {
    //             std::cout << pi_table[i][j] << " ";
    //         }
    //         std::cout<<std::endl;
    //     }
    // }
    //
    // if (b_dealloc_table_2_dim(&pi_table, 5, 3)) {
    //     std::cout<<"Deallocated table: "<<pi_table<<std::endl;
    // }
    //
    // // CTable
    // std::cout<<std::endl<<std::endl;
    //
    // CTable *newTable = new CTable();
    // CTable *copyTable = new CTable(*newTable);
    //
    // delete newTable;
    // delete copyTable;
    //
    // CTable *newTable2 = new CTable("Table2", 4);
    // CTable *copyTable2 = newTable2->pcClone();
    //
    // delete newTable2;
    //
    // std::cout<<copyTable2->bSetNewSize(-10)<<std::endl;
    // std::cout<<copyTable2->bSetNewSize(7)<<std::endl;
    //
    // copyTable2->vSetName("ChangedTable");
    //
    // delete copyTable2;
    //
    // // v_mod_tab procedures
    //
    // std::cout<<std::endl<<std::endl;
    //
    // CTable *modTable = new CTable("modTable", 4);
    //
    // v_mod_tab(modTable, 8);
    //
    // delete modTable;
    //
    // CTable *modTableNotWorking = new CTable("modTable2", 4);
    //
    // v_mod_tab(*modTableNotWorking, 8);
    //
    // delete modTableNotWorking;

    // tests after modifications

    CTable *table = new CTable("Sample Table", 20);

    for (int i = 0; i < table->iGetLength(); i++) {
        table->bSetValue(i, i);
    }

    for (int i = 0; i < table->iGetLength(); i++) {
        std::cout << table->iGetValue(i) << std::endl;
    }

    std::cout<<std::endl<<std::endl;

    CTable table2 = table->cutOut(6, 7);

    for (int i = 0; i < table->iGetLength(); i++) {
        std::cout << table->iGetValue(i) << std::endl;
    }

    std::cout<<std::endl<<std::endl;

    for (int i = 0; i < table2.iGetLength(); i++) {
        std::cout << table2.iGetValue(i) << std::endl;
    }

    delete table;
}