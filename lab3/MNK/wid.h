#ifndef WID_H
#define WID_H

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
#define N 6 //����������� �������� �������

using namespace std;

void NullMas(float _mas[N][N]); /// ��������� ����������� �������
float Function1(float _b[N], float _x); /// ������������� ��������� 1-�� �������
float Function2(float _b[N], float _x); /// ������������� ��������� 2-�� �������
float Determinant2x2(float _mas[N][N]); /// ���������� ������������ ������� 2�2
float Determinaton3x3(float _mas[N][N]); /// ���������� ������������ ������� 3�3
float F1(float _b[N], float _x[N], float _y[N]); /// ������� ��� ���������� ������� ��������
float F2(float _b[N], float _x[N], float _y[N]); /// ������� ��� ���������� ������� ��������
void InputMas(QString name1, float x[], float y[]); /// ���������� �� �����

#endif // WID_H
