#include "Chess.h"

Chess::Chess()
{
    for(int i=0; i<8; i++){
        board.push_back(babu(Vector2(2,i+1)
                                 ,light,
                                 pawn));
           board.push_back(babu(Vector2(2,i+1)
                                 ,dark,
                                 pawn));
    }
}
