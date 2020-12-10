//
// Created by tuli on 24/11/2020.
//

#ifndef HW2_PAWN_H
#define HW2_PAWN_H


#include "ChessTool.h"

class Pawn : public ChessTool{
public:
     ostream & put(ostream &os) const;
     Vect Route(const Location &dst);
     Vect Route(const Location &dst, bool flag);
     ~Pawn(){}
     Pawn (const ChessTool& other) : super(other){}
     Pawn (bool col, Location loc) : ChessTool(col, loc, 'p') {  }


private:
    typedef  ChessTool super;

};



#endif //HW2_PAWN_H
