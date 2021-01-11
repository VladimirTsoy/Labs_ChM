#include "wid.h"

float Fy(float _z)
{
    return _z;
}
float Fz(float _x, float _y)
{
    return 2*(1+(qTan(_x))*(qTan(_x)))*_y;
}
float Ftrue(float _x)
{
    return (1 + (qTan(_x*(_x+1))));
}
float Accuracy(float _y2, float _y1)
{
    return ((_y2-_y1)/((2*2)-1));
}
void SolveMatrix (QVector<float> _a, QVector<float> _c, QVector<float> _b, QVector<float> _f, QVector<float> &_x)
{
        for (int i = 1; i < _x.size(); i++)
        {
                float m = _a[i]/_c[i-1];
                _c[i] = _c[i] - m*_b[i-1];
                _f[i] = _f[i] - m*_f[i-1];
        }

        _x.last() = _f.last()/_c.last();

        for (int i = _x.size() - 2; i >= 0; i--)
                _x[i]=(_f[i]-_b[i]*_x[i+1])/_c[i];
}
bool Diagonal_dominance(QVector<float> _a, QVector<float> _c, QVector<float> _b)
{
    for (int i = 1;i<_c.size()-1;i++)
    {
        if((_a[i]==0)||(_b[i]==0))
            return true;
    }
    for (int k = 0; k<_c.size(); k++)
    {
        if(abs(_c[k]) < abs(_a[k])+abs(_b[k]))
            return true;
    }
    return false;
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
