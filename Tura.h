//
// Created by tuli on 24/11/2020.
//

#ifndef HW2_TURA_H
#define HW2_TURA_H


#include "ChessTool.h"

class Tura : public ChessTool {
public:
    ~Tura() {}
    Vect Route(const Location &dst);
    Vect Route(const Location &dst, bool flag);
    Tura (bool col, Location loc) : ChessTool(col, loc, 'r') { }
    Tura (const ChessTool& other) : super(other){}
    ostream& put(ostream &os) const;
private:
    typedef  ChessTool super;

};



#endif //HW2_TURA_H
