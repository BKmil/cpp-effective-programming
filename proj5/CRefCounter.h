//
// Created by kamil on 11/01/2026.
//

#ifndef PROJ5_CREFCOUNTER_H
#define PROJ5_CREFCOUNTER_H


class CRefCounter
{
public:
    CRefCounter();
    int iAdd();
    int iDec();
    int iGet() const;
private:
    int i_count;
};


#endif //PROJ5_CREFCOUNTER_H