#ifndef WID_H
#define WID_H
#include <iostream>
#include <QByteArray>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include<QFile>
#define pi 3.14159265358979323846264338327950288419716939937510
#define minimum 0.0000000000000001
#define N 4

using namespace std;

void Test(double _mas[N]);/// Вывод на консоль одномерного массива
void Test(double _mas[N][N], double y[N]);/// Вывод на консоль матрицы со столбом правой части системы
bool Converge(double _a[N], double _b[N], double accuracy);/// Проверка выполнения заданной точности
void SwapRows(double _mas[N][N], int _i, int _j);/// Меняет местами строки в двумерном массиве
void Assignment(double _mas[N][N], double _mas2[N][N]);/// Поэлементное присвание двумерных массивов
void Assignment(double _mas[N], double _mas2[N]);/// Поэлементное присванивание одномерных массивов
void NullMas(double _mas[N][N]);/// Обнуление двумерного массива
void NullMas(double _mas[N]);/// Обнуление одномерного массива
void IdentityMas(double _mas[N][N]);/// Создание еденичной матрицы
void MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N]);/// Перемножение матриц
void MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N]);/// Перемножение матрицы на вектор столбец
double NormC_of_the_matrix(double _mas[N][N]);/// Нахождение сильной нормы матрицы
double NormC_of_the_matrix(double _mas[N]);/// Нахождение сильной нормы вектора
int Diagonal_dominance(double _mas[N][N]);/// Проверка на диагональное преобладание
 void InputMas(double x[N][N], double y[N], QString name1);/// Считывание данных из файла
 void OutputAnswer(double a[N], int index, QString name2);/// Вывод данных(ответов) в файл

#endif // WID_H
