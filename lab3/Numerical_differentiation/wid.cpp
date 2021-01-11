#include "wid.h"

float InputMas(QString name1, float x[N], float y[N])
{
    float xk;
    ifstream in;
    in.open(QFile::encodeName(name1).data());
    in >> xk;
    for(int i=0;i<N;i++)
    {
            in >> x[i];
    }
    for(int i=0;i<N;i++)
    {
            in >> y[i];
    }
    in.close();
    return xk;
}
float Determinant2x2(float _mas[N][N])
{
    return _mas[0][0]*_mas[1][1] - _mas[0][1]*_mas[1][0];
}
float Determinaton3x3(float _mas[N][N])
{
    return _mas[0][0]*_mas[1][1]*_mas[2][2]+_mas[0][1]*_mas[1][2]*_mas[2][0]+_mas[1][0]*_mas[2][1]*_mas[0][2]-_mas[0][2]*_mas[1][1]*_mas[2][0]-_mas[0][1]*_mas[1][0]*_mas[2][2]-_mas[1][2]*_mas[2][1]*_mas[0][0];
}
float Function1(float _b[N], float _x)
{
    return _b[0] + _b[1]*_x;
}
float Function2(float _b[N], float _x)
{
    return _b[0] + _b[1]*_x + _b[2]*_x*_x;
}
float F1(float _b[N], float _x[N], float _y[N])
{
    float a = 0.0;
    for(int i=0; i<N; i++)
    {
        a += (Function1(_b, _x[i]) - _y[i])*(Function1(_b, _x[i]) - _y[i]);
    }
    return a;
}
float F2(float _b[N], float _x[N], float _y[N])
{
    float a = 0.0;
    for(int i=0; i<N; i++)
    {
        a += (Function2(_b, _x[i]) - _y[i])*(Function2(_b, _x[i]) - _y[i]);
    }
    return a;
}
