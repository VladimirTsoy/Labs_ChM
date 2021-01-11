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
void OutputAnswer(double x[N][N], double temp2[N][N], double y[N], int index, QString name2)
{
    ofstream out;
    out.open(QFile::encodeName(name2).data());
    out << "Matrix Lambda\n";
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
            if(abs(temp2[i][j]) < minimum)
                out << "0\t";
            else
                out << temp2[i][j] << "\t";
        }
        out << "\n";
    }
    out << "\nEigenvalues\n";
    for(int i=0;i<N;i++)
    {
        if (abs(y[i]) < minimum)
            out << "lambda" << i+1 << " = 0\n";
        else
            out << "lambda" << i+1 << " = " << y[i] << "\n";
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
    for(int i=0;i<N-1;i++)
    {
        if(abs(_mas[i]) < minimum)
            printf("0.00\t");
        else
            printf("%.2f\t",_mas[i]);
    }
    printf("\n\n");
}
void Proverka(double _mas[N][N])
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
    for(int i=0;i<N;i++)
        _mas2[i]=_mas[i][i];
}
int Symmetry(double _mas[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(_mas[i][j] != _mas[j][i])
                return 1;
        }
    }
    return 0;
}
bool CriterionTermination(double _mas[N][N], double accuracy)
{
    double a = 0.0;
    for (int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
            a += (_mas[i][j])*(_mas[i][j]);
    }
    qDebug("a = %f\t;\t\taccuracy = %f",qSqrt(a), accuracy);
    if (qSqrt(a) < accuracy)
        return true;
    return false;
}

void ChangeU(double _mas[N][N], int _i, int _j, double _fi)
{
    _mas[_i][_j] = -qSin(_fi);
    _mas[_j][_i] = qSin(_fi);
    _mas[_i][_i] = qCos(_fi);
    _mas[_j][_j] = qCos(_fi);
}
void MaxElement(double _mas[N][N], int &_i,int &_j)
{
    _i = 0; _j = 1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;(j<N);j++)
        {
            if((abs(_mas[_i][_j])<abs(_mas[i][j]))&&(i!=j))
            {
                _i = i;
                _j = j;
            }
        }
    }
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
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            _mas[i][j] = _mas2[i][j];
    }
}
void Assignment(double _mas[N], double _mas2[N])
{
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
