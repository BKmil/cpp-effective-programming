//
// Created by kamil on 11/01/2026.
//

#include "CRefCounter.h"

CRefCounter::CRefCounter(): i_count(0) {}

int CRefCounter::iAdd() {return ++i_count;}
int CRefCounter::iDec() {return --i_count;}

int CRefCounter::iGet() const {return i_count;}
