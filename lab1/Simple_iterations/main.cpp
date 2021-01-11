#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication asd(argc, argv);
    double y[N], a[N], b[N], temp1[N], x[N][N], x1[N][N];
    int index; // Счётчик числа итераций
    double accuracy = 0.001; // Заданная точность вычислений
    QString name1 = "input3.txt", name2 = "output.txt"; // Файла ввода/вывода информации
    index = 0.0;
    InputMas(x, y, name1); // Считывание входных данных из заданного файла
    if(Diagonal_dominance(x) == 0) // Проверка на диагональное преобладание
    {
        Assignment(x1, x);
        Test(x1, y);
        Jacobi_method(x, y);
        if ((NormC_of_the_matrix(x) < 1.0)) // Проверка матрицы на сильную норму
        {
            Assignment(a, y);
            double temp[N];
            do // Вычисление методом простых итераций
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
            while (!Change_accuracy(x, a, b, accuracy)); // Проверка выполнения условия окончания
            Test(x, y);
            MultiMas(x1, a, temp1); // Проверка правильности найденного решения
            OutputAnswer(a, name2, index); // Вывод результата в файл
        }
        else
            qDebug("Error: Norm of the matrix !");
    }
    else
        qDebug("Error: Diagonal dominance !");

    return asd.exec();
}
