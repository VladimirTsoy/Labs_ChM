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
void Test2(double _mas[N][N]);/// ����� �� ������� ���������� �������
void Test1(double _mas[N]);/// ����� �� ������� ����������� �������
void PLU(double _x[N][N], double _l[N][N], double _u[N][N], double _p[N][N], double _y[N], int index);/// LU ���������� � �������� ������������ P
void PLUinverse(double _u[N][N], double _y[N]);/// �������� ����� ����� LU ����������
void SwapRows(double _mas[N][N], int _i, int _j);/// ������ ������� ������ � ��������� �������
void SwapRows(double _mas[N], int _i, int _j);/// ������ ������� �������� � ���������� �������
void Assignment(double _mas[N][N], double _mas2[N][N]); /// ������������ ��������� ��������� ��������
void Assignment(double _mas[N], double _mas2[N]);/// ������������ ������������� ���������� ��������
void Determinant(double _mas[N][N], int index);/// ������� ������������ ������� ����� LU ����������
void NullMas(double _mas[N][N]);/// ��������� ���������� �������
void NullMas(double _mas[N]);/// ��������� ����������� �������
void IdentityMas(double _mas[N][N]);/// �������� ��������� �������
void MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N]);/// ������������ ������
void MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N]);/// ������������ ������� �� ������ �������
void InputMas(double x[N][N], double y[N], char *name1);/// ���������� ������ �� �����
void OutputAnswer(double l[N][N], double u[N][N], double p[N][N], double inv[N][N], double y[N], char *name2);/// ����� ������(�������) � ����
#endif // WID_H
