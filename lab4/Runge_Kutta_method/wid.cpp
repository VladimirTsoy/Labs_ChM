#include "wid.h"

float Fy(float _z)
{
    return _z;
}
float Fz(float _x, float _y, float _z)
{
    return (1+(2*((qTan(_x))*(qTan(_x)))))*_y;
//    return -(4*_x*_z)-(((4*_x*_x)+2)*_y);
//    return (2*_x*_z)/(_x*_x+1);
}
float Ftrue(float _x)
{
    return (1/(qCos(_x))) + (qSin(_x)) + (_x/(qCos(_x)));
//    return (1+_x)*(qExp(-_x*_x));
//    return _x*_x*_x + 3*_x + 1;
}
float Accuracy(float _y2, float _y1)
{
    return ((_y2-_y1)/((2*2*2*2)-1));
}
void Assignment(QVector<float> _mas, QVector<float> _mas2)
{
    NullMas(_mas, N-2);
    for(int i=0;i<N-2;i++)
    {
            _mas[i] = _mas2[i];
    }
}
void NullMas(QVector<float> _mas, float n)
{
    for(int i=0;i<n;i++)
    {
            _mas[i] = 0.0;
    }
}
