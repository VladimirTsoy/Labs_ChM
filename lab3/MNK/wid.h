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
#define N 6 //Размерность исходной матрицы

using namespace std;

void NullMas(float _mas[N][N]); /// Обнуление двухмерного массива
float Function1(float _b[N], float _x); /// Аппроксимация полиномом 1-ой степени
float Function2(float _b[N], float _x); /// Аппроксимация полиномом 2-ой степени
float Determinant2x2(float _mas[N][N]); /// Вычисление определителя матрицы 2х2
float Determinaton3x3(float _mas[N][N]); /// Вычисление определителя матрицы 3х3
float F1(float _b[N], float _x[N], float _y[N]); /// Формула для построения первого полинома
float F2(float _b[N], float _x[N], float _y[N]); /// Формула для построения второго полинома
void InputMas(QString name1, float x[], float y[]); /// Считывание из файла

#endif // WID_H
