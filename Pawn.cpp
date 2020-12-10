//
// Created by tuli on 24/11/2020.
//

#include "Pawn.h"
ostream& Pawn::put(ostream &os) const {
    if (!whatColor()) os << "p";
    else os <<"P" ;
    return os;
}

Vect Pawn::Route(const Location &dst) {
    Vect moves(5);
    int mov = 8;
    int d = dst.value();
    int sr = getLoc().value();  //mov is minus or plus
    if (hasMoved){// possible doule first move

    if (!whatColor()){ // depending on color
        if ( d != (sr - mov))   return Vect(0);
        else     {
            moves.push(d);
            return moves; }
    }
    else {
        if ( d != (sr + mov))       return Vect(0);
        else     {  moves.push(d);      return moves; }
    }
    }

    else if (!whatColor())
    { // depending on color
        if ( (d != (sr - mov) ) && (d != sr - 2*mov)) return Vect(0); //only two options
        else     {
            while (d < sr){
            sr -= 8;
            moves.push(sr);
            }
         return moves;
         }
    }
    else if ( (d != sr + mov) && (d != sr + 2*mov)) return Vect(0);   // NEED TO FIX ENPASAT HERE SOMEHOW I DONT KNOWWW
     else     {
        while (d > sr){
        sr += 8;
        moves.push(sr);
        }
        return moves;
        }

    return Vect(0);
}


Vect Pawn::Route(const Location& dst, bool flag){
    Vect moves(1);
    int d = dst.value();                                            //PAWN eating move sideways
    int sr = getLoc().value();
    if (whatColor()){
        if (d != sr +7 && d != sr +9 )  { return moves; } //only front or back
    moves.push(d);
    return moves;
    }
    else    {
    if (d != sr -7 && d != sr -9 )   { return moves;   }
    moves.push(d);
    return moves;
    }
}
