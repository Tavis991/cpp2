//
// Created by tuli on 24/11/2020.
//

#ifndef HW2_LOCATION_H
#define HW2_LOCATION_H

#include <string>

enum Pos// Squares
{
    A8 = 0, B8, C8, D8, E8, F8, G8, H8,
    A7 = 8, B7, C7, D7, E7, F7, G7, H7,
    A6 = 16, B6, C6, D6, E6, F6, G6, H6,
    A5 = 24, B5, C5, D5, E5, F5, G5, H5,
    A4 = 32, B4, C4, D4, E4, F4, G4, H4,
    A3 = 40, B3, C3, D3, E3, F3, G3, H3,
    A2 = 48, B2, C2, D2, E2, F2, G2, H2,
    A1 = 56, B1, C1, D1, E1, F1, G1, H1
};

using namespace std;

class Location { //location is father of gridsquare
public:
    Location():pos(-1) { }
    explicit Location( int pos);
    explicit Location(string S);
    Location (const Location & other) : pos(other.pos) {} // SOMEWHERE MAKE SEGMENTATRION
    Location& operator= (const Location& rhs);
    bool operator == (const Location& rhs) const { if (this->pos == rhs.pos) { return true;}  return false;};
    bool operator > (const Location& rhs);
    int value() const;
    string Name() const;
private:

   int pos;
};


#endif //HW2_LOCATION_H
