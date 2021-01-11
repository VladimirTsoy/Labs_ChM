#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int iter; // Счётчик числа итераций
    float accuracy = 0.0001, left = 0.0, right = M_PI, x, xk;
    QString name = "output.txt"; // Фаил вывода

    if((Sign(Function(left)) != Sign(Function(right)))&&(Sign(Derivative(left)) == Sign(Derivative(right))))
    {
        ofstream out;
        out.open(QFile::encodeName(name).data()); // Открытие файла на запись
        out << "k" << "\t" << "x" << "\t" << "f(x)" << "\t" << "f'(x)" << "\t" << "-f(x)/f'(x)" << "\n";
        if(Function(left)*Second_derivative(left) > 0.0) // Выбор начального приближения
            xk = left;
        else
            xk = right;
        iter = 0;
        do
        {
            x = xk;
            out << iter << "\t" << xk << "\t";
            xk = x-(Function(x))/(Derivative(x));
            out << Function(xk) << "\t" << Derivative(xk) << "\t" << -(Function(xk))/(Derivative(xk)) << "\n";
            iter++;
        }
        while(!CriterionTermination(xk, x, accuracy)); // Проверка удовлетворения заданной точности
        out << iter << "\t" << xk << "\n\nAnswer: x = " << xk << "\n";
        out.close();
    }
    else
        qWarning("Please, choose a different interval !");
    cout << "OK";
    
    return a.exec();
}
