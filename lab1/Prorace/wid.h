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
 void read_of_file(double a[N],double b[N],double c[N],double f[N], char* _namefile); /// ���������� �� �����
 void printarr(double x[N]); /// ����� �� �������
 void Prorace(double *a,double *b,double *c,double *f, double *x); /// ����� ��������
 void Nullmas(double a[N],double b[N],double c[N],double f[N]); /// ��������� ��������
 void out_ansver(double x[N], char *out_ans); /// ����� ���������� � ����
 int diagPrevalence(double a[N],double b[N],double c[N]); /// �������� �� ������������ ������������
#endif // WID_H
