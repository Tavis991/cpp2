//
// Created by tuli on 24/11/2020.
//

#ifndef HW2_BISHOP_H
#define HW2_BISHOP_H

#include "ChessTool.h"

class Bishop : public ChessTool{
public:
    Vect Route(const Location &dst);
    Vect Route(const Location &dst, bool flag) ;
    ostream& put(ostream &os) const;
    ~Bishop(){}
    Bishop (bool col, Location loc) : ChessTool(col, loc, 'b') { }
    Bishop (const ChessTool& other) : super(other){}
private:
    typedef  ChessTool super;

};
#endif //HW2_BISHOP_H
