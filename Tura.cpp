//
// Created by tuli on 24/11/2020.
//

#include "Tura.h"
ostream& Tura::put(ostream &os) const {
    if (!whatColor()) os << "r";
    else os << "R" ;
    return os;
}

Vect Tura::Route(const Location &dst) {
    int d = dst.value();
    int sr = getLoc().value();

    Vect moves = checkCol(sr, d);
    return moves;
}

Vect Tura::Route(const Location &dst,  bool flag) { //tura moves same if eats
    return Route(dst);
}
