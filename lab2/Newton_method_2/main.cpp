#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication asd(argc, argv);
    
    int iter; // Счётчик числа итераций
    float accuracy = 0.01, left1 = 0.25, right1 = 0.75, left2 = 2.0, right2 = 2.5, x[N], xk[N], a[N][N], detA1, detA2, detJ;
    QString name = "output.txt"; // Имя файла на вывод информации

    ofstream out;
    out.open(QFile::encodeName(name).data()); // Открытие файла на запись
    out << "k" << "\t" << "x1" << "\t" << "f1(x1,x2)" << "\t" << "df1(x1,x2)/dx1" << "\t" << "df1(x1,x2)/dx2" << "\t" << "det A1" << "\t" << "det A2" << "\t" << "det J" << "\n";
    out << "\t" << "x2" << "\t" << "f2(x1,x2)" << "\t" << "df2(x1,x2)/dx1" << "\t" << "df2(x1,x2)/dx2" << "\n";
    out << "----------------------------------------------------------------------------------------------------" << "\n";
    xk[0] = (left1 + right1)/2; // Начальное приближение по х1
    xk[1] = (left2 + right2)/2; // Начальное приближение по х2
    iter = 0;
    do
    {
        x[0] = xk[0];
        x[1] = xk[1];
        a[0][0] = F1_der_x1(x[0], x[1]);
        a[0][1] = F1_der_x2(x[0], x[1]);
        a[1][0] = F2_der_x1(x[0], x[1]);
        a[1][1] = F2_der_x2(x[0], x[1]);
        detJ = Determinant(a);
        a[0][0] = Function1(x[0], x[1]);
        a[0][1] = F1_der_x2(x[0], x[1]);
        a[1][0] = Function2(x[0], x[1]);
        a[1][1] = F2_der_x2(x[0], x[1]);
        detA1 = Determinant(a);
        a[0][0] = F1_der_x1(x[0], x[1]);
        a[0][1] = Function1(x[0], x[1]);
        a[1][0] = F2_der_x1(x[0], x[1]);
        a[1][1] = Function2(x[0], x[1]);
        detA2 = Determinant(a);
        out << iter << "\t" << x[0] << "\t" << Function1(x[0], x[1]) << "\t" << F1_der_x1(x[0], x[1]) << "\t" << F1_der_x2(x[0], x[1]) << "\t";
        out << detA1 << "\t" << detA2 << "\t" << detJ << "\n";
        out << "\t" << x[1] << "\t" << Function2(x[0], x[1]) << "\t" << F2_der_x1(x[0], x[1]) << "\t" << F2_der_x2(x[0], x[1]) << "\n";

        xk[0] = x[0] - detA1/detJ;
        xk[1] = x[1] - detA2/detJ;
        out << "----------------------------------------------------------------------------------------------------" << "\n";
        iter++;
    }
    while(!CriterionTermination(xk, x, accuracy)); // Проверка выполнения критерия окончания
    out << iter << "\t" << xk[0] << "\n" << "\t" << xk[1] << "\n\nAnswer: \tx1 = " << xk[0] << "\n\t\tx2 = " << xk[1] << "\n"; // Вывод ответа
    out.close(); // Закрытие файла
    cout << "OK";

    return asd.exec();
}
