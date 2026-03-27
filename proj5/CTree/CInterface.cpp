//
// Created by kamil on 23/11/2025.
//

#include "CInterface.h"

#include <iostream>
#include <sstream>

CInterface::CInterface(): tree(new CTree()) {};

CInterface::~CInterface() {
    delete tree;
}

void CInterface::stream() {
    std::string line;
    std::string cmd;

    while (cmd != "exit") {
        std::cout << ">>>";

        std::getline(std::cin, line);
        std::stringstream ss(line);
        cmd = "";
        ss >> cmd;

        if (cmd == "enter") {
            std::string arg;
            std::getline(ss, arg);
            enter(arg);
        }
        else if (cmd == "vars") {
            vars();
        }
        else if (cmd == "print") {
            print();
        }
        else if (cmd == "comp") {
            std::string arg;
            std::getline(ss, arg);
            comp(arg);
        }
        else if (cmd == "join") {
            std::string arg;
            std::getline(ss, arg);
            join(arg);
        }
        else if (cmd == "exit") {
            std::cout << "Goodbye!\n";
        }
        else {
            std::cout << "Unknown command: " << cmd << "\n";
        }
    }
}

void CInterface::enter(const std::string &arg) {
    std::cout<<"Entering: "<<arg<<"\n";
    std::cout<<tree->insert(arg);
}

void CInterface::vars() {
    std::cout<<"Vars: ";
    std::cout<<tree->varList().toString()<<"\n";
}

void CInterface::print() {
    std::cout<<"Printing:"<<"\n";
    std::cout<<tree->print()<<"\n";
}

void CInterface::comp(const std::string &arg) {
    std::cout<<"Comp: "<<tree->comp(arg)<<"\n";
}

void CInterface::join(const std::string &arg) {
    std::cout<<"Joining: "<<arg<<"\n";
    CTree newTree;
    std::cout<<newTree.insert(arg);
    *tree = *tree + newTree;
}