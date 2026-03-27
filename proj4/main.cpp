#include <iostream>

#include "CInterface.h"
#include "CTreeCreator.h"
#include "CResultSaver.h"
#include "CResult.hpp"

int main() {
    CInterface interface;

    CResultSaver::save(createTree("* 1 / 6 7"), "treeoutput1.txt");
    CResultSaver::save(createTree("* 1 2 3"), "treeoutput2.txt");
    CResultSaver::save(createTree("/ 4"), "treeoutput3.txt");

    char message[] = "Hello world";
    std::string error_code = "Error";

    CResult<std::string, std::string> cMessageOk= CResult<char*, std::string>::cOk(message);
    CResult<std::string, std::string> cMessageFail= CResult<char*, std::string>::cFail(&error_code);

    std::cout<<cMessageOk.cGetValue()<<std::endl;
    std::cout<<*
        cMessageFail.vGetErrors()[0]<<std::endl;

    return 0;
}
