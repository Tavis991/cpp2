//
// Created by tuli on 24/11/2020.
//

#include "Knight.h"

ostream& Knight::put(ostream &os) const {
    if (!whatColor()) os << "n";
    else os <<"N" ;
    return os;
}

Vect Knight::Route(const Location &dst) {
    Vect moves(1);
    int d = dst.value();
    int sr = getLoc().value();
    int arr [] = {sr + (8*2 +1), sr + (8 + 2), sr + (8 - 2), sr + (8*2 - 1), sr - (8*2 +1), sr - (8 + 2), sr - (8 - 2), sr - (8*2 - 1)};
    for (int i=0; i<8; i++) {
    if (d == arr[i]) {  moves.push(d); return moves; }
    }
    return moves;
}

Vect Knight::Route(const Location& dst, bool flag)
{
  return Route(dst);
}
//bool Knight::inReach(const Location &gr) {
//   return ChessTool::inReach(gr);
//}
