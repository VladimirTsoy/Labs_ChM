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

float Sign(float _a); /// Определение знака числа
float Function(float _x); /// Заданная функция
float Derivative(float _x); /// Производная функции
float Second_derivative(float _x); /// Вторая производная функции
bool CriterionTermination(float _xk, float _x, float accuracy); /// Проверка удовлетворения заданной точности

#endif // WID_H
