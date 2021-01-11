#ifndef WID_H
#define WID_H

#include <QVector>
#include <QObject>
#include <qmath.h>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <QtGui/QFileDialog>
#include <QDebug>
#include <QtDebug>
#include <iostream>
#include <QByteArray>

using namespace std;

#define pi 3.14159265358979323846264338327950288419716939937510
#define minimum 0.00001
#define N 3 //Размерность исходной матрицы

void Test(double _mas[N][N]);/// Вывод на консоль двумерного массива
void Test(double _mas[N]);/// Вывод на консоль одномерного массива
void SwapRows(double _mas[N][N], int _i, int _j);/// Меняет местами строки в двумерном массиве
void SwapRows(double _mas[N], int _i, int _j);/// Меняет местами элементы в одномерном массиве
void Assignment(double _mas[N][N], double _mas2[N][N]);/// Поэлементное присванивание двумерных массивов
void Assignment(double _mas[N], double _mas2[N]);/// Поэлементное присванивание одномерных массивов
void Transp(double _mas[N][N]);/// Транспонирование матриц
void NullMas(double _mas[N][N]);/// Обнуление двумерного массива
void NullMas(double _mas[N]);/// Обнуление одномерного массива
void IdentityMas(double _mas[N][N]);/// Создание еденичной матрицы
void MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N]);/// Перемножение матриц
void MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N]);/// Перемножение матрицы на вектор столбец
void MaxElement(double _mas[N][N], int &_i, int &_j);/// Поиск максимального элемента
void ChangeU(double _mas[N][N], int _i, int _j, double _fi); /// Создание матрицы вращений
bool CriterionTermination(double _mas[N][N], double accuracy);/// Проверка удовлетворения заданному критерию точности
int Symmetry(double _mas[N][N]);/// Проверка на симметричность исходной матрицы
void Eigenvalues(double _mas[N][N], double _mas2[N]);/// Выделение собственных значений из матрицы
void Proverka(double _mas[N][N]);/// Проверка на ортогональность собственных векторов
void InputMas(double x[N][N], QString name1); /// Считывание из файла
void OutputAnswer(double x[N][N], double temp2[N][N], double y[N], int index, QString name2);/// Вывод в фаил

#endif // WID_H
