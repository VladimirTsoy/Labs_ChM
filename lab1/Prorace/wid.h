#ifndef WID_H
#define WID_H
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "stdlib.h"
#include "math.h"

using namespace std;

#define N 4
 void read_of_file(double a[N],double b[N],double c[N],double f[N], char* _namefile); /// Считывание из файла
 void printarr(double x[N]); /// Вывод на консоль
 void Prorace(double *a,double *b,double *c,double *f, double *x); /// Метод прогонки
 void Nullmas(double a[N],double b[N],double c[N],double f[N]); /// Обнуление массивов
 void out_ansver(double x[N], char *out_ans); /// Вывод результата в фаил
 int diagPrevalence(double a[N],double b[N],double c[N]); /// Проверка на диагональное преобладание
#endif // WID_H
