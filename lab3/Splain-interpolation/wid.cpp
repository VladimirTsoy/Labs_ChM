#include "wid.h"

float InputMas(QString name1, float Xk[N], float Fk[N], float h[N], float c[N], float b[N], float a[N], float f[N], int &_index)
{
    int index;
    float qwerty;
    ifstream in;
    in.open(QFile::encodeName(name1).data());
    in >> qwerty;
    for(int i=0;i<N;i++)
    {
            in >> Xk[i];
    }
    for(int i=0;i<N;i++)
    {
            in >> Fk[i];
    }
    for(int i=1; i<N; i++)
    {
        h[i] = Xk[i] - Xk[i-1];
    }
    for(int i=0; i<N-2; i++)
    {
        c[i] = 2*(h[i+1]+h[i+2]);
        b[i] = h[i+2];
        a[i] = h[i+1];
        f[i] = 3*(((Fk[i+2]-Fk[i+1])/h[i+2])-((Fk[i+1]-Fk[i])/h[i+1]));
    }
    for(int i=0; i<N-1; i++)
    {
        if((qwerty>Xk[i])&&(qwerty<Xk[i+1]))
            _index = i;
    }
    in.close();
    return qwerty;
}
float F(float _a, float _b, float _c, float _d, float _x, float _param)
{
    float answer = 0.0;
    float temp;
    for(int i=0; i<N-1;i++)
    {
        temp = 1.0;
        if(i==0)
            temp *= _a;
        if(i==1)
            temp *= _b;
        if(i==2)
            temp *= _c;
        if(i==3)
            temp *= _d;
        for(int j=0; j<i; j++)
            temp *= (_param-_x);
        answer += temp;
    }
    return answer;
}
void SolveMatrix (float _a[N-2], float _c[N-2], float _b[N-2], float _f1[N-2], float *x, int n)
{
    float _f[N-2];
    Assignment(_f, _f1);
        for (int i = 1; i < n; i++)
        {
                float m = _a[i]/_c[i-1];
                _c[i] = _c[i] - m*_b[i-1];
                _f[i] = _f[i] - m*_f[i-1];
        }

        x[n-1] = _f[n-1]/_c[n-1];

        for (int i = n - 2; i >= 0; i--)
                x[i]=(_f[i]-_b[i]*x[i+1])/_c[i];
}
void Assignment(float _mas[N-2], float _mas2[N-2])
{
    NullMas(_mas, N-2);
    for(int i=0;i<N-2;i++)
    {
            _mas[i] = _mas2[i];
    }
}
void NullMas(float _mas[N], int n)
{
    for(int i=0;i<n;i++)
    {
            _mas[i] = 0.0;
    }
}
