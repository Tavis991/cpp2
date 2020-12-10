//
// Created by tuli on 21/11/2020.
//

#include "ChessTool.h"


ChessTool::ChessTool(bool color, Location loc, char type) :color(color), loc(loc), type(type)
{}

//bool ChessTool::inReach(const Location &dst) {
//    return 0;
//}
ChessTool::ChessTool (const ChessTool& other): color(other.color), loc(other.loc), type(other.type), hasMoved(other.hasMoved) {
}
Vect ChessTool::Route(const Location &dst) {
 cout << "overridden !! this is not supposed to happen "<< endl;
 return Vect(0);
}

 Vect ChessTool::Route(const Location& dst, bool flag)
{ cout << "overridden !! this is not supposed to happen "<< endl;
return Vect(0);
}
ChessTool::ChessTool()
:color(false), loc(-1),  type('.'), hasMoved(false)
{}
ostream& operator <<(ostream & os, const ChessTool& ref)
{

ref.put(os);
return os;
}


Vect ChessTool::checkCol(int sr, int d){
Vect moves(10);
    if (d%8 == sr %8){     // IF on tura col
        if (d > sr){
            while (sr < d){
            sr += 8;
            moves.push(sr);}
        }
        else {
            while (sr > d){
            sr -= 8;
            moves.push(sr);
            }
        }
    }

    else {
    int Rwid; // if on tura row
        if (d > sr ){
            Rwid = (8 - sr%8);
            if(d - sr > Rwid) return moves;         // not on row
            while (d > sr)
            moves.push(++sr);
        }
        else {
            Rwid = (sr%8);
            if (sr - d > Rwid) return moves;   // not on row
            while (sr > d)
            moves.push(--sr);
        }

    }
    return moves;
}
Vect ChessTool::checkDiag(int src, int dst){
    Vect moves(10);
    if (src > dst){  //top half
        if (src%8 > dst%8){ //left corner
        while (src > dst){
        src -= 9;
        moves.push(src);
        }
        if (src != dst) moves.clear();
        return moves;
        }

        else if (src%8 < dst%8){ //right ocrner
        while (src > dst){
        src -= 7;
        moves.push(src);
        }
        if (src != dst) moves.clear();
        return moves;
        }
        else return moves;  //on col
    }


    else {  //low half
        if (src%8 > dst%8){ //left corner
        while (src < dst){
        src += 7;
        moves.push(src);
        }
        if (src != dst) moves.clear();
        return moves;
        }

        else if (src%8 < dst%8){ //right ocrner
        while (src < dst){
        src += 9;
        moves.push(src);
        }
        if (src != dst) moves.clear();
        return moves;
        }
        else return moves;  //on col}

    }
    return moves;
 }


ostream & ChessTool::put(ostream &os) const {
    return os;
}

bool ChessTool::onBoard(int b){
return (b < 0 || b > 63);
}

ChessTool&  ChessTool::operator = (const ChessTool& rhs){
loc = rhs.loc; color = rhs.color;  hasMoved = rhs.hasMoved; type = rhs.type;
return *this;
}
