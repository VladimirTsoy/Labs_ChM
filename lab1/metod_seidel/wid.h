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

void Test(double _mas[N]);/// ����� �� ������� ����������� �������
void Test(double _mas[N][N], double y[N]);/// ����� �� ������� ������� �� ������� ������ ����� �������
bool Converge(double _a[N], double _b[N], double accuracy);/// �������� ���������� �������� ��������
void SwapRows(double _mas[N][N], int _i, int _j);/// ������ ������� ������ � ��������� �������
void Assignment(double _mas[N][N], double _mas2[N][N]);/// ������������ ��������� ��������� ��������
void Assignment(double _mas[N], double _mas2[N]);/// ������������ ������������� ���������� ��������
void NullMas(double _mas[N][N]);/// ��������� ���������� �������
void NullMas(double _mas[N]);/// ��������� ����������� �������
void IdentityMas(double _mas[N][N]);/// �������� ��������� �������
void MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N]);/// ������������ ������
void MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N]);/// ������������ ������� �� ������ �������
double NormC_of_the_matrix(double _mas[N][N]);/// ���������� ������� ����� �������
double NormC_of_the_matrix(double _mas[N]);/// ���������� ������� ����� �������
int Diagonal_dominance(double _mas[N][N]);/// �������� �� ������������ ������������
 void InputMas(double x[N][N], double y[N], QString name1);/// ���������� ������ �� �����
 void OutputAnswer(double a[N], int index, QString name2);/// ����� ������(�������) � ����

#endif // WID_H
