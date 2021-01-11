#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication abc(argc, argv);
    
    float x[N], y[N], a[N][N], detA1, detA2, b[N], c[N];

    QString name1 = "input3.txt", name2 = "output.txt"; // Файлы ввода/вывода информации

    InputMas(name1, x, y); // Считывание данных из файла

    ofstream out;
    out.open(QFile::encodeName(name2).data()); // Открытие файла на запись
    NullMas(a); // Вычисление аппроксимирующего полинома 1 степени
    a[0][0] = N;
    for(int i=0;i < N;i++)
    {
        a[0][1] += x[i];
        a[1][0] += x[i];
        a[1][1] += x[i]*x[i];
    }
    detA1 = Determinant2x2(a);
    a[0][0] = 0.0;
    a[1][0] = 0.0;
    for(int i=0;i < N;i++)
    {
        a[0][0] += y[i];
        a[1][0] += y[i]*x[i];
    }
    detA2 = Determinant2x2(a);
    b[0] = detA2/detA1;
    NullMas(a);
    a[0][0] = N;
    for(int i=0;i<N;i++)
    {
        a[1][0] += x[i];
        a[0][1] += y[i];
        a[1][1] += y[i]*x[i];
    }
    detA2 = Determinant2x2(a);
    b[1] = detA2/detA1;
    out << "i" << "\t";
    for(int i=0;i<N-1;i++)
    {
        out << i << "\t";
    }
    out << N-1 << "\n";
    out << "x[i]" << "\t";
    for(int i=0;i<N-1;i++)
    {
        out << x[i] << "\t";
    }
    out << x[N-1] << "\n";
    out << "F1(x[i])" << "\t";
    for(int i=0;i<N-1;i++)
    {
        out << Function1(b, x[i]) << "\t";
    }
    out << Function1(b, x[N-1]) << "\n\n\n\n";

    NullMas(a); // Вычисление аппроксимирующего полинома 2 степени
    a[0][0] = N;
    for(int i=0; i<N; i++)
    {
        a[0][1] += x[i];
        a[1][0] += x[i];
        a[0][2] += x[i]*x[i];
        a[1][1] += x[i]*x[i];
        a[2][0] += x[i]*x[i];
        a[1][2] += x[i]*x[i]*x[i];
        a[2][1] += x[i]*x[i]*x[i];
        a[2][2] += x[i]*x[i]*x[i]*x[i];
    }
    detA1 = Determinaton3x3(a);
    a[0][0] = 0.0;
    a[1][0] = 0.0;
    a[2][0] = 0.0;
    for(int i=0; i<N; i++)
    {
        a[0][0] += y[i];
        a[1][0] += y[i]*x[i];
        a[2][0] += y[i]*x[i]*x[i];
    }
    detA2 = Determinaton3x3(a);
    c[0] = detA2/detA1;
    NullMas(a);
    a[0][0] = N;
    for(int i=0; i<N; i++)
    {
        a[1][0] += x[i];
        a[2][0] += x[i]*x[i];
        a[0][2] += x[i]*x[i];
        a[1][2] += x[i]*x[i]*x[i];
        a[2][2] += x[i]*x[i]*x[i]*x[i];
        a[0][1] += y[i];
        a[1][1] += y[i]*x[i];
        a[2][1] += y[i]*x[i]*x[i];

    }
    detA2 = Determinaton3x3(a);
    c[1] = detA2/detA1;
    NullMas(a);
    a[0][0] = N;
    for(int i=0; i<N; i++)
    {
        a[1][0] += x[i];
        a[2][0] += x[i]*x[i];
        a[0][1] += x[i];
        a[1][1] += x[i]*x[i];
        a[2][1] += x[i]*x[i]*x[i];
        a[0][2] += y[i];
        a[1][2] += y[i]*x[i];
        a[2][2] += y[i]*x[i]*x[i];

    }
    detA2 = Determinaton3x3(a);
    c[2] = detA2/detA1;
    out << "i" << "\t";
    for(int i=0;i<N-1;i++)
    {
        out << i << "\t";
    }
    out << N-1 << "\n";
    out << "x[i]" << "\t";
    for(int i=0;i<N-1;i++)
    {
        out << x[i] << "\t";
    }
    out << x[N-1] << "\n";
    out << "F2(x[i])" << "\t";
    for(int i=0;i<N-1;i++)
    {
        out << Function2(c, x[i]) << "\t";
    }
    out << Function2(c, x[N-1]) << "\n";

    cout << "F1(x) = " << b[0] << " + " << b[1] << "*x\n";
    cout << "F2(x) = " << c[0] << " + " << c[1] << "*x + " << c[2] << "*x^2\n";
    cout << "OK";

    out << "\nF1(x) = " << b[0] << " + " << b[1] << "*x\n\n";
    out << "F2(x) = " << c[0] << " + " << c[1] << "*x + " << c[2] << "*x^2\n";

    out.close(); // Закртыие файла

    return abc.exec();
}
