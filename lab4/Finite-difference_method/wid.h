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

void Assignment(QVector<float> _mas, QVector<float> _mas2); /// Поэлементное присваивание двух векторов
void NullMas(QVector<float> _mas, float n); /// Обнуление вектора заданной размерности
void SolveMatrix (QVector<float> _a, QVector<float> _c, QVector<float> _b, QVector<float> _f, QVector<float> &_x); /// Метод прогонки
bool Diagonal_dominance(QVector<float> _a, QVector<float> _c, QVector<float> _b); /// Проверка на диагональное преобладание
float Fy(float _z); /// y' = z
float Fz(float _x, float _y); /// Выражение заданной функции
float Ftrue(float _x ); /// Точное значение
float Accuracy(float _y1, float _y2); /// Вычисление погрешности

#endif // WID_H
