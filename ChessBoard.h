//
// Created by tuli on 21/11/2020.
//

#ifndef HW2_CHESSBOARD_H
#define HW2_CHESSBOARD_H

#include "ChessTool.h"
#include "GridSquare.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Tura.h"
#include "Pawn.h"
#include "Knight.h"


class ChessBoard {
public:
    ChessBoard();
    ChessBoard(const ChessBoard& other);
    ~ChessBoard();
   // int moveIf(int a, int b);
    bool checkMate(){ return oShaq;}
    GridSquare& operator[](int grid);
    //GridSquare operator()(int grid);
    bool onBoard(int b) {return (b > 0 || b < 63);}
    int operator () (Location src, Location dst, bool flag);
    void operator = (const ChessBoard& rhs);
    void print();
    void moove (int src, int dst);
    void TEST_moove (int src, int dst) { GridArr[src] %= GridArr[dst];}
    void promote (int src, int dst, char type) ;
    Vect KingMovs(int color);
    bool simpleCheck(int color);
    Location WhereKING(int color) { if (color == BLACK) return BLACKING(); else return WHITKING();}
    Vect** Check(int kind);
    bool CheckCheck(Vect** vic, int color);
    bool Castellation(int color, Vect route);
    void demote (int src, int dst);

private:
    enum KIND{ WHITE = -1, EMPTY = 0, BLACK = 1 };  // CHANGED ENUM TO NAME KIND
    bool oShaq;
    GridSquare GridArr[64];
    ChessTool* PlayWhArr[16];
    ChessTool* PlayBlArr[16];
    inline bool checkRoute (Vect route){
       if (!route.size()) return false;
       for (int i=0; i<route.size(); i++)    {
       if ((!onBoard(route[i])) || !GridArr[route[i]].isEmpty())
       return false; }
       return true;  //if route suggested by tool is not clear move illegal
        }
    inline Location WHITKING ()  { return PlayWhArr[12]->getLoc();}
    inline Location BLACKING ()  { return PlayBlArr[4]->getLoc();}

};


#endif //HW2_CHESSBOARD_H
