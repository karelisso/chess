#ifndef CHESS_H
#define CHESS_H
#include <vector>
#include "vector2.h"
using namespace std;
enum tipus{
king,queen,runner,knight,tower,pawn};
enum Team{
dark,
light};
struct babu{
    tipus fig;
    Team csapat;
    Vector2 pos;
    babu(Vector2 _pos,Team _csapat,tipus _fig){
        pos= _pos;
        csapat = _csapat;
        fig = _fig;
    }
    int to_int(){
    return int(fig) +10*pos.x+100*pos.y;
    }
};

class Chess
{
    public:
        Chess();
        bool TryMove(Vector2 pos);

    private:
        vector<babu> board;
};

#endif // CHESS_H
