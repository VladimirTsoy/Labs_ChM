#include "wid.h"


float Fy(float _z)
{
    return _z;
}
float Fz(float _x, float _y)
{
    return (1+(2*((qTan(_x))*(qTan(_x)))))*_y;

}
float Ftrue(float _x)
{
    return (1/(qCos(_x))) + (qSin(_x)) + (_x/(qCos(_x)));
}
float Accuracy(float _y2, float _y1)
{
    return ((_y2-_y1)/((2*2*2*2)-1));
}

void Assignment(QVector<float> _mas, QVector<float> _mas2)
{
    NullMas(_mas, N);
    for(int i=0;i<N;i++)
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

