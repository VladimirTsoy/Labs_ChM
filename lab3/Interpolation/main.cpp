#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    float x[N], Xk, w[N];
    QString name1 = "input5.txt", name2 = "output.txt";

    Xk = InputMas(name1, x); // Считывание из файла

    ofstream out;
    out.open(QFile::encodeName(name2).data()); // Открытие файла на запись
    out << "i" << "\t" << "x[i]" << "\t" << "F(x[i])" << "\t" << "w'(x[i])" << "\t" << "F(x[i])/w'(x[i])" << "\t" << "Xk - x[i]" << "\n";
    for(int i=0; i<N; i++) // Вывод таблицы для построения многочлена Лагранжа в файл
    {
        w[i] = W(x, i);
        out << i << "\t" << x[i] <<  "\t" << F(x[i]) << "\t" << w[i] << "\t" << F(x[i])/w[i] << "\t" << Xk-x[i] << "\n";
    }
    out << "\nL(x) = "; // Вывод многочлена Лагранжа в файл
    if(F(x[0])/w[0] == 0)
        out << abs(F(x[0])/w[0]) << "*";
    else
        out << F(x[0])/w[0] << "*";
    for(int i=0; i<N;i++)
    {
        if(i!=0)
        {
            if(F(x[i])/w[i] > 0.0)
                out << " + " << abs(F(x[i])/w[i]);
            else if(F(x[i])/w[i] < 0.0)
                out << " - " << abs(F(x[i])/w[i]);
            else
                out << " + 0*";
        }
        for(int j=0; j<N; j++)
        {
            if(j!=i)
            {
                if (x[j]>0.0)
                    out << "(x - " << abs(x[j]) << ")";
                else if(x[j]<0.0)
                    out << "(x + " << abs(x[j]) << ")";
                else
                    if(i == N-1)
                        out << "*x";
                    else
                        out << "*x*";
            }
        }
    }
    out << "\n\nL(" << Xk << ") = " << L(x, w, Xk) << "\t\ty(" << Xk << ") = " << F(Xk);
    out << "\t\tdelta(L(" << Xk << ")) = " << abs(L(x, w, Xk)-F(Xk)) << "\n";
    out << "\n\n\ni" << "\t" << "x[i]" << "\t" << "F(x[i])" << "\t" << "F(x[i],x[i+1])" << "\t" << "F(x[i],x[i+1],x[i+2])" << "\t" << "F(x[i],x[i+1],x[i+2],x[i+3])" << "\n";
    for(int i=0; i<N; i++) // Вывод таблицы для построения многочлена Ньютона в файл
    {
        out << i << "\t" << x[i]; //<<  "\t" << F(x[i]);out << "\t" << FP(x, i, 1);out << "\t" << FP(x, i, 2);out << "\t" << FP(x, i, 3);
        for(int j=0; j<N-i; j++)
            out << "\t\t" << FP(x, i, j);
        out << "\n";
    }
    out << "\nP(x) = "; // Вывод многочлена Ньютона в файл
    for(int i=0; i<N;i++)
    {
        if(i!=0)
        {
            if(FP(x, 0, i) > 0.0)
            {
                if(i == 1)
                    out << abs(FP(x, 0, i));
                else
                    out << " + " << abs(FP(x, 0, i));
            }
            else if(FP(x, 0, i) < 0.0)
                out << " - " << abs(FP(x, 0, i));
            else
                out << " + 0*";
        }
        for(int j=0; j<i+1; j++)
        {
            if(j!=i)
            {
                if (x[j]>0.0)
                    out << "(x - " << abs(x[j]) << ")";
                else if(x[j]<0.0)
                    out << "(x + " << abs(x[j]) << ")";
                else
                {
                    if(i == N-1)
                        out << "*x";
                    else
                        out << "*x*";
                }
            }
        }
    }
    out << "\n\nP(" << Xk << ") = " << P(x, Xk) << "\t\ty(" << Xk << ") = " << F(Xk);
    out << "\t\tdelta(P(" << Xk << ")) = " << abs(P(x, Xk)-F(Xk)) << "\n";
    out.close();

    cout << "OK";

    return a.exec();
}
