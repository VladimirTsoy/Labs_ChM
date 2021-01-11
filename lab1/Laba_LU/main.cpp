#include "wid.h"
int main(/*int argc, char *argv[]*/) {
//    QCoreApplication a(argc, argv);
    /// переменные для
    char name1[30];// Название файла для считывания
    char name2[30];// Название файла для записи
    char ok;// Пдтверждение для повторного выполнения программы
    double x[N][N];// Матрица системы
    double y[N];// Вектор правых частей системы
    double l[N][N];// Матрица L
    double u[N][N];// Матрица U
    double p[N][N];// Матрица перестановок
    double inv[N][N];// Обратная матрица
    double temp[N][N];// Временный двумерный массив для проверки вычислений
    double temp2[N];// Временный одномерный массив для проверки вычислений
    double I[N];// Столбец еденичной матрицы
    int index; // Количество перестановок
    int okey;//Для  зацикливания программы(повторного выполнения)

    do {
    cout << "Please, enter the name of file for input matrix:\n";
        cin >> name1;
        cout << "Please, enter the name of file for output answer:\n";
        cin >> name2;
        index = 0.0;
        InputMas(x, y, name1);
        PLU(x, l, u, p, y, index);// Выполняем LU разложение

        Determinant(u, index);// Вычисляем определитель

        MultiMas(l, u, temp);// Проверяем,что произведение L на U дают
        //исходную матрицу с точностью до перестановок строк

        PLUinverse(u, y);//Находим корни из матрицы U

        MultiMas(x, y, temp2);//Проверяем,что произведение исходной
        //матрицы на вектор корней равен правой части

        for(int i=0;i<N;i++)//Поиск обратной матрицы
        {
            NullMas(I);
            I[i] = 1.0;

            NullMas(l);
            IdentityMas(l);

            NullMas(u);

            NullMas(p);
            IdentityMas(p);

            PLU(x, l, u, p, I, index);
            PLUinverse(u, I);

            for(int j=0;j<N;j++)
            {
                inv[j][i] = I[j];
            }
        }

        NullMas(temp);

        MultiMas(x, inv, temp);// Умножение исходной матрицы на
                              // обратную(должна получиться еденичная)

        OutputAnswer(l, u, p, inv, y, name2);//Вывод результатов в файл
      // Выводим результаты в консоль
        cout << "\tMatrix L\n";
        Test2(l);
        cout << "\tMatrix U\n";
        Test2(u);
        cout << "\tMatrix P\n";
        Test2(p);
        cout << "\tMatrix Invers\n";
        Test2(inv);
        cout << "\tVector Y\n";
        Test1(y);

        cout << "\nDo you want the restart this programm ? (y/n)\n";
        cin >> ok;
        if (ok == 'y')
            okey = 1;
        else
            okey = 0;
        cout << "\n";
    }
    while(okey);

    return 0/*a.exec()*/;
}
