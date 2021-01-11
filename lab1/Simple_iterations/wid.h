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

void Test(double _mas[N][N], double y[N]); /// ����� ������� � ������� ������ ����� � �������
void SwapRows(double _mas[N][N], int _i, int _j); /// �������� ������ � ������ ������� �������
void Assignment(double _mas[N][N], double _mas2[N][N]); /// ������� ������������ ������ ������������ ������� �������
void Assignment(double _mas[N], double _mas2[N]); /// ������� ������������ ������ ����������� ������� �������
void Transp(double _mas[N][N]); /// ���������������� �������
void Determinant(double _mas[N][N]); /// ���������� ������������
void IdentityMas(double _mas[N][N]); /// �������� ��������� �������
void MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N]); /// ������������ ���������� ��������
void MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N]); /// ������������ ���������� ��������
void Jacobi_method(double _x[N][N], double _y[N]); /// ����� �����
double NormC_of_the_matrix(double _mas[N][N]); /// ���������� ������� ����� �������
double NormC_of_the_matrix(double _mas[N]); /// ���������� ������� ����� �������
int Diagonal_dominance(double _mas[N][N]); /// �������� �� ������������ ������������ �������
bool Change_accuracy(double _x[N][N], double _y1[N], double _y2[N], double accuracy); /// �������� �������������� �������� ��������
 void InputMas(double x[N][N], double y[N], QString name1); /// ���������� ������� ������ �� ���������� �����
 void OutputAnswer(double a[N], QString name2, int index); /// ����� ���������� � ��������� ����
 void NullMas(double _mas[N][N]); /// ��������� ����������� �������
 void NullMas(double _mas[N]); /// ��������� ����������� �������

#endif // WID_H
