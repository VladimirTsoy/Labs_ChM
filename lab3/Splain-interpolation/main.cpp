#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication abc(argc, argv);

    int index;
    float a[N-2], b[N-2], c[N-2], f[N-2], x[N-2], Xk[N], Fk[N], Dot, h[N], Ck[N-1], Ak[N-1], Bk[N-1], Dk[N-1];
    QString name1 = "input3.txt", name2 = "output.txt"; // Имена файлов ввода/вывода

    Dot = InputMas(name1, Xk, Fk, h, c, b, a, f, index); // Считывание из файла

    ofstream out;
    out.open(QFile::encodeName(name2).data()); // Открытие файла на запись
    SolveMatrix (a, c, b, f, x, N-2); // Построение интерполирующего многочлена
    Ck[0] = 0.0;
    for (int i=1; i<N-1; i++)
        Ck[i] = x[i-1];
    for(int i=0; i<N-1; i++)
        Ak[i] = Fk[i];
    for(int i=0; i<N-2; i++)
    {
        Bk[i] = ((Fk[i+1]-Fk[i])/h[i+1])-(h[i+1]/3)*(Ck[i+1]+2*Ck[i]);
        Dk[i] = (Ck[i+1]-Ck[i])/(3*h[i+1]);
    }
    Bk[N-2] = ((Fk[N-1]-Fk[N-2])/h[N-1]) - (2*h[N-1]*Ck[N-2])/3;
    Dk[N-2] = - (Ck[N-2])/(3*h[N-1]);
    out << "i" << "\t" << "[ x[i-1],x[i] ]" << "\t" << "a[i]" << "\t\t" << "b[i]" << "\t\t" << "c[i]" << "\t\t\t" << "d[i]" << "\n";
    for(int i=0; i<N-1; i++)
    {
        out << i+1 << "\t[" << Xk[i] << "," << Xk[i+1] << "]\t\t\t" << Ak[i] << "\t" << Bk[i] << "\t" << Ck[i] << "\t" << Dk[i] << "\n";
    }
    out << "\nf(x) = " << Ak[index]; // Вывод интерполирующего многочлена
    for(int i=0; i<N-2; i++)
    {
        if(i==0)
        {
            if(Bk[index] < 0.0)
                out << " - " << abs(Bk[index]);
            else
                out << " + " << Bk[index];
        }
        if(i==1)
        {
            if(Ck[index] < 0.0)
                out << " - " << abs(Ck[index]);
            else
                out << " + " << Ck[index];
        }
        if(i==2)
        {
            if(Dk[index] < 0.0)
                out << " - " << abs(Dk[index]);
            else
                out << " + " << Dk[index];
        }
        out << "*(x";
        if(Xk[index] < 0.0)
            out << " + " << abs(Xk[index]) << ")";
        else
            out << " - " << abs(Xk[index]) << ")";
        if(i != 0)
            out << "^" << i+1;
    }
    out << "\n\nf(" << Dot << ") = " << F(Ak[index], Bk[index], Ck[index], Dk[index], Xk[index], Dot) << "\n";
    out.close(); // Закрытие файла

    cout << "OK";

    return abc.exec();
}
