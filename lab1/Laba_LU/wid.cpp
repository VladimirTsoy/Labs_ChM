#include "wid.h"

void InputMas(double x[N][N], double y[N], char *name1)
{
    ifstream in;
    in.open(name1);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            in >> x[i][j];
        in >> y[i];
    }
//    if(N < maximum)
        //PrintArr(arr_input, x, y);
    in.close();
}

void OutputAnswer(double l[N][N], double u[N][N], double p[N][N], double inv[N][N], double y[N], char *name2)
{
    ofstream out;
    out.open(name2);
    out << "Matrix L\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(abs(l[i][j]) < minimum)
                out << "0\t";
            else
                out << l[i][j] << "\t";
        }
        out << "\n";
    }
    out << "\nMatrix U\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(abs(u[i][j]) < minimum)
                out << "0\t";
            else
                out << u[i][j] << "\t";
        }
        out << "\n";
    }
    out << "\nMatrix P\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(abs(p[i][j]) < minimum)
                out << "0\t";
            else
                out << p[i][j] << "\t";
        }
        out << "\n";
    }
    out << "\nMatrix inverse\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(abs(inv[i][j]) < minimum)
                out << "0\t";
            else
                out << inv[i][j] << "\t";
        }
        out << "\n";
    }
    out << "\nAnswer\n";
    for(int i=0;i<N;i++)
    {
        if(abs(y[i]) < minimum)
            out << "x" << i+1 << " = 0\n";
        else
            out << "x" << i+1 << " = " << y[i] << "\n";
    }
    out.close();
}

void Test2(double _mas[N][N])//вывод на консоль 2х
{                             //мерного массива
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

void Test1(double _mas[N])//вывод на консоль одномерного массива
{
    for(int i=0;i<N;i++)
    {
        if(abs(_mas[i]) < minimum )
            printf("0.00\t");
        else
            printf("%.2f\t",_mas[i]);
    }
    printf("\n\n");
}
void PLUinverse(double _u[N][N], double _y[N])
{
    double a[ N ];
    NullMas(a);
    _y[N-1] /= _u[N-1][N-1];
    for( int i = N-2; i > -1; i-- )
    {
        for( int j = i+1; j < N; j++ )
        {
            a[ i ] += _u[ i ][ j ] * _y[ j ];
        }
        _y[ i ] = ( _y[ i ] - a[ i ]) / _u [ i ][ i ];
    }
}
void PLU(double _x[N][N], double _l[N][N], double _u[N][N], double _p[N][N], double _y[N], int index)
{
    Assignment(_u, _x);

    for( int i = 0; i < N; i++ )
    {
        //поиск главного элемента
        double element = 0.0;
        int number = -1.0;
        for( int ind = i; ind < N; ind++ )
        {
            if( fabs(_u[ ind ][ i ]) > element )
            {
                element = fabs(_u[ ind ][ i ]);
                number = ind;
                index++;
            }
        }
        if( element == 0 )
        {
            qDebug("The matrix is singular !");
        }

        //меняем местами i-ю строку и строку с главным элементом
        SwapRows(_p, number, i);// Для матрицы перестановок P
        SwapRows(_u, number, i);//Для матрицы U
        SwapRows(_y, number, i);// Для матрицы Y

        for( int j = i+1; j < N; j++ )
        {
            _l[ j ][ i ] = _u[ j ][ i ] / _u[ i ][ i ];
            _u[ j ][ i ] = 0.0;
            for( int k = i+1; k < N; k++ )
            {
                _u[ j ][ k ] -= _l[ j ][ i ] * _u[ i ][ k ];
            }
            _y [ j ] -= _l[ j ][ i ] * _y[ i ];
        }
    }
}


void SwapRows(double _mas[N], int _i, int _j)// замена строк местами
{
        double temp;
            temp = _mas[_i];
            _mas[_i] = _mas[_j];
            _mas[_j] = temp;
}
void SwapRows(double _mas[N][N], int _i, int _j)// замена строк местами
{
        double temp;
        for(int k=0;k<N;k++)
        {
            temp = _mas[_i][k];
            _mas[_i][k] = _mas[_j][k];
            _mas[_j][k] = temp;
        }
}
 //присваивание массивов
void Assignment(double _mas[N][N], double _mas2[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            _mas[i][j] = _mas2[i][j];
    }
}

//присваивание массивов
void Assignment(double _mas[N], double _mas2[N])
{
    for(int i=0;i<N;i++)
    {
            _mas[i] = _mas2[i];
    }
}

void Determinant(double _mas[N][N], int index)
{
    double a = 1.0;
    for(int j=0;j<index-N;j++)
    {
        a *= (-1.0);
    }
    //qDebug("%d", index);
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

void IdentityMas(double _mas[N][N])//создание еденичной матрицы
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
