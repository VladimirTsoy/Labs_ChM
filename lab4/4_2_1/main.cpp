#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication abc(argc, argv);
    
    int index;
    float x0 = 0, y0 = -18, x1 = 3, y1 = 0, h, size, eps;
    char* name2 = "output.txt";

    ofstream out;
    out.open(name2);

    vector <float> xk, yk1, yk2, zk, delta_yk, delta_zk, k1, k2, k3, k4, l1, l2, l3, l4, n, F, Y;
    eps = (float)0.00001;// Критерий остановки алгоритма(заданная точность)
    h = (float)0.3;
    n.push_back(1);// Значение тангенса угла стрельбы
    size = abs((x0-x1)/h);// Количество интервалов
    xk.push_back(x0);
    yk1.push_back(y0);
    zk.push_back(n[n.size()-1]);// Кладём последний элемент вектора  последний эл. в zk
    for(int i=1; i<size+1; i++)
    { // Вычисления методом Стрельбы с заданным n
        xk.push_back(xk[i-1] + h);
        k1.push_back(h*Fy(zk[i-1]));
        l1.push_back(h*Fz(xk[i-1], yk1[i-1], zk[i-1]));
        k2.push_back(h*Fy(zk[i-1] + 0.5*l1[i-1]));
        l2.push_back(h*Fz(xk[i-1] + 0.5*h, yk1[i-1] + 0.5*k1[i-1], zk[i-1] + 0.5*l1[i-1]));
        k3.push_back(h*Fy(zk[i-1] + 0.5*l2[i-1]));
        l3.push_back(h*Fz(xk[i-1] + 0.5*h, yk1[i-1] + 0.5*k2[i-1], zk[i-1] + 0.5*l2[i-1]));
        k4.push_back(h*Fy(zk[i-1] + l3[i-1]));
        l4.push_back(h*Fz(xk[i-1] + h, yk1[i-1] + k3[i-1], zk[i-1] + l3[i-1]));
        delta_yk.push_back((k1[i-1] + 2*k2[i-1] + 2*k3[i-1] + k4[i-1])/6);
        yk1.push_back(yk1[i-1] + delta_yk[i-1]);
        delta_zk.push_back((l1[i-1] + 2*l2[i-1] + 2*l3[i-1] + l4[i-1])/6);
        zk.push_back(zk[i-1] + delta_zk[i-1]);
    }

    F.push_back(yk1[yk1.size()-1] - y1);
    Y.push_back(yk1[yk1.size()-1]);
    xk.clear();
    yk1.clear();
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
    n.push_back((float)(0.8));
    xk.push_back(x0);
    yk1.push_back(y0);
    zk.push_back(n[n.size()-1]);
    for(int i=1; i<size+1; i++)
    {// Вычисления методом стрельбы с другим n
        xk.push_back(xk[i-1] + h);
        k1.push_back(h*Fy(zk[i-1]));
        l1.push_back(h*Fz(xk[i-1], yk1[i-1], zk[i-1]));
        k2.push_back(h*Fy(zk[i-1] + 0.5*l1[i-1]));
        l2.push_back(h*Fz(xk[i-1] + 0.5*h, yk1[i-1] + 0.5*k1[i-1], zk[i-1] + 0.5*l1[i-1]));
        k3.push_back(h*Fy(zk[i-1] + 0.5*l2[i-1]));
        l3.push_back(h*Fz(xk[i-1] + 0.5*h, yk1[i-1] + 0.5*k2[i-1], zk[i-1] + 0.5*l2[i-1]));
        k4.push_back(h*Fy(zk[i-1] + l3[i-1]));
        l4.push_back(h*Fz(xk[i-1] + h, yk1[i-1] + k3[i-1], zk[i-1] + l3[i-1]));
        delta_yk.push_back((k1[i-1] + 2*k2[i-1] + 2*k3[i-1] + k4[i-1])/6);
        yk1.push_back(yk1[i-1] + delta_yk[i-1]);
        delta_zk.push_back((l1[i-1] + 2*l2[i-1] + 2*l3[i-1] + l4[i-1])/6);
        zk.push_back(zk[i-1] + delta_zk[i-1]);
    }

    F.push_back(yk1[yk1.size()-1] - y1);
    Y.push_back(yk1[yk1.size()-1]);
    index = 1;
    do
    {// Очищаем массивы
        xk.clear();
        yk1.clear();
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
        n.push_back(n[index] - (((n[index] - n[index-1])*F[index])/(F[index] - F[index-1])));
        xk.push_back(x0);
        yk1.push_back(y0);
        zk.push_back(n[n.size()-1]);
        for(int i=1; i<size+1; i++)
        {
            xk.push_back(xk[i-1] + h);
            k1.push_back(h*Fy(zk[i-1]));
            l1.push_back(h*Fz(xk[i-1], yk1[i-1], zk[i-1]));
            k2.push_back(h*Fy(zk[i-1] + 0.5*l1[i-1]));
            l2.push_back(h*Fz(xk[i-1] + 0.5*h, yk1[i-1] + 0.5*k1[i-1], zk[i-1] + 0.5*l1[i-1]));
            k3.push_back(h*Fy(zk[i-1] + 0.5*l2[i-1]));
            l3.push_back(h*Fz(xk[i-1] + 0.5*h, yk1[i-1] + 0.5*k2[i-1], zk[i-1] + 0.5*l2[i-1]));
            k4.push_back(h*Fy(zk[i-1] + l3[i-1]));
            l4.push_back(h*Fz(xk[i-1] + h, yk1[i-1] + k3[i-1], zk[i-1] + l3[i-1]));
            delta_yk.push_back((k1[i-1] + 2*k2[i-1] + 2*k3[i-1] + k4[i-1])/6);
            yk1.push_back(yk1[i-1] + delta_yk[i-1]);
            delta_zk.push_back((l1[i-1] + 2*l2[i-1] + 2*l3[i-1] + l4[i-1])/6);
            zk.push_back(zk[i-1] + delta_zk[i-1]);
        }

        F.push_back(yk1[yk1.size()-1] - y1);
        Y.push_back(yk1[yk1.size()-1]);
        index++;
    }
    while(!CriterionTermination(F[F.size()-1], eps));
    out << "\tThe shooting method (step = " << h << ")\n";
    out << "j" << "\t" << "nj" << "\t" << "yj" << "\t" << "|Fj|" << "\n";
    for(int i=0; i<(int)(Y.size()); i++)
    {
        out << i << "\t" << n[i] << "\t" << Y[i] << "\t" << abs(F[i]) << "\n";
    }
    out << "\n\tRunge-Kutta method (step = " << h << ", n = " << n[n.size()-1] << ")\n";
    out << "k" << "\t\t" << "xk" << "\t\t" << "yk1" << "\t\t" << "zk" << "\t\t" << "delta_yk" << "\t\t" << "delta_zk" << "\t\t" << "y_true" << "\t\t" << "epsilon" << "\n";
    for(int i=0; i<size+1; i++)
    {
        if(i!=size)
            out << i << "\t" << xk[i] << "\t" << yk1[i] << "\t" << zk[i] << "\t" << delta_yk[i] << "\t" << delta_zk[i] << "\t" << Ftrue(xk[i]) << "\t" << abs(Ftrue(xk[i]) - yk1[i]) << "\n";
        else
            out << i << "\t" << xk[i] << "\t" << yk1[i] << "\t" << zk[i] << "\t" << "\t" << "\t" << Ftrue(xk[i]) << "\t" << abs(Ftrue(xk[i]) - yk1[i]) << "\n";
    }
    out << "\n";

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
    xk.push_back(x0);
    yk2.push_back(y0);
    zk.push_back(n[n.size()-1]);
    h *= 0.5;
    for(int i=1; i<2*size+1; i++)
    {// Вычисления с другим шагом
        xk.push_back(xk[i-1] + h);
        k1.push_back(h*Fy(zk[i-1]));
        l1.push_back(h*Fz(xk[i-1], yk2[i-1], zk[i-1]));
        k2.push_back(h*Fy(zk[i-1] + 0.5*l1[i-1]));
        l2.push_back(h*Fz(xk[i-1] + 0.5*h, yk2[i-1] + 0.5*k1[i-1], zk[i-1] + 0.5*l1[i-1]));
        k3.push_back(h*Fy(zk[i-1] + 0.5*l2[i-1]));
        l3.push_back(h*Fz(xk[i-1] + 0.5*h, yk2[i-1] + 0.5*k2[i-1], zk[i-1] + 0.5*l2[i-1]));
        k4.push_back(h*Fy(zk[i-1] + l3[i-1]));
        l4.push_back(h*Fz(xk[i-1] + h, yk2[i-1] + k3[i-1], zk[i-1] + l3[i-1]));
        delta_yk.push_back((k1[i-1] + 2*k2[i-1] + 2*k3[i-1] + k4[i-1])/6);
        yk2.push_back(yk2[i-1] + delta_yk[i-1]);
        delta_zk.push_back((l1[i-1] + 2*l2[i-1] + 2*l3[i-1] + l4[i-1])/6);
        zk.push_back(zk[i-1] + delta_zk[i-1]);
    }
    out << "\n\tRunge-Kutta method (step = " << h << ", n = " << n[n.size()-1] << ")\n";
    out << "k" << "\t\t" << "xk" << "\t\t" << "yk2" << "\t\t" << "zk" << "\t\t" << "delta_yk" << "\t\t" << "delta_zk" << "\t\t" << "y_true" << "\t\t" << "epsilon" << "\n";
    for(int i=0; i<2*size+1; i++)
    {
        if(i!=2*size)
            out << i << "\t" << xk[i] << "\t" << yk2[i] << "\t" << zk[i] << "\t" << delta_yk[i] << "\t" << delta_zk[i] << "\t" << Ftrue(xk[i]) << "\t" << abs(Ftrue(xk[i]) - yk2[i]) << "\n";
        else
            out << i << "\t" << xk[i] << "\t" << yk2[i] << "\t" << zk[i] << "\t" << "\t" << "\t" << Ftrue(xk[i]) << "\t" << abs(Ftrue(xk[i]) - yk2[i]) << "\n";
    }
    out << "\n\tAnswer\n"; // Вывод результата и погрешности в каждой точке
    out << "k";
    for(int i=0; i<size+1; i++)
        out << "\t\t" << i;
    out << "\nxk";
    for(int i=0; i<size+1; i++)
        out << "\t" << xk[2*i];
    out << "\nyk1";
    for(int i=0; i<size+1; i++)
        out << "\t" << yk2[i];
    out << "\nAccuracy";
    for(int i=0; i<size+1; i++)
        out << "\t" << Accuracy(yk1[i], yk2[2*i]);
    out << "\n";

    out.close();// Закрытие файла

    cout << "OK";

    return abc.exec();
}
