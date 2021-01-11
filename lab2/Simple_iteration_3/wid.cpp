#include "wid.h"


bool CriterionTermination(float _xk[N], float _x[N], float _q, float accuracy)
{
    float max;
    if(abs(_xk[0] - _x[0]) < abs(_xk[1] - _x[1]))
        max = abs(_xk[1] - _x[1]);
    else
        max = abs(_xk[0] - _x[0]);
    if((_q / (1 - _q)) * max < accuracy)
        return true;
    return false;
}
float Fi1(float _x1, float _x2)
{
    return qCos(_x2) + 1;
}
float Fi2(float _x1, float _x2)
{
    return log10(_x1 + 1) + 2;
}
float Fi1_der_x1(float _x1, float _x2)
{
    return 0;
}
float Fi1_der_x2(float _x1, float _x2)
{
    return -qSin(_x2);
}
float Fi2_der_x1(float _x1, float _x2)
{
    return 1/((_x1+1)*qLn(10));
}
float Fi2_der_x2(float _x1, float _x2)
{
    return 0;
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
