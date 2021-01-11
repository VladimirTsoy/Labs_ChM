#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    double x[N][N], y[N], q[N][N], temp[N][N], temp2[N][N], re[N], im[N];
    int index; // Счётчик итераций
    double accuracy = 0.0001; // Заданная точность вычислений
    QString name1 = "input3.txt", name2 = "output.txt"; // Файлы считывания и записи информации
    IdentityMas(q);

    InputMas(x, name1); // Считывание из файла
    double xn[N][N], qn[N][N], ren[N], imn[N];
        index = 0;
        do //QR-разложение
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
        while(!CriterionTermination(x, re, im, ren, imn, accuracy)); // Проверка выполнения условия окончания
        Eigenvalues(x, y); // Выделение собственных значений из матрицы

        Proverka2(q);

        OutputAnswer(x, q, y, re, im, index, name2); // Вывод в фаил

    return a.exec();
}
