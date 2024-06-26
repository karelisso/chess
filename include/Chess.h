#ifndef CHESS_H
#define CHESS_H
#include <vector>
#include "vector2.h"
using namespace std;
enum tipus{
king,queen,runner,knight,tower,pawn};
enum Team{
light,
dark};
enum State{
round_light,
round_dark,
game_over};
struct babu{
    tipus fig;
    Team csapat;
    Vector2 pos;
    babu(Vector2 _pos,Team _csapat,tipus _fig){
        pos= _pos;
        csapat = _csapat;
        fig = _fig;
        down = false;
    }
    bool down;
    int to_int(){
    return int(fig) +10*pos.x+100*pos.y;
    }
};

class Chess
{
    public:
        Chess();
        void Init();
        void TryMove(Vector2 pos);
        babu IsMoveLegal(Vector2 next,babu);
         vector<babu> board;
         State currentState;
         int getRound();
    private:
        void GenNonPawn(Team);
        bool attack(int id);
        Vector2 prewmove;

};

#endif // CHESS_H
