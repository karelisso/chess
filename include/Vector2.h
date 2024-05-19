#ifndef VECTOR2_H
#define VECTOR2_H
#include <string>
using namespace std;
class Vector2
{

    public:
        float x,y;
        Vector2();
        Vector2(int,int);
        Vector2(float,float);
        Vector2(const Vector2&);
        Vector2 operator+(const Vector2 &other) const;
        Vector2 operator+( const float &other) const;
        Vector2 operator-(const Vector2 &other) const;

        Vector2 operator-( const float &other) const;
        Vector2 operator*(const float other);
        Vector2 operator*(const Vector2 other);
        Vector2 operator/(const Vector2 other);
        Vector2 operator/(const float other);
        std::string ToString();
        float distance();
        float distance(const Vector2 &other);
        static Vector2 lerp(Vector2 A,Vector2 B,float T);
        static float clamp(Vector2 range,float T);
    protected:

    private:
};

#endif // VECTOR2_H
