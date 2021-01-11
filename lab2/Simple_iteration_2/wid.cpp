#include "wid.h"

bool CriterionTermination(float _xk, float _x,float _q, float accuracy)
{
    if((_q/(1-_q))*abs(_xk-_x) < accuracy)
        return true;
    return false;
}
float Fi(float _x)
{
    return qAcos(- 0.25*_x + 0.5);
}
float Fi_der(float _x)
{
    return 0.25/(qSqrt(1 - (0.5 - 0.25*_x)*(0.5 - 0.25*_x)));
}
float Fi_sec_der(float _x)
{
    return (0.5 - 0.25*_x)/(16*qSqrt((1 - (0.5 - 0.25*_x)*(0.5 - 0.25*_x))*(1 - (0.5 - 0.25*_x)*(0.5 - 0.25*_x))*(1 - (0.5 - 0.25*_x)*(0.5 - 0.25*_x))));
}
float Function(float _x)
{
    return qCos(_x) + 0.25*_x - 0.5;
}
float Derivative(float _x)
{
    return - qSin(_x) + 0.25;
}
float Second_derivative(float _x)
{
    return - qCos(_x);
}
float Sign(float _a)
{
    if (_a < 0)
        return -1.0;
    else if (_a == 0)
        return  0.0;
    else
        return 1.0;
}
