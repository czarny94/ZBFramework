#ifndef VECTOR2D_H
#define VECTOR2D_H

#include<cmath>

template<class T>
class Vector2D
{
public:
    Vector2D();

    Vector2D(T x, T y);
    Vector2D(const Vector2D& v2);

    T lenght();

    T getX() { return mX; }
    T getY() { return mY; }

    void setX(T x) { mX = x; }
    void setY(T y){mY=y;}
    void set(T x, T y) { mX = x; mY = y; }
    void normalize();

    Vector2D operator +(const Vector2D& v2)const;
    Vector2D& operator +=(const Vector2D& v2);
    Vector2D& operator =(const Vector2D& v2);
    Vector2D operator *(const T amount)const;
    Vector2D& operator*=(const T amount);
    Vector2D operator -(const Vector2D& v2)const;
    Vector2D& operator -=(const Vector2D<T>& v2);
    Vector2D operator /(const T amount)const;
    Vector2D& operator /=(const T amount);


    ~Vector2D();
private:
    T mX;
    T mY;
};

#endif // VECTOR2D_H
