#ifndef WID_H
#define WID_H

#include <QVector>
#include <QObject>
#include <qmath.h>
#include <QtGui/QFileDialog>
#include <QDebug>
#include <QtDebug>
#include <iostream>
#include <QByteArray>
#include <stdio.h>
#include "math.h"
#include <cmath>
#include <fstream>

#define pi 3.14159265358979323846264338327950288419716939937510
#define minimum 0.000000000000001
#define N 5 //����������� �������� �������

using namespace std;

void Assignment(float _mas[N-2], float _mas2[N-2]); /// ������� ������������ ������ ����������� ������� �������
void NullMas(float _mas[N], int n); /// ������� ��������� ������� �������� �����������
void SolveMatrix (float _a[N-2], float _c[N-2], float _b[N-2], float _f[N-2], float *x, int n); /// ����� ��������
float F(float _a, float _b, float _c, float _d, float _x, float _param); /// ������� �������� �������
float InputMas(QString name1, float Xk[N], float Fk[N], float h[N], float c[N], float b[N], float a[N], float f[N], int &_index); /// ���������� �� �����

#endif // WID_H
