#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    double x[N][N], y[N], u[N][N], temp[N][N], temp2[N][N], temp3[N][N];
    int index; // Счётчик колличества итераций
    double accuracy = 0.0001; // Заданная точность
    QString name1 = "input2.txt", name2 = "output.txt"; // Файлы считывания и записи информации

    InputMas(x, name1);// Считывание из файла
    IdentityMas(temp2);
    index = 0;
    if(Symmetry(x) == 0 ) // Проверка на симметричность исходной матрицы
    {
        do // Метод вращений
        {
            NullMas(temp);
            NullMas(u);
            IdentityMas(u);
            int index_i,index_j;
            double fi;
            MaxElement(x,index_i,index_j);
            qDebug("Max[%d][%d] = %.2f", index_i,index_j, x[index_i][index_j]);
            if(x[index_i][index_i]!=x[index_j][index_j])
                fi = 0.5 * qAtan((2 * x[index_i][index_j]) / (x[index_i][index_i] - x[index_j][index_j]));
            else
                fi = pi/4;
            qDebug("Fi = %f", fi);
            ChangeU(u, index_i, index_j, fi);
            Test(u);
            Transp(u);
            MultiMas(u, x, temp);
            Transp(u);
            MultiMas(temp, u, x);
            Test(x);
            MultiMas(temp2, u, temp3);
            Assignment(temp2, temp3);
            index++;
        }
        while(!CriterionTermination(x, accuracy));// Проверка выполнения условия окончания
        Eigenvalues(x, y);// Выделение собственных значений из матрицы
        index--;
        Proverka(temp2);
        OutputAnswer(x, temp2, y, index, name2);// Вывод в фаил
    }
    else
        qDebug("Matrix is not Symmetry !");

    return a.exec();
}
