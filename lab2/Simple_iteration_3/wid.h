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
#define N 2 //Размерность исходной матрицы

using namespace std;

float Sign(float _a);/// Определение знака числа
float Fi1(float _x1, float _x2);/// Заданная функция 1
float Fi2(float _x1, float _x2);/// Заданная функция 2
float Fi1_der_x1(float _x1, float _x2);/// Производная функции 1 по х1
float Fi1_der_x2(float _x1, float _x2);/// Производная функции 1 по х2
float Fi2_der_x1(float _x1, float _x2);/// Производная функции 2 по х1
float Fi2_der_x2(float _x1, float _x2);/// Производная функции 2 по х2
bool CriterionTermination(float _xk[N], float _x[N], float _q, float accuracy); /// Проверка удовлетворения заданной точности

#endif // WID_H
