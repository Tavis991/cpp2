//
// Created by tuli on 24/11/2020.
//

#ifndef HW2_KNIGHT_H
#define HW2_KNIGHT_H

#include "ChessTool.h"

class Knight : public ChessTool{
public:
    ~Knight() {}
    Vect Route(const Location &dst);
     Vect Route(const Location &dst, bool flag);
     ostream & put(ostream &os) const;
     Knight (bool col, Location loc) : ChessTool(col, loc, 'n') { }
      Knight (const ChessTool& other) : super(other){}

private:
    typedef  ChessTool super;

};


#endif //HW2_KNIGHT_H
