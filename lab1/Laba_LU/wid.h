#ifndef WID_H
#define WID_H
#include <QtCore/QCoreApplication>
//#include <QFile>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define minimum 0.0000000001
#define N 4
//double x[N][N], y[N], l[N][N], u[N][N], p[N][N], inv[N][N], temp[N][N], temp2[N], I[N];
//int index;
//QString name1, name2;
void Test2(double _mas[N][N]);/// Вывод на консоль двумерного массива
void Test1(double _mas[N]);/// Вывод на консоль одномерного массива
void PLU(double _x[N][N], double _l[N][N], double _u[N][N], double _p[N][N], double _y[N], int index);/// LU разложение с матрицей перестановок P
void PLUinverse(double _u[N][N], double _y[N]);/// Вычиляет корни после LU разложения
void SwapRows(double _mas[N][N], int _i, int _j);/// Меняет местами строки в двумерном массиве
void SwapRows(double _mas[N], int _i, int _j);/// Меняет местами элементы в одномерном массиве
void Assignment(double _mas[N][N], double _mas2[N][N]); /// Поэлементное присвание двумерных массивов
void Assignment(double _mas[N], double _mas2[N]);/// Поэлементное присванивание одномерных массивов
void Determinant(double _mas[N][N], int index);/// Подсчёт определителя матрицы после LU разложения
void NullMas(double _mas[N][N]);/// Обнуление двумерного массива
void NullMas(double _mas[N]);/// Обнуление одномерного массива
void IdentityMas(double _mas[N][N]);/// Создание еденичной матрицы
void MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N]);/// Перемножение матриц
void MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N]);/// Перемножение матрицы на вектор столбец
void InputMas(double x[N][N], double y[N], char *name1);/// Считывание данных из файла
void OutputAnswer(double l[N][N], double u[N][N], double p[N][N], double inv[N][N], double y[N], char *name2);/// Вывод данных(ответов) в файл
#endif // WID_H
