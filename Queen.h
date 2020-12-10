//
// Created by tuli on 24/11/2020.
//

#ifndef HW2_QUEEN_H
#define HW2_QUEEN_H


#include "ChessTool.h"

class Queen : public ChessTool{
public:
    ~Queen(){}
    Vect Route(const Location &dst);
    Vect Route(const Location &dst, bool flag);
    ostream& put(ostream &os) const;
    Queen (bool col, Location loc) : ChessTool(col, loc, 'q') { }
     Queen (const ChessTool& other) : super(other){}
private:
    typedef  ChessTool super;

};


#endif //HW2_QUEEN_H
