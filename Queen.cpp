//
// Created by tuli on 24/11/2020.
//

#include "Queen.h"
ostream& Queen::put(ostream &os) const {
    if (!whatColor()) os << "q";
    else os <<"Q" ;
    return os;
}

Vect Queen::Route(const Location &dst) {
    int d = dst.value();
    int sr = getLoc().value();
    Vect col = checkCol(sr, d);
    if (!col.size()){
    return checkDiag(sr, d);
    }
    return col;

}

Vect Queen::Route(const Location& dst, bool flag)
{
    return Route(dst);
}
