//
// Created by tuli on 24/11/2020.
//

#ifndef HW2_KING_H
#define HW2_KING_H


#include "ChessTool.h"

class King : public ChessTool{
public:
    explicit King (bool col, Location loc);// : ChessTool(col, loc) { }
    ~King(){}
    King (const ChessTool& other) : super(other){}
    ostream & put(ostream &os) const;
    Vect Route(const Location &dst);
    Vect Route(const Location &dst, bool flag);
private:
    typedef  ChessTool super;

};


#endif //HW2_KING_H
