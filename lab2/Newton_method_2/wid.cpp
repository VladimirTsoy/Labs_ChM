#include "wid.h"


float Determinant(float _mas[N][N])
{
    return _mas[0][0]*_mas[1][1] - _mas[0][1]*_mas[1][0];
}
bool CriterionTermination(float _xk[N], float _x[N], float accuracy)
{
    float max;
    if(abs(_xk[0] - _x[0]) < abs(_xk[1] - _x[1]))
        max = abs(_xk[1] - _x[1]);
    else
        max = abs(_xk[0] - _x[0]);
    if(max < accuracy)
        return true;
    return false;
}
float Function1(float _x1, float _x2)
{
    return _x1 - qCos(_x2) - 1;
}
float Function2(float _x1, float _x2)
{
    return _x2 - log10(_x1 + 1) - 2;
}
float F1_der_x1(float _x1, float _x2)
{
    return 1;
}
float F1_der_x2(float _x1, float _x2)
{
    return qSin(_x2);
}
float F2_der_x1(float _x1, float _x2)
{
    return -1/((_x1+1)*qLn(10));
}
float F2_der_x2(float _x1, float _x2)
{
    return 1;
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

