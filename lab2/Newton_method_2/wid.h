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

using namespace std;

#define pi 3.14159265358979323846264338327950288419716939937510
#define minimum 0.000000000000001
#define N 2 //����������� �������� �������


float Sign(float _a);/// ����������� ����� �����
float Function1(float _x1, float _x2);/// �������� ������� 1
float Function2(float _x1, float _x2);/// �������� ������� 2
float F1_der_x1(float _x1, float _x2);/// ����������� ������� 1 �� �1
float F1_der_x2(float _x1, float _x2);/// ����������� ������� 1 �� �2
float F2_der_x1(float _x1, float _x2);/// ����������� ������� 2 �� �1
float F2_der_x2(float _x1, float _x2);/// ����������� ������� 2 �� �2
bool CriterionTermination(float _xk[N], float _x[N], float accuracy);/// �������� �������������� �������� ��������
float Determinant(float _mas[N][N]);/// ���������� ������������

#endif // WID_H
