#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication asd(argc, argv);

    double y[N], a[N], b[N], temp1[N], x[N][N], x1[N][N];
    int index; // Колличество итераций
    double accuracy = 0.01; // Заданная точность вычислений
    QString name1 = "input3.txt", name2 = "output.txt";
    InputMas(x, y, name1);

    index = 0.0;
    NullMas(a);
    if(Diagonal_dominance(x) == 0)// Проверка на диагональное преобладание исходной матрицы
    {
        Assignment(x1, x);
        //Test(x1, y);
                do
                {
                    for (int i = 0; i < N; i++)
                    {
                        if ( (x[i][i] == 0.0)&&(i!=N-1))
                            SwapRows(x, i, i+1);
                        double var = 0;
                        for (int j = 0; j < N; j++)
                            if (j != i) var += (x[i][j] * a[j]);
                        b[i] = a[i];
                        a[i] = (y[i] - var) / x[i][i];

                    }
                    index++;
                }
                while (!Converge(a, b, accuracy)); // Проверка удовлетворения заданной точности
            cout << "\tMatrix:\n";
            Test(x, y);
            index--;
            OutputAnswer(a, index, name2); // Вывод результатов в фаил
            MultiMas(x1, a, temp1);//Проверяем,что произведение исходной
            //матрицы на вектор корней равен правой части
            cout << "\tAnswer:\n";
            Test(a);// Вывод результата на консоль
    }
    else
        qDebug("Error : Diagonal dominance !");
    return asd.exec();
}
