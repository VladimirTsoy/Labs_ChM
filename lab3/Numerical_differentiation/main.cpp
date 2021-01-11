#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    int index;
    float x[N], y[N], xk, yk;
    QString name1 = "input3.txt", name2 = "output.txt"; // ����� �����/������

    xk = InputMas(name1, x, y); // ���������� �� �����

    ofstream out;
    out.open(QFile::encodeName(name2).data()); // �������� ����� �� ������
    for(int i=0;i<N;i++) // ���������� �����������
    {
        if(xk == x[i])
            index = i;
    }
    yk = (y[index] - y[index-1])/(x[index] - x[index-1]);
    out << "Left-sided derivative: y'(x) = " << yk << "\n";
    yk = (y[index+1] - y[index])/(x[index+1] - x[index]);
    out << "Right-sided derivative: y'(x) = " << yk << "\n";
    yk = (y[index] - y[index-1])/(x[index] - x[index-1]) + ((((y[index+1]-y[index])/(x[index+1]-x[index]))-((y[index]-y[index-1])/(x[index]-x[index-1])))/(x[index+1]-x[index-1]))*(2*xk-x[index-1]-x[index]);
    out << "The derivative of the second order of accuracy: y'(x) = " << yk << "\n";
    yk = 2*((((y[index+1]-y[index])/(x[index+1]-x[index]))-((y[index]-y[index-1])/(x[index]-x[index-1])))/(x[index+1]-x[index-1]));
    out << "The second derivative: y\"(x) = " << yk << "\n";
    out.close(); // �������� �����

    cout << "OK";

    return a.exec();
}
