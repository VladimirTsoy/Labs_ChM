#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    double x[N][N], y[N], q[N][N], temp[N][N], temp2[N][N], re[N], im[N];
    int index; // ������� ��������
    double accuracy = 0.0001; // �������� �������� ����������
    QString name1 = "input3.txt", name2 = "output.txt"; // ����� ���������� � ������ ����������
    IdentityMas(q);

    InputMas(x, name1); // ���������� �� �����
    double xn[N][N], qn[N][N], ren[N], imn[N];
        index = 0;
        do //QR-����������
        {
            Assignment(ren, re);
            Assignment(imn, im);
            Assignment(xn, x);
            QR(xn, qn);
            Proverka(xn, qn, temp, temp2);
            MultiMas(xn, qn, x);
            Assignment(temp, q);
            MultiMas(temp, qn, q);
            Complex(x, re, im);
            Test(re);
            Test(im);
            index++;
        }
        while(!CriterionTermination(x, re, im, ren, imn, accuracy)); // �������� ���������� ������� ���������
        Eigenvalues(x, y); // ��������� ����������� �������� �� �������

        Proverka2(q);

        OutputAnswer(x, q, y, re, im, index, name2); // ����� � ����

    return a.exec();
}
