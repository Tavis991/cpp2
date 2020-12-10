//
// Created by tuli on 24/11/2020.
//

#include "Bishop.h"




ostream& Bishop::put(ostream &os) const {
    if (!whatColor()) os << "b";
    else os <<"B" ;
    return os;
}


Vect Bishop::Route(const Location& dst)
{
    int d = dst.value();
    int sr = getLoc().value();
    Vect moves = checkDiag(sr, d);
    return moves;
}

 Vect Bishop::Route(const Location& dst, bool flag)
{
    return Route(dst);
}
