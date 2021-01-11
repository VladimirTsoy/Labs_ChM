#include "wid.h"

void InputMas(double x[N][N], QString name1)
{
    ifstream in;
    in.open(QFile::encodeName(name1).data());
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            in >> x[i][j];
    }
    in.close();
}
void OutputAnswer(double x[N][N], double q[N][N], double y[N], double re[N], double im[N], int index, QString name2)
{
    ofstream out;
    out.open(QFile::encodeName(name2).data());
    out << "Matrix R * Q\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(abs(x[i][j]) < minimum)
                out << "0\t";
            else
                out << x[i][j] << "\t";
        }
        out << "\n";
    }
    out << "\nMatrix Own Vectors\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(abs(q[i][j]) < minimum)
                out << "0\t";
            else
                out << q[i][j] << "\t";
        }
        out << "\n";
    }
    out << "\nEigenvalues\n";
    for(int i=0;i<N;i++)
    {
        if((abs(re[i]) < minimum)&&(abs(im[i]) < minimum))
        {
            if(abs(y[i]) < minimum)
                out << "lambda" << i+1 << " = 0\n";
            else
                out << "lambda" << i+1 << " = " << y[i] << "\n";
        }
        else
        {
            if(im[i] < 0.0)
                out << "lambda" << i+1 << " = " << re[i] << " - " << abs(im[i]) << "*i\n";
            else
                out << "lambda" << i+1 << " = " << re[i] << " + " << abs(im[i]) << "*i\n";
        }
    }
    out << "\nNumber of itteration: " << index;
    out.close();
}
void Test(double _mas[N][N])
{
    printf("\tTest\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(abs(_mas[i][j]) < minimum)
                printf("0.00\t");
            else
                printf("%.2f\t",_mas[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void Test(double _mas[N])
{
    printf("\tTest\n");
    for(int i=0;i<N;i++)
    {
        if(abs(_mas[i]) < minimum)
            printf("0.00\t");
        else
            printf("%.2f\t",_mas[i]);
    }
    printf("\n\n");
}
void QR(double _x[N][N], double _q[N][N])
{
    double v[N], xn[N][N], h[N][N], hn[N][N];
    NullMas(_q);
    IdentityMas(_q);
    for(int i=0;i<N;i++)
    {
        NullMas(v);
        NullMas(h);
        Assignment(xn, _x);
        Assignment(h, _q);
        for(int j=0;j<N;j++)
        {
            if(j == i)
                v[j] = xn[j][i] + Sign(xn[j][i])*NormVector(xn, i);
            else if(j < i)
                v[j] = 0.0;
            else
                v[j] = xn[j][i];
        }
        ChangeH(v, hn);
        MultiMas(hn, xn, _x);
        MultiMas(h, hn, _q);
    }
}
void ChangeH(double _mas[N],double _mas2[N][N])
{
    double vtv, e[N][N], vvt[N][N];
    NullMas(e);
    IdentityMas(e);
    vtv = MultiVector1(_mas);
    MultiVector2(_mas, vvt);
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            _mas2[i][j] = e[i][j] - 2.0*vvt[i][j]/vtv;
    }
}
void MultiVector2(double _mas[N], double _mas2[N][N])
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            _mas2[i][j] = _mas[i] * _mas[j];
    }
}
double MultiVector1(double _mas[N])
{
    double a = 0.0;
    for (int i=0; i<N; i++)
        a += _mas[i] * _mas[i];
    return a;
}
double NormVector(double _mas[N][N], int _j)
{
    double a = 0.0;
    for (int i=_j; i<N; i++)
    {
        a += _mas[i][_j] * _mas[i][_j];
    }
    return qSqrt(a);
}
double Sign(double _a)
{
    if (_a < 0)
        return -1.0;
    else if (_a == 0)
        return  0.0;
    else
        return 1.0;
}
void Proverka(double _x[N][N],double _q[N][N], double temp[N][N], double temp2[N][N])
{
    MultiMas(_q, _x, temp);
    Test(temp);
    Assignment(temp, _q);
    Transp(temp);
    MultiMas(_q, temp, temp2);
    Test(temp2);
}
void Proverka2(double _mas[N][N])
{
    double _mas2[N];
    NullMas(_mas2);
    for(int i=0;i<N-1;i++)
    {
        for (int j=0;j<N;j++)
            _mas2[i] += _mas[j][i]*_mas[j][i+1];
    }
    Test(_mas2);
}
void Eigenvalues(double _mas[N][N], double _mas2[N])
{
    for(int i=0;i<N-1;i++)
    {
        if(Discriminant(_mas, i) > 0.0)
        {
            _mas2[i] = _mas[i][i];
            if(i==N-2)
                _mas2[i+1] = _mas[i+1][i+1];
        }
    }
}
void Complex(double _x[N][N], double _re[N], double _im[N])
{
    for(int i=0;i<N-1;i++)
    {
        if(Discriminant(_x, i) < 0.0)
        {
            _re[i] = 0.5 * (_x[i][i] + _x[i+1][i+1]);
            _re[i+1] = 0.5 * (_x[i][i] + _x[i+1][i+1]);
            _im[i] = 0.5 * qSqrt(0.0 - Discriminant(_x, i));
            _im[i+1] = 0.0 - 0.5 * qSqrt(0.0 - Discriminant(_x, i));
        }
    }
}
bool CriterionTermination(double _mas[N][N], double _re[N], double _im[N], double _ren[N], double _imn[N], double accuracy)
{
    double a;
    for (int i=0;i<N-1;i++)
    {
        a = 0.0;
        for(int j=i+1;j<N;j++)
            a += (_mas[j][i])*(_mas[j][i]);
        qDebug("a = %f\t;\t\taccuracy = %f",qSqrt(a), accuracy);
        if (qSqrt(a) < accuracy)
            return true;
        qDebug("Discriminant: %f",Discriminant(_mas, i));
        if(Discriminant(_mas, i) < 0.0)
        {
            qDebug("b = %f",qSqrt((_re[i] - _ren[i])*(_re[i] - _ren[i]) + (_im[i] - _imn[i])*(_im[i] - _imn[i])));
            if(qSqrt((_re[i] - _ren[i])*(_re[i] - _ren[i]) + (_im[i] - _imn[i])*(_im[i] - _imn[i])) < accuracy)
                return true;
        }
    }
    qDebug("---------------");
    return false;
}
double Discriminant(double _mas[N][N], int _i)
{
    return (_mas[_i][_i]+_mas[_i+1][_i+1])*(_mas[_i][_i]+_mas[_i+1][_i+1]) - 4 * ((_mas[_i][_i]*_mas[_i+1][_i+1]) - (_mas[_i][_i+1]*_mas[_i+1][_i]));
}
void Transp(double _mas[N][N])
{
    double temp;
    for (int i=0; i<N; i++)
    {
        for(int j=i; j<N; j++)
        {
            temp = _mas[i][j];
            _mas[i][j] = _mas[j][i];
            _mas[j][i] = temp;
        }
    }
}
void SwapRows(double _mas[N], int _i, int _j)
{
        double temp;
            temp = _mas[_i];
            _mas[_i] = _mas[_j];
            _mas[_j] = temp;
}
void SwapRows(double _mas[N][N], int _i, int _j)
{
        double temp;
        for(int k=0;k<N;k++)
        {
            temp = _mas[_i][k];
            _mas[_i][k] = _mas[_j][k];
            _mas[_j][k] = temp;
        }
}
void Assignment(double _mas[N][N], double _mas2[N][N])
{
    NullMas(_mas);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            _mas[i][j] = _mas2[i][j];
    }
}
void Assignment(double _mas[N], double _mas2[N])
{
    NullMas(_mas);
    for(int i=0;i<N;i++)
    {
            _mas[i] = _mas2[i];
    }
}
void NullMas(double _mas[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            _mas[i][j] = 0.0;
        }
    }
}
void NullMas(double _mas[N])
{
    for(int i=0;i<N;i++)
    {
            _mas[i] = 0.0;
    }
}
void IdentityMas(double _mas[N][N])
{
    for(int i=0;i<N;i++)
    {
        _mas[i][i] = 1.0;
    }
}
void MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            _mas3[i][j] = 0;
            for(int k=0;k<N;k++)
                _mas3[i][j] += (_mas[i][k])*(_mas2[k][j]);
        }
    }
}
void MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N])
{
    for(int i=0;i<N;i++)
    {
            for(int k=0;k<N;k++)
                _mas3[i] += (_mas[i][k])*(_mas2[k]);
    }
}
