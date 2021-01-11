#include "wid.h"


bool CriterionTermination(float _F, float eps)
{
    if(abs(_F) <= eps)
        return true;
    return false;
}
float Fy(float _z)
{
    return _z;
}
float Fz(float _x, float _y,float _z)
{
    return (_y-(_x-3)*_z)/(_x*_x-1);
}
float Ftrue(float _x)
{
    return (6*_x-18);
}
float Accuracy(float _y2, float _y1)
{
    return ((_y2-_y1)/((2*2*2*2)-1));
}



