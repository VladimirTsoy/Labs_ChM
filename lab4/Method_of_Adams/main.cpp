#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication abc(argc, argv);

    float y0 = 1.0;// Краевое условие
    float z0 = 2.0;// Краевое условие
    float a = 0.0; // Левый конец отрезка
    float b = 1.0; // Правый конец отрезка
    float h = (float)0.1;// Величина шага
    float size;// Количество интервалов,разбиения отрезка
    QString name2 = "output.txt";// Имя файла для вывода результата

    ofstream out;
    out.open(QFile::encodeName(name2).data());// Открытие файла на запись

    QVector <float> xk, yk1, yk2, zk, delta_yk, delta_zk, k1, k2, k3, k4, l1, l2, l3, l4;
    size = abs((a-b)/h);
    xk.push_back(a);
    yk1.push_back(y0);
    zk.push_back(z0);
    for(int i=1; i<4; i++)
    {
        // Вычисление методом Адамса
        xk.push_back(xk[i-1] + h);
        k1.push_back(h*Fy(zk[i-1]));
        l1.push_back(h*Fz(xk[i-1], yk1[i-1]));
        k2.push_back(h*Fy(zk[i-1] + 0.5*l1[i-1]));
        l2.push_back(h*Fz(xk[i-1] + 0.5*h, yk1[i-1] + 0.5*k1[i-1]));
        k3.push_back(h*Fy(zk[i-1] + 0.5*l2[i-1]));
        l3.push_back(h*Fz(xk[i-1] + 0.5*h, yk1[i-1] + 0.5*k2[i-1]));
        k4.push_back(h*Fy(zk[i-1] + l3[i-1]));
        l4.push_back(h*Fz(xk[i-1] + h, yk1[i-1] + k3[i-1]));
        delta_yk.push_back((k1[i-1] + 2*k2[i-1] + 2*k3[i-1] + k4[i-1])/6);
        yk1.push_back(yk1[i-1] + delta_yk[i-1]);
        delta_zk.push_back((l1[i-1] + 2*l2[i-1] + 2*l3[i-1] + l4[i-1])/6);
        zk.push_back(zk[i-1] + delta_zk[i-1]);
    }
    for(int i=4; i<size+1; i++)
    {
        xk.push_back(xk[i-1] + h);
        yk1.push_back(yk1[i-1] + h*(55*Fy(zk[i-1]) - 59*Fy(zk[i-2]) + 37*Fy(zk[i-3]) - 9*Fy(zk[i-4]))/24);
        zk.push_back(zk[i-1] + h*(55*Fz(xk[i-1], yk1[i-1]) - 59*Fz(xk[i-2], yk1[i-2]) + 37*Fz(xk[i-3], yk1[i-3]) - 9*Fz(xk[i-4], yk1[i-4]))/24);
    }

    out << "\tThe method of Adams (step = " << h << ")\n";
    out << "k" << "\t\t" << "xk" << "\t\t" << "yk1" << "\t\t" << "zk" << "\t\t" << "Fy(x[k], y[k], z[k])" << "\t\t" << "Fz(x[k], y[k], z[k])" << "\t\t" << "y_true" << "\t\t" << "epsilon" << "\n";
    for(int i=0; i<size+1; i++)
            out << i << "\t\t" << xk[i] << "\t\t" << yk1[i] << "\t\t" << zk[i] << "\t\t" << Fy(zk[i]) << "\t\t" << Fz(xk[i], yk1[i]) << "\t\t" << Ftrue(xk[i]) << "\t\t" << abs(Ftrue(xk[i]) - yk1[i]) << "\n";// Вывод в файл посчитанных значений
    xk.clear();
    zk.clear();
    delta_yk.clear();
    delta_zk.clear();
    k1.clear();
    k2.clear();
    k3.clear();
    k4.clear();
    l1.clear();
    l2.clear();
    l3.clear();
    l4.clear();
    xk.push_back(a);
    yk2.push_back(y0);
    zk.push_back(z0);
    for(int i=1; i<4; i++)
    {
        // Вычисление Методом Адамса с другим шагом
        xk.push_back(xk[i-1] + 0.5*h);
        k1.push_back(0.5*h*Fy(zk[i-1]));
        l1.push_back(0.5*h*Fz(xk[i-1], yk2[i-1]));
        k2.push_back(0.5*h*Fy(zk[i-1] + 0.5*l1[i-1]));
        l2.push_back(0.5*h*Fz(xk[i-1] + 0.5*0.5*h, yk2[i-1] + 0.5*k1[i-1]));
        k3.push_back(0.5*h*Fy(zk[i-1] + 0.5*l2[i-1]));
        l3.push_back(0.5*h*Fz(xk[i-1] + 0.5*0.5*h, yk2[i-1] + 0.5*k2[i-1]));
        k4.push_back(0.5*h*Fy(zk[i-1] + l3[i-1]));
        l4.push_back(0.5*h*Fz(xk[i-1] + 0.5*h, yk2[i-1] + k3[i-1]));
        delta_yk.push_back((k1[i-1] + 2*k2[i-1] + 2*k3[i-1] + k4[i-1])/6);
        yk2.push_back(yk2[i-1] + delta_yk[i-1]);
        delta_zk.push_back((l1[i-1] + 2*l2[i-1] + 2*l3[i-1] + l4[i-1])/6);
        zk.push_back(zk[i-1] + delta_zk[i-1]);
    }
    for(int i=4; i<2*size+1; i++)
    {
        xk.push_back(xk[i-1] + 0.5*h);
        yk2.push_back(yk2[i-1] + 0.5*h*(55*Fy(zk[i-1]) - 59*Fy(zk[i-2]) + 37*Fy(zk[i-3]) - 9*Fy(zk[i-4]))/24);
        zk.push_back(zk[i-1] + 0.5*h*(55*Fz(xk[i-1], yk2[i-1]) - 59*Fz(xk[i-2], yk2[i-2]) + 37*Fz(xk[i-3], yk2[i-3]) - 9*Fz(xk[i-4], yk2[i-4]))/24);
    }
    // Вывод значений с другим шагом
    out << "\n\tThe method of Adams (step = " << 0.5*h << ")\n";
    out << "k" << "\t\t" << "xk" << "\t\t" << "yk2" << "\t\t" << "zk" << "\t\t" << "Fy(x[k], y[k], z[k])" << "\t\t" << "Fz(x[k], y[k], z[k])" << "\t\t" << "y_true" << "\t\t" << "epsilon" << "\n";
    for(int i=0; i<2*size+1; i++)
            out << i << "\t\t" << xk[i] << "\t\t" << yk2[i] << "\t\t" << zk[i] << "\t\t" << Fy(zk[i]) << "\t\t" << Fz(xk[i], yk2[i]) << "\t\t" << Ftrue(xk[i]) << "\t\t" << abs(Ftrue(xk[i]) - yk2[i]) << "\n";
    // Запись ответов в файл:
    out << "\n\tAnswer\n";
    out << "k";
    for(int i=0; i<size+1; i++)
        out << "\t\t" << i;
    out << "\nxk";
    for(int i=0; i<size+1; i++)
        out << "\t\t" << xk[i];
    out << "\nyk1";
    for(int i=0; i<size+1; i++)
        out << "\t\t" << yk1[i];
    out << "\nAccuracy";
    for(int i=0; i<size+1; i++)
        out << "\t" << Accuracy(yk1[i], yk2[2*i]);
    out << "\n";
    out.close();

    cout << "OK";

    return abc.exec();
}
