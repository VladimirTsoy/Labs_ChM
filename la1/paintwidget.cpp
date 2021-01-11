#include <QPainter>
#include <QtGui/QFileDialog>
#include <QPen>
#include <QDebug>
#include <QtDebug>
#include <iostream>
#include <QByteArray>

#include "paintwidget.h"
#include <stdio.h>
#include <cmath>
#include <fstream>

using namespace std;

PaintWidget::PaintWidget(QVector < QLineEdit *> &arr_L, QVector < QLineEdit *> &arr_U, QVector < QLineEdit *> &arr_b, QVector < QLineEdit *> &arr_inverse, QVector < KeyLine *> &arr_input, QWidget *_parent /*= 0*/) :
        QWidget(_parent)
{
    // установка цвета фона
        QPalette palette;
        palette.setColor( backgroundRole(), Qt::yellow);
        setPalette(palette);
        setAutoFillBackground(true);
        NullMas(x);
        NullMas(temp);
        NullMas(temp2);
        NullMas(u);
        NullMas(y);
        NullMas(l);
        NullMas(p);
        NullMas(inv);
        IdentityMas(l);
        IdentityMas(p);
        name1 = "input.txt";
        name2 = "output.txt";

        this->arr_L = arr_L;
        this->arr_U = arr_U;
        this->arr_b = arr_b;
        this->arr_inverse = arr_inverse;
        this->arr_input = arr_input;
}
void PaintWidget::ChangeName1( const QString & _text )
{
            if(!_text.isEmpty())
            {
                name1 = _text;
            }
}
void PaintWidget::ChangeName2( const QString & _text )
{
            if(!_text.isEmpty())
            {
                name2 = _text;
            }
}
void PaintWidget::InputMas()
{
    ifstream in;
    in.open(QFile::encodeName(name1).data());
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            in >> x[i][j];
        in >> y[i];
    }
    if(N < maximum)
        PrintArr(arr_input, x, y);
    in.close();
}
void PaintWidget::OutputAnswer()
{
    ofstream out;
    out.open(QFile::encodeName(name2).data());
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
void PaintWidget::ChangeX( const QString & _text )
{
                if(!_text.isEmpty())
                {

                    KeyLine *pLineEdit = (KeyLine *)sender();
                    qDebug("%d",pLineEdit->myDigit);
                    //emit digitClicked(button->text()[0].digitValue());

                    if((pLineEdit->myDigit+1)%(N+1)==0)
                        y[(pLineEdit->myDigit/N+1)-2] = _text.toDouble();
                    else
                        x[pLineEdit->myDigit/(N+1)][pLineEdit->myDigit%(N+1)] = _text.toDouble();
//                    for(int i=0;i<N;i++)
                        //qDebug("%.2f\t%.2f\t%.2f\t%.2f\t\t%.2f",x[i][0],x[i][1],x[i][2],x[i][3],y[i]);
                }
}
void PaintWidget::Test(double _mas[N][N])
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
void PaintWidget::Test(double _mas[N])
{
    printf("\tTest\n");
    for(int i=0;i<N;i++)
    {
        if(abs(_mas[i]) < minimum )
            printf("0.00\t");
        else
            printf("%.2f\t",_mas[i]);
    }
    printf("\n\n");
}
void PaintWidget::Action()
{
    index = 0.0;
    PLU(x,l,u,p,y);

    if(N < maximum)
    {
        PrintArr(arr_L, l);
        PrintArr(arr_U, u);
    }
    Determinant(u, arr_b);

    MultiMas(l, u, temp);
    Test(temp);
    Test(p);

    PLUinverse(u, y);
    Test(y);
    if(N < maximum)
        PrintArr(arr_b, y);

    MultiMas(x, y, temp2);
    Test(temp2);

    for(int i=0;i<N;i++)
    {
        NullMas(I);
        I[i] = 1.0;

        NullMas(l);
        IdentityMas(l);

        NullMas(u);

        NullMas(p);
        IdentityMas(p);

        PLU(x, l, u, p, I);
        PLUinverse(u, I);

        for(int j=0;j<N;j++)
        {
            inv[j][i] = I[j];
        }
    }
    if(N < maximum)
        PrintArr(arr_inverse, inv);
    NullMas(temp);

    MultiMas(x, inv, temp);
    Test(temp);
}
void PaintWidget::PLUinverse(double _u[N][N], double _y[N])
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
void PaintWidget::PLU(double _x[N][N], double _l[N][N], double _u[N][N], double _p[N][N], double _y[N])
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
        SwapRows(_p, number, i);
        SwapRows(_u, number, i);
        SwapRows(_y, number, i);

        //Transp(_p);
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
void PaintWidget::Transp(double _mas[N][N])
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
void PaintWidget::SwapRows(double _mas[N], int _i, int _j)
{
        double temp;
            temp = _mas[_i];
            _mas[_i] = _mas[_j];
            _mas[_j] = temp;
}
void PaintWidget::SwapRows(double _mas[N][N], int _i, int _j)
{
        double temp;
        for(int k=0;k<N;k++)
        {
            temp = _mas[_i][k];
            _mas[_i][k] = _mas[_j][k];
            _mas[_j][k] = temp;
        }
}
void PaintWidget::Assignment(double _mas[N][N], double _mas2[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            _mas[i][j] = _mas2[i][j];
    }
}
void PaintWidget::Assignment(double _mas[N], double _mas2[N])
{
    for(int i=0;i<N;i++)
    {
            _mas[i] = _mas2[i];
    }
}
void PaintWidget::Determinant(double _mas[N][N], QVector < QLineEdit *> & _arr)
{
    double a = 1.0;
    for(int j=0;j<index-N;j++)
    {
        a *= (-1.0);
    }
    qDebug("%d", index);
    for(int i=0;i<N;i++)
        a *= _mas[i][i];
    if(N < maximum)
        _arr[N]->setText(QString::number(a));
    else
        _arr[0]->setText(QString::number(a));
}
void PaintWidget::PrintArr(QVector < QLineEdit *> & _arr, double _mas[N][N])
{
    int k=0.0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(abs(_mas[i][j]) < minimum)
                    _arr[k++]->setText(QString::number(0.0));
                else
                    _arr[k++]->setText(QString::number(_mas[i][j]));
            }
        }
}
void PaintWidget::PrintArr(QVector < QLineEdit *> & _arr, double _mas[N])
{
    for(int i=0;i<N;i++)
    {
        if(abs(_mas[i]) < minimum)
            _arr[i]->setText(QString::number(0.0));
        else
            _arr[i]->setText(QString::number(_mas[i]));
    }
}
void PaintWidget::PrintArr(QVector < KeyLine *> & _arr, double _mas2[N][N], double _mas[N])
{
    int k=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
                _arr[k++]->setText(QString::number(_mas2[i][j]));
        }
        _arr[k++]->setText(QString::number(_mas[i]));
    }
}
void PaintWidget::NullMas(double _mas[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            _mas[i][j] = 0.0;
        }
    }
}
void PaintWidget::NullMas(double _mas[N])
{
    for(int i=0;i<N;i++)
    {
            _mas[i] = 0.0;
    }
}
void PaintWidget::IdentityMas(double _mas[N][N])
{
    for(int i=0;i<N;i++)
    {
        _mas[i][i] = 1.0;
    }
}
void PaintWidget::MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N])
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
void PaintWidget::MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N])
{
    for(int i=0;i<N;i++)
    {
            for(int k=0;k<N;k++)
                _mas3[i] += (_mas[i][k])*(_mas2[k]);
    }
}
void PaintWidget::Refreash()
{
    NullMas(l);
    IdentityMas(l);
    NullMas(x);
    NullMas(temp);
    NullMas(temp2);
    NullMas(u);
    NullMas(y);
    NullMas(inv);
    NullMas(p);
    IdentityMas(p);

    PrintArr(arr_input, x, y);
    PrintArr(arr_U, u);
    PrintArr(arr_L, l);
    PrintArr(arr_b, y);
    PrintArr(arr_inverse, inv);
    arr_b[N]->setText(QString::number(0));
    qDebug("------------------------------");
}
