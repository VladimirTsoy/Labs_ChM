#ifndef WID_H
#define WID_H

#include <QFile>
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
#define N 4 //Размерность исходной матрицы

using namespace std;

float F(float _x); /// Исходная функция
float W(float _x[N], int _i); /// Вспомогательная функция для построения многочелена Лагранжа
float L(float _x[N], float _w[N], float _Xk); /// Многочлен Лагранжа
float FP(float _x[N], int _i, int _j); /// Рекурсивная функция для построения многочлена Ньютона
float P(float _x[N], float _Xk); /// Многочлен Ньютона
float InputMas(QString name1, float x[N]); /// Считывание из файла

#endif // WID_H
