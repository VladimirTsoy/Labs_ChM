#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication abc(argc, argv);
    
    float x0 = (float)pi/4, x1 = (float)pi/3, h, size;
    QString name2 = "output.txt"; // Имя файла на вывод информации

    ofstream out;
    out.open(QFile::encodeName(name2).data()); // Открытие файла на запись

    h = (float)pi/60; // Определение шага
    QVector<float> xk, a, b, c, f, yk1, yk2;
    size = abs((x1-x0)/h);
    f.push_back((3+(pi/2))*h);
    yk1.push_back(0.0);
    xk.push_back(x0);
    c.push_back(1.0);
    b.push_back(-1.0);
    a.push_back(0.0);
    for(int i=1; i<size; i++) // Вычисления
    {
        f.push_back(0.0);
        yk1.push_back(0.0);
        xk.push_back(xk.last() + h);
        c.push_back(-2.0 + (h*h*(-2.0)*(1.0+(qTan(xk.last()))*(qTan(xk.last())))));
        b.push_back(1.0);
        a.push_back(1.0);
    }
    f.push_back(-3*pi*pi - (pi*pi*(4-qSqrt(3)))/3);
    yk1.push_back(0.0);
    xk.push_back(xk.last() + h);
    c.push_back((float)(-120+pi));
    b.push_back(0.0);
    a.push_back(120.0);
    if(!Diagonal_dominance(a, c, b)) // Проверка диагонального преобладания
        SolveMatrix(a, c, b, f, yk1);
    else
        qFatal("ERROR: Matrix is not Diagonal dominance !");
    out << "\tThe finite-difference method (step = " << h << ")\n";
    out << "k" << "\t\t" << "xk" << "\t\t" << "yk1" << "\t\t" << "y_true" << "\t\t" << "epsilon" << "\n";
    for(int i=0; i<size+1; i++)
    {
        out << i << "\t" << xk[i] << "\t" << yk1[i] << "\t" << Ftrue(xk[i]) << "\t" << abs(Ftrue(xk[i]) - yk1[i]) << "\n";
    }

    h *= 0.5;
    a.clear();
    b.clear();
    c.clear();
    f.clear();
    xk.clear();
    f.push_back((3+(pi/2))*h);
    yk2.push_back(0.0);
    xk.push_back(x0);
    c.push_back(1.0);
    b.push_back(-1.0);
    a.push_back(0.0);
    for(int i=1; i<2*size; i++)
    {
        f.push_back(0.0);
        yk2.push_back(0.0);
        xk.push_back(xk.last() + h);
        c.push_back(-2.0 + (h*h*(-2.0)*(1.0+(qTan(xk.last()))*(qTan(xk.last())))));
        b.push_back(1.0);
        a.push_back(1.0);
    }
    f.push_back(-3*pi*pi - (pi*pi*(4-qSqrt(3)))/3);
    yk2.push_back(0.0);
    xk.push_back(xk.last() + h);
    c.push_back((float)(-120+pi));
    b.push_back(0.0);
    a.push_back(120.0);
    if(!Diagonal_dominance(a, c, b)) // Проверка диагонального преобладания
        SolveMatrix(a, c, b, f, yk2);
    else
        qFatal("ERROR: Matrix is not Diagonal dominance !");
    out << "\n\tThe finite-difference method (step = " << h << ")\n";
    out << "k" << "\t\t" << "xk" << "\t\t" << "yk1" << "\t\t" << "y_true" << "\t\t" << "epsilon" << "\n";
    for(int i=0; i<2*size+1; i++)
    {
        out << i << "\t" << xk[i] << "\t" << yk2[i] << "\t" << Ftrue(xk[i]) << "\t" << abs(Ftrue(xk[i]) - yk2[i]) << "\n";
    }
    out << "\n\tAnswer\n"; // Вывод ответа
    out << "k";
    for(int i=0; i<size+1; i++)
        out << "\t\t\t" << i;
    out << "\nxk";
    for(int i=0; i<size+1; i++)
        out << "\t\t" << xk[2*i];
    out << "\nyk1\t";
    for(int i=0; i<size+1; i++)
        out << "\t" << yk1[i];
    out << "\nAccuracy";
    for(int i=0; i<size+1; i++)
        out << "\t" << Accuracy(yk1[i], yk2[2*i]); // Вывод погрешности
    out << "\n";
    out.close(); // Закрытие файла

    cout << "OK";

    return abc.exec();
}
