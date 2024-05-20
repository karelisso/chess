#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include "Vector2.h"
enum Team{
dark,
light};
class piece
{
    public:
        piece();
        virtual vector<Vector2> possible_moves()=0; //return to a vector with every possible position;
        virtual void move_to()=0; //moves to the desired position; this should work the same on every piece type.
        Vector2 curpos;
        Team team;
    protected:

    private:
};

#endif // PIECE_H
