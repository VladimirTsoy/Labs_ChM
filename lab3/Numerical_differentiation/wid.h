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
#define N 5 //Размерность исходной матрицы

using namespace std;

float Function1(float _b[N], float _x);
float Function2(float _b[N], float _x);
float Determinant2x2(float _mas[N][N]);
float Determinaton3x3(float _mas[N][N]);
float F1(float _b[N], float _x[N], float _y[N]);
float F2(float _b[N], float _x[N], float _y[N]);
float InputMas(QString name1, float x[N], float y[N]);

#endif // WID_H
