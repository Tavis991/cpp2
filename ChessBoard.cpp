//
// Created by tuli on 21/11/2020.
//

#include <iostream>
#include <cstdlib>
#include "ChessBoard.h"

void ChessBoard::print() {

    for (int i = 0; i < 9; i++) {//print the board and extra row,col
        for (int j = 0; j < 9; j++) {
            if (i < 8) {
                if (j == 0) { cout << (8 - i) << " "; }
                else cout << GridArr[i*8+j-1];
            }
            else if (j==0) cout << "  ";
            else ( cout << (char)('A'+j-1) << " ");
        }
        cout << endl;
    }
}





ChessBoard::ChessBoard(const ChessBoard &other) { //chessboard copy ctor
        for (int i = 0; i < 16; i++) { //initiliazing black tool set;

        if (i < 8) { PlayWhArr[i] = (new Pawn(*other.PlayWhArr[i])); }
        else if (i == 8 || i == 15) { PlayWhArr[i] = (new Tura(*other.PlayWhArr[i])); }
        else if (i == 9 || i == 14) { PlayWhArr[i] = (new Knight(*other.PlayWhArr[i])); }
        else if (i == 10 || i == 13) { PlayWhArr[i] = (new Bishop(*other.PlayWhArr[i])); }
        else if (i == 11) { PlayWhArr[i] = (new Queen(*other.PlayWhArr[i])); }
        else { PlayWhArr[i] = (new King(*other.PlayWhArr[i])); }
    }
    for (int i = 0; i < 16; i++) { //initiliazing white tool set;

        if (i > 7) { PlayBlArr[i] = (new Pawn(*other.PlayBlArr[i])); }
        else if (i % 7 == 0) { PlayBlArr[i] = (new Tura(*other.PlayBlArr[i])); }
        else if (i == 1 || i == 6) { PlayBlArr[i] = (new Knight(*other.PlayBlArr[i])); }
        else if (i == 2 || i == 5) { PlayBlArr[i] = (new Bishop(*other.PlayBlArr[i])); }
        else if (i == 3) { PlayBlArr[i] = (new Queen(*other.PlayBlArr[i])); }
        else { PlayBlArr[i] = (new King(*other.PlayBlArr[i])); }
    }
    for (int i=0; i<64; i++){
    GridArr[i]= other.GridArr[i];
    }
    for (int i=0; i<16; i++){
        int position = PlayWhArr[i]->getLoc().value();  // MATCHing grid and player
        if  (onBoard(position))   {
            GridArr[position].setPlayer(PlayWhArr[i]);
        }
    }
     for (int i=0; i<16; i++){
        int position = PlayBlArr[i]->getLoc().value();
        if(onBoard(position))   {
            GridArr[position].setPlayer(PlayBlArr[i]);
        }
    }

}

ChessBoard::ChessBoard() :oShaq(false) {
    for (int i = 0; i < 16; i++) { //initiliazing black tool set;

        if (i < 8) { PlayWhArr[i] = (new Pawn(false, Location(A2+i))); }
        else if (i == 8 || i == 15) { PlayWhArr[i] = (new Tura(false, Location(A2 + i))); }
        else if (i == 9 || i == 14) { PlayWhArr[i] = (new Knight(false, Location(A2 + i))); }
        else if (i == 10 || i == 13) { PlayWhArr[i] = (new Bishop(false, Location(A2 + i))); }
        else if (i == 11) { PlayWhArr[i] = (new Queen(false,  Location(A2 + i))); }
        else { PlayWhArr[i] = (new King(false,  Location(A2 + i))); }
    }
    for (int i = 0; i < 16; i++) { //initiliazing white tool set;

        if (i > 7) { PlayBlArr[i] = (new Pawn(true,  Location(A7+(i-8)))); }
        else if (i % 7 == 0) { PlayBlArr[i] = (new Tura(true,  Location(A8+i))); }
        else if (i == 1 || i == 6) { PlayBlArr[i] = (new Knight(true,  Location(A8 +i))); }
        else if (i == 2 || i == 5) { PlayBlArr[i] = (new Bishop(true,  Location(A8 +i))); }
        else if (i == 3) { PlayBlArr[i] = (new Queen(true,  Location(A8 +i))); }
        else { PlayBlArr[i] = (new King(true,  Location(A8 +i))); }
    }
    int j = 0;
    for (int i=0; i<64; i++){ //placing tools on grid
        if (i<16){ GridArr[i] = GridSquare(PlayBlArr[i]->loc, PlayBlArr[i]);}
        else if (i < 48 ) GridArr[i] = GridSquare(i);                       //HERE START BAD THINGS
        else if (i>47){ GridArr[i] = GridSquare(PlayWhArr[i-48]->loc, PlayWhArr[j++]);}
    }


}

ChessBoard::~ChessBoard(){
    for (int i = 0; i < 16; i++) {
        delete(PlayBlArr[i]);
        delete(PlayWhArr[i]);
    }
}

GridSquare &ChessBoard::operator[](int i) {
    if (i<0 || i>63) { cerr <<"board out of bounds" ; exit(1); }
    return GridArr[i];
}


int ChessBoard::operator () (Location src, Location dst, bool flag){
    // this is move on board
//

    Vect route;

    if (!flag)
    {  //this is flag for eating move
    route = ((&GridArr[src.value()])->player->Route(dst));
    if (!route.size()) return EMPTY;  // if tool cannot reach point theoretically
    for (int i=0; i<route.size(); i++)    {
       if ((!onBoard(route[i])) || !GridArr[route[i]].isEmpty()) return EMPTY; }  //if route suggested by tool is not clear move illegal
    }

    else
    {
    route = (&GridArr[src.value()])->player->Route(dst, true);
    if (!route.size()) return EMPTY;  // if tool cannot reach point theoretically
    //cout << GridArr[route[1]].isEmpty() << endl;
    for (int i=0; i<route.size()-1; i++)    {

       if ( !onBoard(route[i]) || !GridArr[route[i]].isEmpty()) return EMPTY;    //if route suggested by tool is not clear move illegal

       }
    }
    if ((GridArr[src.value()].player->getType() == 'k' ) && (route.size()>1)) {

        if (!Castellation(GridArr[src.value()].whatKind(),route)) return EMPTY; //this is casteling
        if (!GridArr[dst.value()+1].isEmpty()) { //here looking for tura
          if ((GridArr[dst.value()+1].player->getType() == 'r' ) && (!GridArr[dst.value()+1].player->hisMoved())){
           GridArr[dst.value()+1] &= GridArr[dst.value()-1]; //TURA DONT MOVE
            }
         }
        else if (!(GridArr[dst.value()-1].isEmpty())) { //or other side
                if((GridArr[dst.value()-1].player->getType() == 'r' ) && (!GridArr[dst.value()-1].player->hisMoved())){
                    GridArr[dst.value()-1] &= GridArr[dst.value()+1];
                }
                else return EMPTY;  //else false move
            }
        else return EMPTY;

    }
                // SAVE LOCATION OF  LAST PAWN MOVE FOR ELPASAN//move tool   // #S OF MEMBER FUNCTION CALLED BY REF ~8 HERE
    return BLACK;

}


 bool ChessBoard::CheckCheck(Vect** vic, int color){
    bool canRun = false;
    int Shaked = 0;
    Vect temp;

    Vect kingMv = KingMovs(color);                   //first check if king escape
    while (kingMv.size()>0){
            int tmp = kingMv.pop();
            GridArr[WhereKING(color).value()] %= GridArr[tmp];  //if king cn escape
            if (!simpleCheck(color)) {
                GridArr[tmp] %= GridArr[WhereKING(color).value()];
                canRun = true;
                break;
            }//king can escape //this iIS MANY PROBLEMS
            GridArr[tmp] %= GridArr[WhereKING(color).value()];
    }
    if (canRun)  {
       // for (int i=0; i<2; i++) { if (vic[i]) delete(vic[i]);} /// HERE SEGMENATING
        return false;
    }

    for (int i=0; i<2; i++){  //routes to king,
        if(vic[i]->size()) {
               if (Shaked) {
               Shaked++;
               break;
               } //if  there are two threats and one move you are mat, we know this from cages of the pidgeon

                   if (color == BLACK){ //if king cannot escape maybe somone save him
                     for (int k=0; k<16; k++){
                        for (int j=0; j<(vic[i])->size(); j++){
                             if (PlayBlArr[k]->lives()) {  // if there is a player alive
                             temp = PlayBlArr[k]->Route(Location((*vic)->pop())); // if he can block the check move
                                if (temp.size()){ // if theres a route
                                    Shaked++;
                                    break;
                                    }
                                }
                            }
                          if (Shaked) break;
                        }
                    }
                    else if (color == WHITE){
                        for (int k=0; k<16; k++){
                            if (PlayWhArr[k]->lives()) {
                                 temp = PlayWhArr[k]->Route(Location((*vic)->pop()));
                                 if (temp.size()){  // if there is a route
                                     Shaked++;   //checked one check
                                     break; //brak?
                                }
                            }
                          if (Shaked) break;
                        }
                    } // if not one can block its check and he cant move mat
         }
     }

    // for (int i=0; i<16; i++) { if (vic[i]) delete(vic[i]);} //delete vic
     if (Shaked != 1) return true;
     return false;
 }

bool ChessBoard::simpleCheck(int color){
  Location sr = WhereKING(color);
  for (int i=0; i<16; i++){
            if (color == BLACK){  // this is already for checkmate actually  ... some how it will work
                 if (PlayWhArr[i]->lives()) {  // if there is a player alive
                    if ((*this)(GridArr[PlayWhArr[i]->getLoc().value()],sr,true)) // his route to the king
                     return true;
                     }
                }
            else if (color == WHITE){
                if (PlayBlArr[i]->lives()) {
                     if((*this)(GridArr[PlayBlArr[i]->getLoc().value()],sr,true))
                         return true;
                    }                         // if there is a route
                }
            }
        return false;
    }
 Vect** ChessBoard::Check(int color){  // will need to save source of threat and route to threat

    Vect* VectArr[2] = {NULL};
    int j = 0;// i should hav template vect for vect of vects but what can u do only so many time
    Vect** vic = VectArr;
    Vect temp;                  // save an array of vector moves
    Location kingLoc = WhereKING(color);
        for (int i=0; i<16; i++){
            if (j>1) return vic; // this will be enough for mat
            if (color == BLACK){  // this is already for checkmate actually  ... some how it will work
                 if (PlayWhArr[i]->lives()) {  // if there is a player alive
                 temp = (&GridArr[PlayWhArr[i]->getLoc().value()])->player->Route(kingLoc, true); // his route to the king
                 if (temp.size()){ // if theres a route
                     VectArr[j] = new Vect(temp); // i will dynammically alloc because i need it somehow
                     VectArr[j]->pop(); // removing the dst because we dont need it
                     VectArr[j++]->push(PlayWhArr[i]->getLoc().value()); // adding source of threat
                    }
                 //else {VectArr[i] = new Vect(0); } //placeholder against segmentatinon
                }
            }
            else if (color == WHITE){
            if (PlayBlArr[i]->lives()) {
                 temp = (&GridArr[PlayBlArr[i]->getLoc().value()])->player->Route(kingLoc, true);
                 if (temp.size()){  // if there is a route
                     VectArr[j] = new Vect(temp); // i will dynammically alloc because i need it somehow to last outside func
                     VectArr[j]->pop(); // removing the dst OF KING
                     VectArr[j++]->push(PlayBlArr[i]->getLoc().value()); // adding source of threat}
                    }
              //  else {VectArr[j] = new Vect(0); }
                }
            }
        }
    if (j == 1) VectArr[j] = new Vect(0);
    return vic;
}

void ChessBoard::demote (int src, int dst){
int color = GridArr[src].whatKind();  //check color
    for (int i=0; i<16; i++){
        if (color == BLACK) {
            if (PlayBlArr[i]->getLoc().value() == src) { //delete og PAWN
                delete(PlayBlArr[i]);
                PlayBlArr[i] = new Pawn(true,  Location(dst));
            }
        }
        else {
            if (PlayWhArr[i]->getLoc().value() == src) {
                delete(PlayWhArr[i]);
                PlayWhArr[i] = new Pawn(false,  Location(dst));

                }
            }
        }
    }

void ChessBoard::promote (int src, int dst, char type) {
    int color = GridArr[src].whatKind();  //check color
    for (int i=0; i<16; i++){
        if (color == BLACK) {
            if (PlayBlArr[i]->getLoc().value() == src) { //delete og PAWN
            delete(PlayBlArr[i]);

            switch (type){ //promote black
                case ('N'):
                PlayBlArr[i] = new Knight(true,  Location(src));
                break;
                case ('R'):
                PlayBlArr[i] = new Tura(true,  Location(src));
                break;
                case ('Q'):
                PlayBlArr[i] = new Queen(true,  Location(src));
                break;
                case ('B'):
                PlayBlArr[i] = new Bishop(true,  Location(src));
                break;
                default:
                break;
                }
            }
        }

        else { //promote white

            if (PlayWhArr[i]->getLoc().value() == src) {
                delete(PlayWhArr[i]);

            switch (type){
                case ('N'):
                PlayWhArr[i] = new Knight(false,  Location(src));
                break;
                case ('R'):
                PlayWhArr[i] = new Tura(false,  Location(src));
                break;
                case ('Q'):
                PlayWhArr[i] = new Queen(false,  Location(src));
                break;
                case ('B'):
                PlayWhArr[i] = new Bishop(false,  Location(src));
                break;
                default:
                break;
                }
            }
        }

    }

  //  if (test) GridArr[src] %= GridArr[dst];
    GridArr[src] &= GridArr[dst]; //make move

}

bool ChessBoard::Castellation(int color, Vect route){
    if (simpleCheck(color)) return false; //if in check cant castel
    for (int j=0; j<route.size(); j++){ //check all route
        for (int i=0; i<16; i++){
                if (color == BLACK){
                     if (PlayWhArr[i]->lives()) {  // if there is a player alive
                        if ((*this)(GridArr[PlayWhArr[i]->getLoc().value()],Location(route[j]),true)) // his route to TARGET
                         return false;
                         }
                    }
                else if (color == WHITE){
                    if (PlayBlArr[i]->lives()) {
                         if((*this)(GridArr[PlayBlArr[i]->getLoc().value()],Location(route[j]),true))
                             return false;
                        }                         // if there is a route
                    }
                }
            }
        return true;
    }

void ChessBoard::moove (int src, int dst) { GridArr[src] &= GridArr[dst];}
Vect ChessBoard::KingMovs(int color){
    int sr;
    Vect moves;
    sr = WhereKING(color).value();
    int arr [] = {sr + (7), sr + ( 8), sr + (9), sr + (1), sr - (1), sr - (7), sr - (8), sr - (9)};
    for (int i=0; i<8; i++) {
         if ((GridArr[arr[i]].isEmpty() || GridArr[arr[i]].whatKind() != color)  && onBoard(arr[i]))     moves.push(arr[i]);
     }
    return moves;
}

