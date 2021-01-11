#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int iter; // Счётчик колличества итераций
    float accuracy = (float)0.1, left = (float)0.0, right = M_PI, x, xk, q;
    QString name = "output.txt"; // Фаил вывода

    if((Sign(Function(left)) != Sign(Function(right)))&&(Sign(Derivative(left)) == Sign(Derivative(right))))
    {
        if((Fi(left)>=left)&&(Fi(left)<=right)&&(Fi(right)>=left)&&(Fi(right)<=right))
        {
            if((abs(Fi_der(left))<1)&&(abs(Fi_der(right))<1))
            {
                ofstream out;
                out.open(QFile::encodeName(name).data()); // Открытие файла на запись
                out << "k" << "\t" << "x" << "\t" << "fi(x)" << "\n";
                xk = (left+right)/2; // Выбор начального приближения
                iter = 0;
                do
                {
                    x = xk;
                    out << iter << "\t" << xk << "\t";
                    q = abs(Fi_der(xk));
                    xk = Fi(x);
                    out << Fi(xk) << "\n";
                    iter++;
                }
                while(!CriterionTermination(xk, x, q, accuracy)); // Проверка удовлетворения заданной точности
                out << iter << "\t" << xk << "\n\nAnswer: x = " << xk << "\n"; // Вывод ответа
                out.close();
            }
            else
            {
                qWarning("Please, choose a different interval !");
                qWarning("Becouse, |fi'(x)| >= 1 for some x = [%f, %f].", left, right);
            }
        }
        else
        {
            qWarning("Please, choose a different interval !");
            qWarning("Becouse, fi(x) != [%f,%f] for some x = [%f, %f].", left, right, left, right);
        }
    }
    else
    {
        qWarning("Please, choose a different interval !");
        qWarning("Becouse, function is not monotonic");
        qWarning("or there is no solution in this interval: [%f, %f]", left, right);
    }
    cout << "OK";

    return a.exec();
}
