#ifndef WID_H
#define WID_H

//#include <QVector>
#include <vector>
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
#define minimum 0.00000001
#define N 5 //Размерность исходной матрицы

using namespace std;

float Fy(float _z); /// z=y'
float Fz(float _x, float _y, float _z);/// выражение для y''
float Ftrue(float _x);/// точное решение уравнения
float Accuracy(float _y1, float _y2);/// Подсчёт точности
bool CriterionTermination(float _F, float eps);/// критерий окончания

#endif // WID_H
