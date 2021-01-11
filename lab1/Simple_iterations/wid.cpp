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
void OutputAnswer(double a[N], QString name2, int index)
{
    ofstream out;
    out.open(QFile::encodeName(name2).data());
    out << "Answer\n";
    for(int i=0;i<N;i++)
    {
        if(abs(a[i]) < minimum)
            out << "x" << i+1 << " = 0\n";
        else
            out << "x" << i+1 << " = " << a[i] << "\n";
    }
    out << "\nNumber of itteration: " << index << "\n";
    out.close();
}
void Test(double _mas[N][N], double y[N])
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
        printf("\t%.2f\n",y[i]);
    }
    printf("\n");
}

bool Change_accuracy(double _x[N][N], double _y1[N], double _y2[N], double accuracy)
{
    double temp[N];
    for(int i=0; i<N; i++)
    {
        temp[i] = _y1[i] - _y2[i];
    }
    double a = NormC_of_the_matrix(temp);
    double b = NormC_of_the_matrix(_x);
    if ((b/(1-b))*a >= accuracy)
        return false;
    else
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
 //       qDebug("%f\t%f",abs(_mas[k][k]),a[k]);
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
void Jacobi_method(double _x[N][N], double _y[N])
{
    double a[N][N];
    double b[N];
    for (int i=0;i<N;i++)
    {
        if ( (_x[i][i] == 0.0)&&(i!=N-1))
            SwapRows(_x, i, i+1);
        b[i] = _y[i] / _x[i][i];
        for(int j=0;j<N;j++)
        {
            if(j!=i)
                a[i][j] = - (_x[i][j] / _x[i][i]);
            else
                a[i][j] = 0.0;
        }
    }
    Assignment(_x, a);
    Assignment(_y, b);
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
void Determinant(double _mas[N][N])
{
    double a = 1.0;
    for(int j=0;j<N+1;j++)
    {
        a *= (-1.0);
    }
    for(int i=0;i<N;i++)
        a *= _mas[i][i];
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
