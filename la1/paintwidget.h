#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QVector>
#include <QObject>

#define minimum 0.0000000000000001
#define maximum 9
#define N 4 //Размерность исходной матрицы

class KeyLine: public QLineEdit
{
    Q_OBJECT
public:
    explicit KeyLine(const char *, QWidget* parent=0) : QLineEdit(parent)
    {
        autoCompleteList = new QStringList();
    }
    ~KeyLine()
    {
        delete autoCompleteList;
    }
    void setAutoCompleteList(const QStringList &list)
    {
        (*autoCompleteList) = list;
    }
    int myDigit;
private:
        QStringList * autoCompleteList;
};

class PaintWidget : public QWidget
{
    Q_OBJECT

public:
       QVector < QLineEdit * > arr_L;
       QVector < QLineEdit * > arr_U;
       QVector < QLineEdit * > arr_b;
       QVector < QLineEdit * > arr_inverse;
       QVector < KeyLine * > arr_input;
       PaintWidget(QVector < QLineEdit *> &arr_L, QVector < QLineEdit *> &arr_U, QVector < QLineEdit *> &arr_b, QVector < QLineEdit *> &arr_inverse, QVector < KeyLine *> &arr_input, QWidget *_parent = 0);

       void Test(double _mas[N][N]);
       void Test(double _mas[N]);
       void PLU(double _x[N][N], double _l[N][N], double _u[N][N], double _p[N][N], double _y[N]);
       void PLUinverse(double _u[N][N], double _y[N]);
       void SwapRows(double _mas[N][N], int _i, int _j);
       void SwapRows(double _mas[N], int _i, int _j);
       void Assignment(double _mas[N][N], double _mas2[N][N]);
       void Assignment(double _mas[N], double _mas2[N]);
       void Transp(double _mas[N][N]);
       void Determinant(double _mas[N][N], QVector < QLineEdit *> & _arr);
       void PrintArr(QVector < QLineEdit *> & _arr, double _mas[N][N]);
       void PrintArr(QVector < QLineEdit *> & _arr, double _mas[N]);
       void PrintArr(QVector < KeyLine *> & _arr, double _mas2[N][N], double _mas[N]);
       void NullMas(double _mas[N][N]);
       void NullMas(double _mas[N]);
       void IdentityMas(double _mas[N][N]);
       void MultiMas(double _mas[N][N], double _mas2[N][N], double _mas3[N][N]);
       void MultiMas(double _mas[N][N], double _mas2[N], double _mas3[N]);

public slots:
    /// слот - вызывается при изменении текста в QLineEdit, подключен с помощью QObject::connect
        void ChangeX( const QString & _text );
        void ChangeName1( const QString & _text );
        void ChangeName2( const QString & _text );
        void Action();
        void InputMas();
        void OutputAnswer();
        void Refreash();

private:
        double x[N][N], y[N], l[N][N], u[N][N], p[N][N], inv[N][N], temp[N][N], temp2[N], I[N];
        int index;
        QString name1, name2;
};

#endif // PAINTWIDGET_H
