#include "Chess.h"

Chess::Chess()
{
    for(int i=0; i<8; i++){
        board.push_back(babu(Vector2(i+1,2)
                                 ,light,
                                 pawn));
           board.push_back(babu(Vector2(i+1,7)
                                 ,dark,
                                 pawn));
    }

GenNonPawn(light);
GenNonPawn(dark);
};
void Chess::GenNonPawn(Team col){
        board.push_back(babu(Vector2(1,1+int(col)*7)
                                 ,col,
                                 tower));
    board.push_back(babu(Vector2(2,1+int(col)*7)
                                 ,col,
                                 knight));
     board.push_back(babu(Vector2(3,1+int(col)*7)
                                 ,col,
                                 runner));
     board.push_back(babu(Vector2(4,1+int(col)*7)
                                 ,col,
                                 king));
     board.push_back(babu(Vector2(5,1+int(col)*7)
                                 ,col,
                                 queen));
     board.push_back(babu(Vector2(6,1+int(col)*7)
                                 ,col,
                                 runner));
     board.push_back(babu(Vector2(7,1+int(col)*7)
                                 ,col,
                                 knight));
     board.push_back(babu(Vector2(8,1+int(col)*7)
                                 ,col,
                                 tower));
}
bool Chess::TryMove(Vector2 mw){


prewmove = mw;
}
