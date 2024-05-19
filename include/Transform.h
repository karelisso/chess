#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <Vector2.h>


class Transform
{
    public:
          Transform(Vector2 ps,Vector2 sc): pos(ps),scale(sc){};
        Transform(Vector2 ps,Vector2 sc,int rt): pos(ps),scale(sc),rotation(rt){};
    protected:
        Vector2 pos;
        Vector2 scale;
        Vector2 UpLeft,DwRight;
        int rotation;
    private:
};

#endif // TRANSFORM_H
