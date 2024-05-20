#ifndef CHESS_H
#define CHESS_H
#include <vector>
#include "vector2.h"
using namespace std;
enum pies{
pawn,
tower,
knight,
runner,
queen,
king};
struct P{
pies tipus;
Vector2 pos;
};
class Chess
{
    public:
        Chess();
        bool TryMove(Vector2 pos);

    private:
        vector<P> light;
        vector<P> dark;
};

#endif // CHESS_H
