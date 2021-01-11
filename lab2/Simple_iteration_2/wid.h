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
#include <qmath.h>
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
float Fi(float _x); /// Функция fi
float Fi_der(float _x); /// Производная функции fi
float Fi_sec_der(float _x); /// Вторая производная функции fi
bool CriterionTermination(float _xk, float _x, float _q, float accuracy); /// Проверка удовлетворения заданной точности

#endif // WID_H
