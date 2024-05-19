#include "Vector2.h"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
Vector2::Vector2()
{
    x = 0;
    y = 0;
}
Vector2::Vector2(int _x,int _y){
x= _x;
y = _y;
}

Vector2::Vector2(float _x,float _y){
x= _x;
y = _y;
}
Vector2::Vector2(const Vector2 &other){
x= other.x;
y = other.y;
}
Vector2 Vector2::operator+(const Vector2 &other) const{
 return Vector2(x + other.x,y + other.y);
}
Vector2 Vector2::operator+( const float &other) const{
   return Vector2(x + other,y + other);
}
Vector2 Vector2::operator-(const Vector2 &other) const{
 return Vector2(x - other.x,y - other.y);
}

Vector2 Vector2::operator-( const float &other) const{
   return Vector2(x - other,y - other);
}
Vector2 Vector2::operator*(const float other){
    return Vector2(x*other,y*other);
}

Vector2 Vector2::operator*(const Vector2 other){
    return Vector2(x*other.x,y*other.y);
}
Vector2 Vector2::operator/(const Vector2 other){
    Vector2 temp(x,y);
    if(other.x ) temp.x /= other.x;
    if(other.y) temp.y /= other.y;
    return temp;
}


Vector2 Vector2::operator/(const float other){
    if(!other){
    return Vector2(x/other,y/other);
    }
    return Vector2(x,y);
}
std::string Vector2::ToString(){
    return to_string(x) +","+to_string(x);
}
float Vector2::distance(const Vector2 &other){
    return sqrt((x -other.x)*(x -other.x) + (y -other.y)*(y -other.y));
}

float Vector2::distance(){
    return sqrt(x*x + y*y);
}
Vector2 Vector2::lerp(Vector2 A,Vector2 B,float T){
      return A+(B-A)*T;
}
float Vector2::clamp(Vector2 range,float T){
    if(T > range.y) T = range.y;
    if(T < range.x) T = range.x;
     return T;
 }
