#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication asd(argc, argv);
    double y[N], a[N], b[N], temp1[N], x[N][N], x1[N][N];
    int index; // ������� ����� ��������
    double accuracy = 0.001; // �������� �������� ����������
    QString name1 = "input3.txt", name2 = "output.txt"; // ����� �����/������ ����������
    index = 0.0;
    InputMas(x, y, name1); // ���������� ������� ������ �� ��������� �����
    if(Diagonal_dominance(x) == 0) // �������� �� ������������ ������������
    {
        Assignment(x1, x);
        Test(x1, y);
        Jacobi_method(x, y);
        if ((NormC_of_the_matrix(x) < 1.0)) // �������� ������� �� ������� �����
        {
            Assignment(a, y);
            double temp[N];
            do // ���������� ������� ������� ��������
            {
                MultiMas(x, a, temp);
                for (int j=0;j<N;j++)
                {
                    b[j] = a[j];
                    a[j] = y[j] + temp[j];
                }
                NullMas(temp);
                index++;
            }
            while (!Change_accuracy(x, a, b, accuracy)); // �������� ���������� ������� ���������
            Test(x, y);
            MultiMas(x1, a, temp1); // �������� ������������ ���������� �������
            OutputAnswer(a, name2, index); // ����� ���������� � ����
        }
        else
            qDebug("Error: Norm of the matrix !");
    }
    else
        qDebug("Error: Diagonal dominance !");

    return asd.exec();
}
