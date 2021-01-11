#include <QtCore/QCoreApplication>
#include "wid.h"

int main(int argc, char *argv[])
{
    QCoreApplication asd(argc, argv);
    
    int iter; // Счётчик числа итераций
    float accuracy = 0.01, left1 = 0.25, right1 = 0.75, left2 = 2.0, right2 = 2.5, x[N], xk[N], q;
    QString name = "output.txt"; // Имя файла вывода резуцльтата

    ofstream out;
    out.open(QFile::encodeName(name).data()); // Открытие файла на запись
    out << "k" << "\t" << "x1" << "\t" << "fi1(x1,x2)" << "\n";
    out << "\t" << "x2" << "\t" << "fi2(x1,x2)" << "\n";
    out << "--------------------------------------------------" << "\n";
    xk[0] = (left1 + right1)/2;
    xk[1] = (left2 + right2)/2;
    iter = 0;
    do
    {
        x[0] = xk[0];
        x[1] = xk[1];
        if((x[0] > left1)&&(x[0] < right1)&&(x[1]>left2)&&(x[1]<right2))
        {
            if(abs(Fi1_der_x1(x[0], x[1])) + abs(Fi1_der_x2(x[0], x[1])) < abs(Fi2_der_x1(x[0], x[1])) + abs(Fi2_der_x2(x[0], x[1])))
                q = abs(Fi2_der_x1(x[0], x[1])) + abs(Fi2_der_x2(x[0], x[1]));
            else
                q = abs(Fi1_der_x1(x[0], x[1])) + abs(Fi1_der_x2(x[0], x[1]));
            if(q >= 1)
            {
                qWarning ("Please, choose a different interval !");
                qFatal ("Becouse, max ||fi'(x1, x2)|| >= 1.");
            }
            out << iter << "\t" << x[0] << "\t" << Fi1(x[0], x[1]) << "\n";
            out << "\t" << x[1] << "\t" << Fi2(x[0], x[1]) << "\n";

            xk[0] = Fi1(x[0], x[1]);
            xk[1] = Fi2(x[0], x[1]);
            out << "--------------------------------------------------" << "\n";
            iter++;
        }
        else
        {
            qWarning ("Please, choose a different interval !");
            qFatal ("Becouse, successive approximations of the solution left the search area.");
        }
    }
    while(!CriterionTermination(xk, x, q, accuracy)); // Проверка выполнения критерия окончания
    out << iter << "\t" << xk[0] << "\n" << "\t" << xk[1] << "\n\nAnswer: \tx1 = " << xk[0] << "\n\t\tx2 = " << xk[1] << "\n"; // Вывод ответа
    cout << "OK";
    out.close(); // Закрытие файла

    return asd.exec();
}
