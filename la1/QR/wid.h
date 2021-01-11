#ifndef WID_H
#define WID_H

#include <QFile>
#include <QVector>
#include <QObject>
#include <qmath.h>
#include <QDebug>
#include <QtDebug>
#include <iostream>
#include <QByteArray>
#include <stdio.h>
#include <cmath>
#include <fstream>

#define pi 3.14159265358979323846264338327950288419716939937510
#define minimum 0.000000000000001
#define N 3 //����������� �������� �������

using namespace std;

void Test(double _mas[N][N]);/// ����� �� ������� ����������� �������
void Test(double _mas[N]);/// ����� �� ������� ����������� �������
void SwapRows(double _mas[N][N], int _i, int _j);/// ������ ������� ������ � ��������� �������
void SwapRows(double _mas[N], int _i, int _j);/// ������ ������� �������� � ���������� �������
void Assignment(double _mas[N][N], double _mas2[N][N]);/// ������������ ������������� ��������� ��������
void Assignment(double _mas[N], double _mas2[N]);/// ������������ ������������� ���������� ��������
void Transp(double _mas[N][N]);/// ���������������� ������
void NullMas(double _mas[N][N]);/// ��������� ���������� �������
void NullMas(double _mas[N]);/// ��������� ����������� �������
void IdentityMas(double _mas[N][N]);/// �������� ��������� �������
void MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N]);/// ������������ ������
void MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N]);/// ������������ ������� �� ������ �������
void MaxElement(double _mas[N][N], int &_i, int &_j);/// ����� ������������� ��������
void ChangeH(double _mas[N], double _mas2[N][N]); /// �������� ������� H
bool CriterionTermination(double _mas[N][N], double _re[N], double _im[N], double _ren[N], double _imn[N], double accuracy);/// �������� �������������� ��������� �������� ��������
int Symmetry(double _mas[N][N]); /// �������� �� �������������� �������� �������
void Eigenvalues(double _mas[N][N], double _mas2[N]); /// ��������� ����������� �������� �� �������
void Proverka(double _x[N][N],double _q[N][N], double temp[N][N], double temp2[N][N]); /// �������� �� ������������ QR-���������� � �� ��������������� ������� Q
void Proverka2(double _mas[N][N]); /// �������� �� ��������������� ����������� ��������
void QR(double _x[N][N], double _q[N][N]);/// QR - ����������
double Sign(double _a); /// ����������� ����� �����
double NormVector(double _mas[N][N], int _j); /// ���������� �������
double MultiVector1(double _mas[N]); /// ������������ ������������������� ������ �� �� ��������
void MultiVector2(double _mas[N], double _mas2[N][N]); /// ������������ ��������� ������� �� �����������������
double Discriminant(double _mas[N][N], int _i); /// ���������� ������������
void Complex(double _x[N][N], double _re[N], double _im[N]); /// ���������� ����������� ����������� ��������
void InputMas(double x[N][N], QString name1); /// ���������� �� �����
void OutputAnswer(double x[N][N], double q[N][N], double y[N], double re[N], double im[N], int index, QString name2); /// ����� � ����

#endif // WID_H
