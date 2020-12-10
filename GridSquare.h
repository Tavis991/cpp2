//
// Created by tuli on 21/11/2020.
//

#ifndef HW2_GRIDSQUARE_H
#define HW2_GRIDSQUARE_H

#include <clocale>
#include "ChessTool.h"

using namespace std;

class GridSquare : public Location { //gridsquare inherits location so that chesstool and gridsquare do not contradict
public: //each gridsquare has a chesstool and each chesstool has a location, or is off board
    friend class ChessBoard;
    GridSquare () : player(NULL)    {}
    //~GridSquare () { if (player != NULL ) delete(player); }
    GridSquare (const GridSquare & other);
    GridSquare (Location loc, ChessTool* player) : super(loc), player(player)
    {}
    explicit GridSquare ( unsigned int i) : super(i), player(NULL)
    {}
    bool isEmpty() { return (!player);}
    friend ostream& operator <<(ostream & os, const GridSquare& ref);
    GridSquare & operator&=(GridSquare &rhs);
    GridSquare & operator%=(GridSquare &rhs);
    int whatKind();
    char whatType();
    ChessTool* getPlayer(ChessTool*){ return player; }
    void setPlayer(ChessTool* newPlayer){ player = newPlayer; }
private:
    typedef Location super;
    ChessTool* player;
    enum kind { WHITE = -1, EMPTY = 0, BLACK = 1 };
};
ostream& operator <<(ostream & os, const GridSquare& ref);


#endif //HW2_GRIDSQUARE_H
