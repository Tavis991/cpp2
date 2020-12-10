//
// Created by tuli on 24/11/2020.
//

#include <cstdlib>
#include <iostream>
#include "Location.h"

//Location::Location(char e, unsigned int i) : E(0), I(0) {}

int Location::value() const {
    return pos;
}


Location::Location(string S)   //string constructor can treat location as string
    {
    bool flag = false;
    for (int i=0; i<8; i++){ if (S[0] == 'A'+i) flag = true;}
    if (!flag) throw "out of bounds";
    flag = false;
    char T = 0;
    T += S[0] - 'A';

    for (int i=0; i<8; i++){ if (S[1] == '1'+i) flag = true;}
    if (!flag) throw "out of bounds";
    T += (7 - (S[1]-'1')) * 8  ;            //this is calculation of chessboard indexing to c++ array
    pos = T;
    }

Location::Location(int i) : pos(i)
{}

Location &Location::operator= (const Location &rhs) {
    if (this == &rhs) return *this;
    else this->pos = rhs.pos;
    return *this;
}

bool Location::operator > (const Location& rhs){
    return pos>rhs.pos;
}

