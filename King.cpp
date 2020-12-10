//
// Created by tuli on 24/11/2020.
//

#include "King.h"



Vect King::Route(const Location &dst) {
    Vect moves(1);
    int d = dst.value();
    int sr = getLoc().value();
    int arr [] = {sr + (8 +1), sr + ( 1), sr + (-1 ), sr + (8 - 1), sr - (8 +1), sr + (8), sr - (8), sr - (8 - 1)};
    for (int i=0; i<8; i++) {
    if (d == arr[i]) {
     moves.push(d); return moves; }
    }

    if (!hasMoved)
        {
        if  ( (d - sr) == 2)  {
            while ( d > sr ){
            moves.push(++sr);
            }

        }
        else if ( (d - sr) == -3)
        {
            while ( d < sr ){
            moves.push(--sr);
            }
        }

    }



    return moves;
}

King::King (bool col, Location loc) : super(col, loc, 'k'){
//moves.push(A1);
}
ostream& King::put(ostream &os) const {
    if (!whatColor()) os << "k";
    else os << "K";
    return os;
}

Vect King::Route(const Location& dst, bool flag)
    {
       return Route(dst);
    }

