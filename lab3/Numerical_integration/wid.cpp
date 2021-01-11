#include "wid.h"

float Function(float _x)
{
    return 1/((2*_x+7)*(3*_x+4));
//    return _x/((2*_x+7)*(3*_x+4));
    //return _x/((3*_x+4)*(3*_x+4));
}
float Accuracy1(float _F2h, float _Fh, float _h1, float _h2)
{
    float k = _h2/_h1;
    return _F2h + ((_F2h-_Fh)/(k*k-1));
}
float Accuracy2(float _F2h, float _Fh, float _h1, float _h2)
{
    float k = _h2/_h1;
    return ((_F2h-_Fh)/(k*k-1));
}
float Rectangles(QVector <float> _x, float _h, int _i)
{
    float a = 0.0;
    for(int i=0;i < _i; i++)
    {
        a += _h*Function((_x[i]+_x[i+1])/2.0);
    }
    return a;
}
float Trapezoids(QVector <float> _x, float _h, int _i)
{
    float a = 0.0;
    for(int i=0;i<_i;i++)
        a += _h*(Function(_x[i])+Function(_x[i+1]));
    return 0.5*a;
}
float Simpson(QVector <float> _x, float _h, int _i)
{
    float a = 0.0;
    if (_i!=0) a=Function(_x[0]);
    for(int i=1;i<_i;i=i+2)
    {
        if(i+1 == _i)
            a += 4*Function(_x[i]) + Function(_x[i+1]);
        else
            a += 4*Function(_x[i]) + 2*Function(_x[i+1]);
    }
    return a*_h/3.0;
}
