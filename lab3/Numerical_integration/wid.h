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

float Function(float _x); /// ���� �������� �������
float Rectangles(QVector <float> _x, float _h, int _i); /// ����� �������������
float Trapezoids(QVector <float> _x, float _h, int _i); /// ����� ��������
float Simpson(QVector <float> _x, float _h, int _i); /// ����� ��������
float Accuracy1(float _Fh, float _Fkh, float _h1, float _h2); /// ��������� ��������������
float Accuracy2(float _Fh, float _Fkh, float _h1, float _h2); /// ���������� �����������

#endif // WID_H
