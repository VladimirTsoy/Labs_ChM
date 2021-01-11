#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication abc(argc, argv);
    
    float X0 = -1.0, Xk = 1.0, h1 = 0.5, h2 = 0.25;
    QString name = "output.txt"; // Фаил вывода

    ofstream out;
    out.open(QFile::encodeName(name).data()); // Открытие файла на запись
    float d = (float)0.104471037;
//    float c = -0.0413303;
    //float b = -0.16474;
    int size1 = (int)((Xk-X0)/h1);
    int size2 = (int)((Xk-X0)/h2);
    float a = X0;
    QVector <float> x1;
    x1.push_back(a);
    for(int i=1; i<size1+1; i++) // Вычисление первообразных методами Треугольников, Трапеций и Симпсона с двумя различными шагами
    {
        a += h1;
        x1.push_back(a);
    }
    out << "\tMethods of numerical integration (step = " << h1 << ")\n\n";
    out << "i" << "\t" << "x[i]" << "\t" << "y[i]" << "\t" << "Rectangles" << "\t" << "Trapezoids" << "\t" << "Simpson" << "\n";
    for(int i=0; i<size1+1 ; i++)
    {
        if(i%2==0)
            out << i << "\t" << x1[i] << "\t" << Function(x1[i]) << "\t" << Rectangles(x1, h1, i) << "\t" << Trapezoids(x1, h1, i) << "\t" << Simpson(x1, h1, i) << "\n";
        else
            out << i << "\t" << x1[i] << "\t" << Function(x1[i]) << "\t" << Rectangles(x1, h1, i) << "\t" << Trapezoids(x1, h1, i) << "\n";
    }
    a = X0;
    QVector <float> x2;
    x2.push_back(a);
    for (int i=0; i<size2+1; i++)
    {
        a += h2;
        x2.push_back(a);
    }
    out << "\n\n\n\tMethods of numerical integration (step = " << h2 << ")\n\n";
    out << "i" << "\t" << "x[i]" << "\t" << "y[i]" << "\t" << "Rectangles" << "\t" << "Trapezoids" << "\t" << "Simpson" << "\n";
    for(int i=0; i<size2+1 ; i++)
    {
        if(i%2==0)
            out << i << "\t" << x2[i] << "\t" << Function(x2[i]) << "\t" << Rectangles(x2, h2, i) << "\t" << Trapezoids(x2, h2, i) << "\t" << Simpson(x2, h2, i) << "\n";
        else
            out << i << "\t" << x2[i] << "\t" << Function(x2[i]) << "\t" << Rectangles(x2, h2, i) << "\t" << Trapezoids(x2, h2, i) << "\n";
    }
    out << "\n\n\n\tAbsolute accuracy of calculations\n\n";
    out << "The exact value" << "\t" << "Rectangles" << "\t" << "Trapezoids" << "\t" << "Simpson" << "\n";
        out << d << "\t\t" << Accuracy2(Rectangles(x1,h1,size1), Rectangles(x2,h2,size2), h1, h2) << "\t" << Accuracy2(Trapezoids(x1,h1,size1), Trapezoids(x2,h2,size2), h1, h2) << "\t" << Accuracy2(Simpson(x2,h2,size2), Simpson(x1,h1,size1), h2, h1) << "\n"; // Вычисление погрешностей интегрирования
    out << "\t\t\t" << Accuracy1(Rectangles(x1,h1,size1), Rectangles(x2,h2,size2), h1, h2) << "\t" << Accuracy1(Trapezoids(x1,h1,size1), Trapezoids(x2,h2,size2), h1, h2) << "\t" << Accuracy1(Simpson(x2,h2,size2), Simpson(x1,h1,size1), h2, h1) << "\n"; // Уточнение результатов интегрирования
    out << "\t\t\t\t" << abs(d - Accuracy1(Rectangles(x1,h1,size1), Rectangles(x2,h2,size2), h1, h2)) << "\t" << abs(d - Accuracy1(Trapezoids(x1,h1,size1), Trapezoids(x2,h2,size2), h1, h2)) << "\t" << abs(d - Accuracy1(Simpson(x2,h2,size2), Simpson(x1,h1,size1), h2, h1)) << "\n";
    out.close(); // Закрытие файла

    cout << "OK";

    return abc.exec();
}
