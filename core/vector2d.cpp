#include "vector2d.h"

template<class T>
Vector2D<T>::Vector2D():mX(0),mY(0)
{
}
template<class T>
Vector2D<T>::Vector2D(T x, T y):mX(x),mY(y)
{
}
template<class T>
Vector2D<T>::Vector2D(const Vector2D & v2)
{
    mX = v2.mX;
    mY = v2.mY;
}
template<class T>
T Vector2D<T>::lenght()
{
    return (sqrt(mX*mX+mY*mY));
}

template<class T>
void Vector2D<T>::normalize()
{
    T l = lenght();
    if (l > 0)
    {
        (*this *= 1 / l);
    }
}
template<class T>
Vector2D<T>  Vector2D<T>::operator+(const Vector2D<T>& v2) const
{
    return Vector2D(mX + v2.mX, mY + v2.mY);
}
template<class T>
Vector2D<T>& Vector2D<T>::operator +=(const Vector2D<T>& v2)
{
    mX += v2.mX;
    mY += v2.mY;
    return *this;
}
template<class T>
Vector2D<T> & Vector2D<T>::operator=(const Vector2D<T> & v2)
{
    mX = v2.mX;
    mY = v2.mY;
    return *this;
}
template<class T>
Vector2D<T>  Vector2D<T>::operator*(const T amount) const
{
    return Vector2D<T>(mX*amount, mY*amount);
}
template<class T>
Vector2D<T> & Vector2D<T>::operator*=(const T amount)
{
    mX *= amount;
    mY *= amount;
    return *this;
}
template<class T>
Vector2D<T> Vector2D<T>::operator-(const Vector2D<T> & v2) const
{
    return Vector2D<T>(mX-v2.mX,mY-v2.mY);
}
template<class T>
Vector2D<T> & Vector2D<T>::operator-=(const Vector2D<T> & v2)
{
    mX -= v2.mX;
    mY -= v2.mY;
    return *this;
}
template<class T>
Vector2D<T> Vector2D<T>::operator/(const T amount) const
{
    return Vector2D<T>(mX/amount,mY/amount);
}
template<class T>
Vector2D<T>& Vector2D<T>::operator/=(const T amount)
{
    mX /= amount;
    mY /= amount;
    return *this;
}

template<class T>
Vector2D<T>::~Vector2D()
{
}
