#include <QApplication>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDoubleValidator>
#include <QSizePolicy>
#include <QLabel>
#include <QTextCodec>
#include <QPushButton>
#include <QVector>

#include "paintwidget.h"

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));

        // виджет - контейнер

        QWidget MainWdg;
        QPalette plt1 = MainWdg.palette();
        plt1.setColor(QPalette::Window, QColor(255,255,0));
        plt1.setColor(QPalette::Base, QColor(0,255,255));
        plt1.setColor(QPalette::Text, QColor(150,00,150));
        plt1.setColor(QPalette::WindowText, QColor(250,00,00));
        MainWdg.setPalette(plt1);

        QLabel * Label1, * Label2, * Label3, * Label4, * Label7, * Label8, * Label9;
        if(N < maximum)
        {
            Label1 = new QLabel(QObject::tr("\tМатрица L"), &MainWdg);
            Label2 = new QLabel(QObject::tr("\t       Матрица U"), &MainWdg);
            Label3 = new QLabel(QObject::tr("     "), &MainWdg);
            Label7 = new QLabel(QObject::tr("       Решение"), &MainWdg);
            Label8 = new QLabel(QObject::tr("\t\tВведите матрицу"), &MainWdg);
            Label9 = new QLabel(QObject::tr("                  Обратная матрица"), &MainWdg);
        }
        Label4 = new QLabel(QObject::tr("Определитель матрицы: "), &MainWdg);

        // создаем поля ввода

        QVector < KeyLine * > arr_input;  //Вектор QLineEdit-ов Входной матрицы
        if(N < maximum)
        {
            for(int i=0;i<N*N+N;i++)
            {
                    arr_input.push_back(new KeyLine  ("0", &MainWdg));
                    arr_input[i]->myDigit = i;
            }
        }

        QVector < QLineEdit * > arr_L;  //Вектор QLineEdit-ов матрицы L
        int k = 1;
        if(N < maximum)
        {
            for(int i=0;i<N*N;i++)
            {
                if((i+1)%(N+1) == 1)
                    arr_L.push_back(new QLineEdit  ("1", &MainWdg));
                else if(i%N == 0)
                {
                    for(int j=0;j<k;(j++)&&(i++))
                    {
                        arr_L.push_back(new QLineEdit  ("", &MainWdg));
                    }
                    k++;
                }
                else
                    arr_L.push_back(new QLineEdit  ("0", &MainWdg));
            }
        }

        QVector < QLineEdit * > arr_U;  //Вектор QLineEdit-ов матрицы U
        if(N < maximum)
        {
            k = N;
            for(int i=0;i<N*N;i++)
            {
                if((i+1)%(N+1) == 1)
                {
                    for(int j=0;j<k;(j++)&&(i++))
                        arr_U.push_back(new QLineEdit  ("", &MainWdg));
                    k--;
                }
                else
                    arr_U.push_back(new QLineEdit  ("0", &MainWdg));
            }
        }

        QVector < QLineEdit * > arr_inverse;    //Вектор QLineEdit-ов обратной матрицы
        if(N < maximum)
        {
            for(int i=0;i<N*N;i++)
                arr_inverse.push_back(new QLineEdit  ("", &MainWdg));
        }

        QVector < QLineEdit * > arr_b;  //Вектор QLineEdit-ов правой части системы
        if(N < maximum)
        {
            for(int i=0;i<N;i++)
                arr_b.push_back(new QLineEdit  ("", &MainWdg));
        }

        arr_b.push_back(new QLineEdit  ("", &MainWdg));//N
//        arr_b[N]->setMaximumWidth(100);
        arr_b.push_back(new QLineEdit  ("input.txt", &MainWdg));//N+1
//        arr_b[N+1]->setMaximumWidth(80);
        arr_b.push_back(new QLineEdit  ("output.txt", &MainWdg));//N+2

        if(N < maximum)
        {
            for(int i=0;i<N*N+N;i++)
            {
                QPalette plt2 = arr_input[i]->palette();
                plt2.setColor(QPalette::Base, QColor(255,200,255));
                plt2.setColor(QPalette::Text, QColor(50,50,250));
                arr_input[i]->setPalette(plt2);
                arr_b[N+1]->setPalette(plt2);
                arr_b[N+2]->setPalette(plt2);
            }
        }
        else
        {
            QPalette plt2 = arr_b[0]->palette();
            plt2.setColor(QPalette::Base, QColor(255,200,255));
            plt2.setColor(QPalette::Text, QColor(50,50,250));
            arr_b[1]->setPalette(plt2);
            arr_b[2]->setPalette(plt2);
        }

        // создаем виджет
        PaintWidget* pPaintWdg = new PaintWidget(arr_L, arr_U, arr_b, arr_inverse, arr_input, &MainWdg);
        pPaintWdg->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        pPaintWdg->setMaximumWidth(0);

        if(N < maximum)
        {
            for(int i=0;i<N*N+N;i++)
                QObject::connect(arr_input[i], SIGNAL(textChanged ( const QString & )), pPaintWdg, SLOT(ChangeX ( const QString & )));

            QObject::connect(arr_b[N+1], SIGNAL(textChanged ( const QString & )), pPaintWdg, SLOT(ChangeName1 ( const QString & )));
            QObject::connect(arr_b[N+2], SIGNAL(textChanged ( const QString & )), pPaintWdg, SLOT(ChangeName2 ( const QString & )));
        }
        else
        {
            QObject::connect(arr_b[1], SIGNAL(textChanged ( const QString & )), pPaintWdg, SLOT(ChangeName1 ( const QString & )));
            QObject::connect(arr_b[2], SIGNAL(textChanged ( const QString & )), pPaintWdg, SLOT(ChangeName2 ( const QString & )));
        }

        QPushButton* pButton = new QPushButton(QObject::tr ("Посчитать"), &MainWdg);
        QObject::connect(pButton, SIGNAL(clicked()), pPaintWdg, SLOT(Action()));
        //pButton->setMaximumWidth(500);

        QPushButton* pButton2 = new QPushButton(QObject::tr ("Загрузить из файла"), &MainWdg);
        QObject::connect(pButton2, SIGNAL(clicked()), pPaintWdg, SLOT(InputMas()));
        //pButton2->setMaximumWidth(200);

        QPushButton* pButton3 = new QPushButton(QObject::tr ("Обнулить"), &MainWdg);
        QObject::connect(pButton3, SIGNAL(clicked()), pPaintWdg, SLOT(Refreash()));
        //pButton3->setMinimumWidth(100);

        QPushButton* pButton4 = new QPushButton(QObject::tr ("Записать в фаил"), &MainWdg);
        QObject::connect(pButton4, SIGNAL(clicked()), pPaintWdg, SLOT(OutputAnswer()));
        //pButton2->setMaximumWidth(200);

        QVector < QHBoxLayout * > pLayoutCapacity2;
        if(N < maximum)
        {
            k = 0;
            for(int i=0;i<N;i++)
            {
                pLayoutCapacity2.push_back(new QHBoxLayout);
                for(int j=0;j<N-1;j++)
                {
                    pLayoutCapacity2[i]->addWidget(arr_input[k++]);
                    pLayoutCapacity2[i]->addWidget( new QLabel(QObject::tr(" * x"), &MainWdg));
                    pLayoutCapacity2[i]->addWidget( new QLabel(QString().setNum(j+1), &MainWdg));
                    pLayoutCapacity2[i]->addWidget( new QLabel(QObject::tr(" + "), &MainWdg));
                }
                pLayoutCapacity2[i]->addWidget(arr_input[k++]);
                pLayoutCapacity2[i]->addWidget( new QLabel(QObject::tr(" * x"), &MainWdg));
                pLayoutCapacity2[i]->addWidget( new QLabel(QString().setNum(N), &MainWdg));
                pLayoutCapacity2[i]->addWidget( new QLabel(QObject::tr("     = "), &MainWdg));
                pLayoutCapacity2[i]->addWidget(arr_input[k++]);
            }
        }

        QVector < QHBoxLayout * > pLayoutCapacity3;
        if(N < maximum)
        {
            k = 0;
            for(int i=0;i<N;i++)
            {
                pLayoutCapacity3.push_back(new QHBoxLayout);
                for(int j=0;j<N;j++)
                    pLayoutCapacity3[i]->addWidget(arr_L[k++]);
            }
        }

        QVector < QHBoxLayout * > pLayoutCapacity4;
        if(N < maximum)
        {
            k = 0;
            for(int i=0;i<N;i++)
            {
                pLayoutCapacity4.push_back(new QHBoxLayout);
                pLayoutCapacity4[i]->addWidget(Label3);
                for(int j=0;j<N;j++)
                    pLayoutCapacity4[i]->addWidget(arr_U[k++]);
            }
        }

        QVector < QHBoxLayout * > pLayoutCapacity5;
        if(N < maximum)
        {
            k = 0;
            for(int i=0;i<N;i++)
            {
                pLayoutCapacity5.push_back(new QHBoxLayout);
                pLayoutCapacity5[i]->addWidget(Label3);
                for(int j=0;j<N;j++)
                    pLayoutCapacity5[i]->addWidget(arr_inverse[k++]);
            }
        }

        QVector < QHBoxLayout * > pLayoutCapacity6;
        if(N < maximum)
        {
            for(int i=0;i<N;i++)
            {
                pLayoutCapacity6.push_back(new QHBoxLayout);
                pLayoutCapacity6[i]->addWidget( new QLabel(QObject::tr("     x"), &MainWdg));
                pLayoutCapacity6[i]->addWidget( new QLabel(QString().setNum(i+1), &MainWdg));
                pLayoutCapacity6[i]->addWidget( new QLabel(QObject::tr(" = "), &MainWdg));
                pLayoutCapacity6[i]->addWidget(arr_b[i]);
            }
        }

        QHBoxLayout* pLayout6 = new QHBoxLayout;
        pLayout6->addWidget(pButton);
        pLayout6->addWidget(Label4);
        if(N < maximum)
            pLayout6->addWidget(arr_b[N]);
        else
            pLayout6->addWidget(arr_b[0]);

        QHBoxLayout* pLayout10 = new QHBoxLayout;
        pLayout10->addWidget(pButton2);
        if(N < maximum)
            pLayout10->addWidget(arr_b[N+1]);
        else
            pLayout10->addWidget(arr_b[1]);
        pLayout10->addWidget(pButton4);
        if(N < maximum)
            pLayout10->addWidget(arr_b[N+2]);
        else
            pLayout10->addWidget(arr_b[2]);

        QVBoxLayout* pLayout1 = new QVBoxLayout;
        if(N < maximum)
        {
            pLayout1->addWidget(Label8);
            for(int i = 0; i<N; i++)
                pLayout1->addLayout(pLayoutCapacity2[i]);
        }
        pLayout1->addLayout(pLayout10);


        QVBoxLayout* pLayout2 = new QVBoxLayout;
        if(N < maximum)
        {
            pLayout2->addWidget(Label1);
            for(int i = 0; i<N; i++)
                pLayout2->addLayout(pLayoutCapacity3[i]);
        }

        QVBoxLayout* pLayout3 = new QVBoxLayout;
        if(N < maximum)
        {
            pLayout3->addWidget(Label2);
            for(int i = 0; i<N; i++)
                pLayout3->addLayout(pLayoutCapacity4[i]);
        }

        QHBoxLayout* pLayout11 = new QHBoxLayout;
        if(N < maximum)
        {
            pLayout11->addWidget(Label3);
            Label3->setMaximumWidth(16);
        }
        pLayout11->addWidget(pButton3);

        QVBoxLayout* pLayout8 = new QVBoxLayout;
        if(N < maximum)
        {
            pLayout8->addWidget(Label9);
            for(int i = 0; i<N; i++)
                pLayout8->addLayout(pLayoutCapacity5[i]);
        }
        pLayout8->addLayout(pLayout11);


        QVBoxLayout* pLayout7 = new QVBoxLayout;
        if(N < maximum)
        {
            pLayout7->addWidget(Label7);
            for(int i = 0; i<N; i++)
                pLayout7->addLayout(pLayoutCapacity6[i]);
        }

        QHBoxLayout* pLayout9 = new QHBoxLayout;
        pLayout9->addLayout(pLayout1);
        pLayout9->addLayout(pLayout8);

        QHBoxLayout* pLayout4 = new QHBoxLayout;
        if(N < maximum)
        {
            pLayout4->addLayout(pLayout2);
            pLayout4->addLayout(pLayout3);
            pLayout4->addLayout(pLayout7);
        }

        QVBoxLayout* pLayout5 = new QVBoxLayout;
        pLayout5->addLayout(pLayout9);
        pLayout5->addLayout(pLayout6);
        if(N < maximum)
            pLayout5->addLayout(pLayout4);

        QHBoxLayout* pLayout = new QHBoxLayout;
        pLayout->addLayout(pLayout5);
        pLayout->addWidget(pPaintWdg);

        MainWdg.setLayout (pLayout );

        MainWdg.setWindowTitle(QObject::tr("LU - разложение"));

        // показываем виджет
        MainWdg.resize(300,300);
        MainWdg.show();

        return a.exec();
}
