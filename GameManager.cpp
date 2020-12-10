//
// Created by tuli on 22/11/2020.
//
#include <iostream>
#include <sstream>
#include "GameManager.h"



GameManager::GameManager() :  INPERR("Invalid input; please enter a move:" ), MOVERR("Invalid move; please enter a move:"),
BLTRN("Black's turn, please enter a move: "), WHTRN("White's turn, please enter a move: "),
CHKMT("wins with checkmate!"), INSUFF("The game is drawn due to insufficient material"), PAT("The game is drawn due to stalemate"),WhinShaq(false),BlinShaq(false)
{}

int GameManager::run() {
    string temp;// return value for checking purpose
    ChessBoard chis;
    int count = 0;
    int flag = 0;
    chis.print();

    Location src;
    Location dst;
    while (!chis.checkMate()){
        if (count%2) {      cout << BLTRN << endl;  }
        else   {     cout << WHTRN << endl; }

        string temp = Mpares(src, dst);
        while (temp == "0") {   cerr << INPERR << endl; ; temp = Mpares(src, dst);  }
        if (temp == "1"){
            //cout << src.value() << endl;
            //cout << dst.value();
            if (chis[src.value()].whatKind() == EMPTY) { cerr << MOVERR << endl;  continue;} //if trying to move empty square

            if (count%2) {
            if      (chis[src.value()].whatKind() != BLACK) { cerr << MOVERR << endl;  continue;} //if trying to move not a piece of his
            else if (chis[src.value()].whatKind() ==  chis[dst.value()].whatKind()) { cerr << MOVERR << endl;  continue;}
            ChessBoard chez = chis;// if move illegal break here already
            if (chis[src.value()].whatKind() ==  -chis[dst.value()].whatKind()) {
            //eating move

                try {
                flag = chis(src,dst,true);

                    if (!flag)    {
                        cerr << MOVERR << endl;  continue;}   // casteling is implicit
                    }

                catch(const char * msg){     cerr << MOVERR << endl;   }

                }

            else{
                try
                    {
                    if (!chis(src,dst, false))  { cerr << MOVERR << endl;  continue;}
                //reg move
                    }
                catch(const char * msg) { cerr << MOVERR << endl;       }
            }


            chez.moove(src.value(),dst.value()); // test on new board;
            if (chez.simpleCheck(BLACK)){


                {cout << "black checked ";}

            cerr << MOVERR << endl;  continue;
            }
            else {  chis.moove(src.value(),dst.value());}
         //all good
                if (chez.simpleCheck(WHITE)){

                    if (chez.CheckCheck(chez.Check(WHITE), WHITE))            //CHECKMATE
                    {
                    cout << "Black" << CHKMT;
                    break;
                    }
                }

            }



            else {
                  //white's turn
                if      (chis[src.value()].whatKind() != WHITE) { cerr << MOVERR << endl;  continue;}
                else if (chis[src.value()].whatKind() ==  chis[dst.value()].whatKind()) { cerr << MOVERR << endl;  continue;}  // if trying to override self
                else if (chis[src.value()].whatKind() ==  -chis[dst.value()].whatKind()) {
                //EATING MOVE
                    try {
                        if(!(chis(src,dst,true)))   { cerr << MOVERR << endl;  continue;} ;  // board will check legality of move other than that
                        }
                    catch(const char * msg){    cerr << MOVERR << endl;   continue;  }
                        }

                else{
                    try
                        {
                        if (!chis(src,dst, false)){ cerr << MOVERR << endl;  continue;}
                        }
                    catch(const char * msg){    cerr << MOVERR << endl;   continue;}
                    }
                    ChessBoard chez = chis;
                    chez.moove(src.value(),dst.value());
                    if (chez.simpleCheck(WHITE)){

                      {cout << "white checked ";}



             cerr << MOVERR << endl;  continue;
            }
            else {
            chis.moove(src.value(),dst.value());

            }

           //move on board

             if (chez.simpleCheck(BLACK)){

                    if (chez.CheckCheck(chez.Check(BLACK), BLACK))            //CHECKMATE
                    {
                    cout << "White" << CHKMT;
                    break;
                    }
                }
            }                   //I should check elpasan here keep a flag on each pawn that makes two moves but it SUCKS THAT MANAGER DOES EVERYTHING

        }

        else  {
        if (!promote(chis, src, dst, count, temp)) { continue;}
        }

        count++;
        chis.print();
    }

    return 1;
}


bool GameManager::promote(ChessBoard& chis, Location src, Location dst, int count, string temp){
    if (count%2) {
            if      (chis[src.value()].whatKind() != BLACK) { cerr << MOVERR << endl;  return false;} //if trying to move not a piece of his
                else if (chis[src.value()].whatKind() ==  chis[dst.value()].whatKind()) { cerr << MOVERR << endl;  return false;} // if move illegal break here already
                if (chis[src.value()].whatType() != 'p')   { cerr << MOVERR << endl;  return false;}
                if (dst.value() < 56 )   { cerr << MOVERR << endl;  return false;   }

                if (chis[src.value()].whatKind() ==  -chis[dst.value()].whatKind()) {
                    if (!chis(src,dst, true)){ cerr << MOVERR << endl;  return false;}
                }
                else  if (!chis(src,dst, false)){ cerr << MOVERR << endl;  return false;}



                ChessBoard chez = chis;  //need to figure out how to do it, player is really deleted in both boards
                chez.promote(src.value(),dst.value(), temp[0]);
                if (chez.simpleCheck(BLACK)){
                cerr << MOVERR << endl;
                return false;
                }
                else    {
                chis.promote(src.value(),dst.value(), temp[0]);
                 return true;
                }

        }

    else {
                  //white's turn
                if      (chis[src.value()].whatKind() != WHITE) { cerr << MOVERR << endl;  return false;}
                else if (chis[src.value()].whatKind() ==  chis[dst.value()].whatKind()) { cerr << MOVERR << endl;  return false;}
                if (chis[src.value()].whatType() != 'p')   { cerr << MOVERR << endl;  return false;}// if trying to override self
                if (dst.value() > 7 )   { cerr << MOVERR << endl;  return false ; }
                if (chis[src.value()].whatKind() ==  -chis[dst.value()].whatKind()) {
                    if (!chis(src,dst, true)){ cerr << MOVERR << endl;  return false;}
                    }
                else if (!chis(src,dst, false)){ cerr << MOVERR << endl;  return false;}



                ChessBoard chez = chis;  // TEST BOARD
                chez.promote(src.value(),dst.value(), temp[0]);
                if (chez.simpleCheck(WHITE)){
                cerr << MOVERR << endl;
                return false;
                }
                else    {
                chis.promote(src.value(),dst.value(), temp[0]);
                 return true;
                }
                chis.promote(src.value(),dst.value(), temp[0]);
                return true;

        }
}
//bool GameManager::readMove (int & count, ChessBoard & chis, Location& src, Location& dst){}

 bool GameManager::elpasan (int & count, ChessBoard & chis, Location& src, Location& dst){
        if (abs(src.value() - dst.value()) < 15 ){
        return chis(src,dst,false);
        }
        return chis(src,dst,false);
 }

string GameManager::Mpares (Location& src, Location& dst) {  //parsing function
    string temp;
    getline(cin,temp);
    if (!cin){
    exit(1);
    }
    stringstream tip(temp);
    tip >> temp;
    if (temp.size() != 2)   return "0";
    try {  src = Location(temp);}
    catch (const char* msg){
        return "0";
    }
    tip >> temp;
    if (temp.size() != 2)    return "0";

    try {  dst = Location(temp);}
    catch (const char* msg){
        return "0";
    }
    temp = "";
    tip >> temp;
    if (temp.size() > 1)    return "0";
    else if (temp.size() == 0)  return "1";
    else { //promotion
        switch (temp[0])
        {
            case ('Q'):
                break;
            case ('R'):
                break;
            case ('B'):
                break;
            case ('N'):
                break;
            default:
                return "0";
        }
    }
    return temp;       // this means promotion
}
