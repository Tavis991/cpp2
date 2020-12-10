//
// Created by tuli on 22/11/2020.
//

#ifndef HW2_GAMEMANAGER_H
#define HW2_GAMEMANAGER_H
#include "ChessBoard.h"
#include <cmath>
#include <stdlib.h>
class GameManager{
public:
    GameManager() ;
    string Mpares (Location& src, Location& dst);
    int run();

private:
    enum kind { WHITE = -1, EMPTY = 0, BLACK = 1 };
    bool elpasan (int & count, ChessBoard & chis, Location& src, Location& dst);
    const string INPERR, MOVERR, BLTRN, WHTRN, CHKMT, INSUFF, PAT;
   // bool readMove(int & count, ChessBoard & chis, Location& src, Location& dst);
    bool promote(ChessBoard& chis, Location src, Location dst, int count, string temp);
    Vect check(ChessBoard & chis, bool color);
    bool WhinShaq;
    bool BlinShaq;
};
#endif //HW2_GAMEMANAGER_H
