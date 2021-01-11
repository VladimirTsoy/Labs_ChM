#include "wid.h"
bool CriterionTermination(float _xk, float _x, float accuracy)
{
    if(abs(_xk-_x) < accuracy)
        return true;
    return false;
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
