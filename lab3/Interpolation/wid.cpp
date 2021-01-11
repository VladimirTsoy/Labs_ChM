#include "wid.h"

float InputMas(QString name1, float x[N])
{
    float a;
    ifstream in;
    in.open(QFile::encodeName(name1).data());
    in >> a;
    for(int i=0;i<N;i++)
    {
            in >> x[i];
    }
    in.close();
    return a;
}
float P(float _x[N], float _Xk)
{
    float a = 0.0;
    float b = 1.0;
    for(int i=0; i<N; i++)
    {
         b = FP(_x, 0, i);
         for(int j=0; j<i+1;j++)
         {
             if(i!=j)
                b *= (_Xk-_x[j]);
         }
         a+=b;
    }
    return a;
}
float FP(float _x[N], int _i, int _j)
{
    float a = 0.0;
    if(_j>0)
        a = (FP(_x,_i,_j-1)-FP(_x,_i+1,_j-1))/(_x[_i]-_x[_i+_j]);
    else if(_j == 0)
        a = F(_x[_i]);
    return a;
}
float L(float _x[N], float _w[N], float _Xk)
{
    float a = 0.0;
    float b = 1.0;
    for(int i=0; i<N; i++)
    {
         b = F(_x[i])/_w[i];
         for(int j=0; j<N;j++)
         {
             if(i!=j)
                b *= (_Xk-_x[j]);
         }
         a+=b;
    }
    return a;
}
float W(float _x[N], int _i)
{
    float a = 1.0;
    for( int i=0; i<N; i++)
    {
        if(i!=_i)
            a *= _x[_i]-_x[i];
    }
    return a;
}
float F(float _x)
{
//    return qExp(_x);
    return qLn(_x);
//    return qSin(M_PI*_x/6);
}
