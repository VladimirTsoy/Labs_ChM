#include "wid.h"

void InputMas(double x[N][N], double y[N], QString name1)
{
    ifstream in;
    in.open(QFile::encodeName(name1).data());
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            in >> x[i][j];
        in >> y[i];
    }

}
void OutputAnswer(double a[N], int index, QString name2)
{
    ofstream out;
    out.open(QFile::encodeName(name2).data());
    out << "Answer\n";
    for(int i=0;i<N;i++)
    {
        if (abs(a[i]) < minimum)
            out << "x" << i+1 << " = 0\n";
        else
            out << "x" << i+1 << " = " << a[i] << "\n";
    }
    out << "\nNumber of itteration: " << index << "\n";
    out.close();
}

void Test(double _mas[N])
{
    for(int i=0;i<N;i++)
    {
        printf("%.2f\t",_mas[i]);
    }
}
void Test(double _mas[N][N], double y[N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(abs(_mas[i][j]) < minimum)
                printf("0.00\t");
            else
                printf("%.2f\t",_mas[i][j]);
        }
        printf("\t%.2f\n",y[i]);
    }
    printf("\n");
}
bool Converge(double _a[N], double _b[N], double accuracy)
{
    double temp[N];
    for(int i=0; i<N; i++)
    {
        temp[i] = _a[i] - _b[i];
    }
    double a = NormC_of_the_matrix(temp);
    if (a >= accuracy)
            return false;
    return true;
}
int Diagonal_dominance(double _mas[N][N])
{
    double a[N];
    NullMas(a);
    for (int i = 0;i<N;i++)
    {
        for (int j = 0;j<N;j++)
        {
            if(j!=i)
            {
                a[i] += abs(_mas[j][i]);
            }
        }
    }
    for (int k = 0; k<N; k++)
    {
        if(abs(_mas[k][k]) <= a[k])
            return 1;
    }
    return 0;
}
double NormC_of_the_matrix(double _mas[N])
{
    double r = abs(_mas[0]);
    for (int i = 1; i<N; i++)
    {
        if (r < abs(_mas[i]))
        {
            r = abs(_mas[i]);
        }
    }
    return r;
}
double NormC_of_the_matrix(double _mas[N][N])
{
    double a[N];
    NullMas(a);
    for (int i = 0;i<N;i++)
    {
        for (int j = 0;j<N;j++)
        {
            a[i] += abs(_mas[i][j]);
        }
    }
    double r = a[0];
    for (int k = 1; k<N; k++)
    {
        if (r < a[k])
            r = a[k];
    }
    return r;
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
