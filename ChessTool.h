//
// Created by tuli on 21/11/2020.
//

#ifndef HW2_CHESSTOOL_H
#define HW2_CHESSTOOL_H

#include <iostream>
#include "Vect.h"
using namespace std;
class ChessTool {
public:
    friend class ChessBoard;
    ChessTool ();
    ChessTool (const ChessTool& other); //COPY CTOR BIG PROBLEM
    ChessTool (bool color, Location loc, char type);
    virtual ~ChessTool() {}
    virtual ostream & put(std::ostream& os) const;
    virtual Vect Route(const Location &dst);// virtual route function returns an array of locations which is route to dest
    virtual Vect Route(const Location &dst, bool flag);
   // virtual ~ChessTool(); //overloaded method when call is to eat enemy tool, for pawn which moves differntly in case
    bool whatColor() const { return this->color; }
    friend ostream& operator <<(ostream & os, const ChessTool& ref);
    Location& getLoc() {    return loc;}
    ChessTool& operator =(const ChessTool& rhs);
    void setLoc(int val) { loc = Location(val);}
    bool onBoard (int b) ;
    bool lives () { return (getLoc().value() != -1);}
    bool hisMoved () { return hasMoved;}
    bool hezMoved (bool flag=true) { hasMoved = true; return true;}
    char getType () { return type;}
    Vect checkDiag(int src, int dst);
    Vect checkCol(int src, int dst);
private:
    bool color;
    Location loc;

protected:
    char type;
    bool hasMoved;   // NEED A UNIVERSAL FLAG FOR HAS MOVED  BECAUSE TOOL DOES NOT KNOW IF MOVE SUCCEDED
};

ostream& operator <<(ostream & os, const ChessTool& ref);


#endif //HW2_CHESSTOOL_H
