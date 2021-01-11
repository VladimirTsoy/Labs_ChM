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

void Assignment(QVector<float> _mas, QVector<float> _mas2); /// ������������ ������������ ���� ��������
void NullMas(QVector<float> _mas, float n); /// ��������� ������� �������� �����������
void SolveMatrix (QVector<float> _a, QVector<float> _c, QVector<float> _b, QVector<float> _f, QVector<float> &_x); /// ����� ��������
bool Diagonal_dominance(QVector<float> _a, QVector<float> _c, QVector<float> _b); /// �������� �� ������������ ������������
float Fy(float _z); /// y' = z
float Fz(float _x, float _y); /// ��������� �������� �������
float Ftrue(float _x ); /// ������ ��������
float Accuracy(float _y1, float _y2); /// ���������� �����������

#endif // WID_H
