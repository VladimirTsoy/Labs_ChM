#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication abc(argc, argv);

    float y0 = 1.0, z0 = 2.0, a = 0.0, b = 1.0, h = (float)0.1;
    float size;
    QString name2 = "output.txt"; // Имя файла на вывод результата

    ofstream out;
    out.open(QFile::encodeName(name2).data()); // Открытие файла на запись

    QVector <float> xk, yk1, yk2, zk, delta_yk, delta_zk;
    size = abs((a-b)/h);
    xk.push_back(a);
    yk1.push_back(y0);
    zk.push_back(z0);
    for(int i=1; i<size+1; i++) // Вычисление методом Эйлера
    {
        xk.push_back(xk[i-1] + h);
        delta_yk.push_back(h*Fy(zk[i-1]));
        yk1.push_back(yk1[i-1] + delta_yk[i-1]);
        delta_zk.push_back(h*Fz(xk[i-1], yk1[i-1]));
        zk.push_back(zk[i-1] + delta_zk[i-1]);
    }

    out << "\tEuler's method (step = " << h << ")\n";
    out << "k" << "\t\t" << "xk" << "\t\t" << "yk1" << "\t\t" << "zk" << "\t\t" << "delta_yk" << "\t\t" << "delta_zk" << "\t\t" << "y_true" << "\t\t" << "epsilon" << "\n";
    for(int i=0; i<size+1; i++)
    {
        if(i!=size)
            out << i << "\t\t" << xk[i] << "\t\t" << yk1[i] << "\t\t" << zk[i] << "\t\t" << delta_yk[i] << "\t\t" << delta_zk[i] << "\t\t" << Ftrue(xk[i]) << "\t\t" << abs(Ftrue(xk[i]) - yk1[i]) << "\n";
        else
            out << i << "\t\t" << xk[i] << "\t\t" << yk1[i] << "\t\t" << zk[i] << "\t\t" << "\t\t" << "\t\t" << Ftrue(xk[i]) << "\t\t" << abs(Ftrue(xk[i]) - yk1[i]) << "\n";
    }
    xk.clear();
    zk.clear();
    delta_yk.clear();
    delta_zk.clear();
    xk.push_back(a);
    yk2.push_back(y0);
    zk.push_back(z0);
    for(int i=1; i<2*size+1; i++) // Вычисление методом Эйлера с другим шагом
    {
        xk.push_back(xk[i-1] + 0.5*h);
        delta_yk.push_back(0.5*h*Fy(zk[i-1]));
        yk2.push_back(yk2[i-1] + delta_yk[i-1]);
        delta_zk.push_back(0.5*h*Fz(xk[i-1], yk2[i-1]));
        zk.push_back(zk[i-1] + delta_zk[i-1]);
    }
    out << "\n\tEuler's method (step = " << 0.5*h << ")\n";
    out << "k" << "\t\t" << "xk" << "\t\t" << "yk2" << "\t\t" << "zk" << "\t\t" << "delta_yk" << "\t\t" << "delta_zk" << "\t\t" << "y_true" << "\t\t" << "epsilon" << "\n";
    for(int i=0; i<2*size+1; i++)
    {
        if(i!=2*size)
            out << i << "\t\t" << xk[i] << "\t\t" << yk2[i] << "\t\t" << zk[i] << "\t\t" << delta_yk[i] << "\t\t" << delta_zk[i] << "\t\t" << Ftrue(xk[i]) << "\t\t" << abs(Ftrue(xk[i]) - yk2[i]) << "\n";
        else
            out << i << "\t\t" << xk[i] << "\t\t" << yk2[i] << "\t\t" << zk[i] << "\t\t" << "\t\t" << "\t\t" << Ftrue(xk[i]) << "\t\t" << abs(Ftrue(xk[i]) - yk2[i]) << "\n";
    }
    out << "\n\tAnswer\n"; // Вывод ответа
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
        out << "\t" << Accuracy(yk1[i], yk2[2*i]); // Подсчёт погрешности вычислений
    out << "\n";
    out.close(); // Закрытие файла

    cout << "OK";

    return abc.exec();
}
