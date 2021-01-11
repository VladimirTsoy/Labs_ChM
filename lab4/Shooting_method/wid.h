#ifndef WID_H

#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QVector>
#include <QObject>
#include <qmath.h>
//#include <nrutil.h>

#define pi 3.14159265358979323846264338327950288419716939937510
#define minimum 0.000000000000001
#define N 5 //����������� �������� �������

class PaintWidget : public QWidget
{
    Q_OBJECT

public:
       QVector < QLineEdit * > arr_b;
       PaintWidget(QVector < QLineEdit *> &arr_b, QWidget *_parent = 0);

       void Test(float _mas[N][N]);
       void Test(float _mas[N]);
       void Assignment(float _mas[N][N], float _mas2[N][N]);
       void Assignment(QVector<float> _mas, QVector<float> _mas2);
       void Transp(float _mas[N][N]);
       void NullMas(float _mas[N][N]);
       void NullMas(QVector<float> _mas, float n);
       void IdentityMas(float _mas[N][N]);
       void MultiMas(float _mas[N][N], float _mas2[N][N], float _mas3[N][N]);
       void MultiMas(float _mas[N][N], float _mas2[N], float _mas3[N]);
       float Fy(float _z);
       float Fz(float _x, float _y);
       float Ftrue(float _x);
       float Accuracy(float _y1, float _y2);
       float Sign(float _a);
       bool CriterionTermination(float _F);

public slots:
    /// ���� - ���������� ��� ��������� ������ � QLineEdit, ��������� � ������� QObject::connect
        void ChangeName1( const QString & _text );
        void ChangeName2( const QString & _text );
        void InputMas();
        void Action();
        void Refreash();

private:
        int index;
        float x0, y0, x1, y1, h, size, eps;
        QString name1, name2;
};

#endif // PAINTWIDGET_H

//#define WID_H

//#include <QVector>
//#include <QObject>
//#include <qmath.h>
//#include <QtGui/QFileDialog>
//#include <QDebug>
//#include <QtDebug>
//#include <iostream>
//#include <QByteArray>
//#include <stdio.h>
//#include "math.h"
//#include <cmath>
//#include <fstream>

//#define pi 3.14159265358979323846264338327950288419716939937510
//#define minimum 0.000000000000001
//#define N 5 //����������� �������� �������

//using namespace std;

//void Assignment(QVector<float> _mas, QVector<float> _mas2); /// ������������ ������ ������������� ������� �������
//void NullMas(QVector<float> _mas, float n); /// ��������� ������������� �������
//float Fy(float _z); /// y' = z
//float Fz(float _x, float _y, float _z); /// ��������� ������� � ������� ������ y' = z
//float Ftrue(float _x); /// ������ �������� �������
//float Accuracy(float _y1, float _y2); /// ���������� �����������
//bool CriterionTermination(float _F, float eps); /// �������� ���������� �������� (eps = 0.0001)

//#endif // WID_H
