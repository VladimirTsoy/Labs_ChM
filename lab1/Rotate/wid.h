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
#define N 3 //����������� �������� �������

void Test(double _mas[N][N]);/// ����� �� ������� ���������� �������
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
void ChangeU(double _mas[N][N], int _i, int _j, double _fi); /// �������� ������� ��������
bool CriterionTermination(double _mas[N][N], double accuracy);/// �������� �������������� ��������� �������� ��������
int Symmetry(double _mas[N][N]);/// �������� �� �������������� �������� �������
void Eigenvalues(double _mas[N][N], double _mas2[N]);/// ��������� ����������� �������� �� �������
void Proverka(double _mas[N][N]);/// �������� �� ��������������� ����������� ��������
void InputMas(double x[N][N], QString name1); /// ���������� �� �����
void OutputAnswer(double x[N][N], double temp2[N][N], double y[N], int index, QString name2);/// ����� � ����

#endif // WID_H
