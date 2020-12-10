//
// Created by tuli on 21/11/2020.
//

#include "GridSquare.h"

ostream& operator <<(ostream & os, const GridSquare& ref) {
    if (ref.player) {
        if  (ref.player->getLoc().value() == -1)   os << ". ";
        else     os << *ref.player <<   " ";
    }
    else os << ". ";
    return os;
}
GridSquare::GridSquare(const GridSquare &other): super(other), player(new ChessTool(*other.player))
{  }//GRIDSQUARE COPY CTOR BIG BALAGAN
//
GridSquare &GridSquare::operator&=(GridSquare &rhs) {
   if (this == &rhs) return *this;
   if(rhs.player)   {    rhs.player->setLoc(-1);    }

   rhs.player = player;
   rhs.player->setLoc(rhs.value());// SET LOCATION WORK ONLY FOR WHITES
   if (!rhs.player->hisMoved()) rhs.player->hezMoved();
   player = NULL;  //copieng player
   return *this;
}
GridSquare &GridSquare::operator%=(GridSquare &rhs) { //demo mod for gridsquare operator
   if (this == &rhs) return *this;
                                            /// i  want to set rhs player dead for testing and then bring it back
   rhs.player = player;
   rhs.player->setLoc(rhs.value());//
   player = NULL;  //copieng player
   return *this;
}


int GridSquare::whatKind()
 {
    if (!player) return EMPTY;
    else if (player->whatColor()) return BLACK;
    return WHITE;
}
char GridSquare::whatType()
 {
    if (!player) return 0;
    else return player->getType();

}
//GridSquare &GridSquare::operator=(GridSquare &rhs) {
//   if (this == &rhs) return *this;
//   this->player = rhs.player;
//}
