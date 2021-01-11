#ifndef WID_H
#define WID_H
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <QFile>
#include <QString>

#define N 4
#define minimum 0.00000001
using namespace std;

void Test(double _mas[N][N], double y[N]); /// Вывод матрицы и вектора правой части в консоль
void SwapRows(double _mas[N][N], int _i, int _j); /// Поменять строки в данной матрице местами
void Assignment(double _mas[N][N], double _mas2[N][N]); /// Функция присваивания одного двухмнерного массива другому
void Assignment(double _mas[N], double _mas2[N]); /// Функция присваивания одного одномерного массива другому
void Transp(double _mas[N][N]); /// Транспонирование матрицы
void Determinant(double _mas[N][N]); /// Вычисление определителя
void IdentityMas(double _mas[N][N]); /// Создание единичной матрицы
void MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N]); /// Произведение двухмерных массивов
void MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N]); /// Произведение одномерных массивов
void Jacobi_method(double _x[N][N], double _y[N]); /// Метод Якоби
double NormC_of_the_matrix(double _mas[N][N]); /// Вычисление сильной нормы матрицы
double NormC_of_the_matrix(double _mas[N]); /// Вычисление сильной нормы вектора
int Diagonal_dominance(double _mas[N][N]); /// Проверка на диагональное преобладание матрицы
bool Change_accuracy(double _x[N][N], double _y1[N], double _y2[N], double accuracy); /// Проверка удовлетворения заданной точности
 void InputMas(double x[N][N], double y[N], QString name1); /// Считывание входных данных из указанного файла
 void OutputAnswer(double a[N], QString name2, int index); /// Вывод результата в указанный файл
 void NullMas(double _mas[N][N]); /// Обнуление двухмерного массива
 void NullMas(double _mas[N]); /// Обнуление одномерного массива

#endif // WID_H
