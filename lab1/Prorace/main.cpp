#include <QtCore/QCoreApplication>
#include "wid.h"
#define N 4

int main(int argc, char *argv[])
{
    QCoreApplication asd(argc, argv);
    double a[N],b[N],c[N],f[N],x[N];
    char namefile[10]; // ��� ����� ����������
    char out_ans[12]; // ��� ����� ������

        cout <<"Please, input name of file for Read:\n";
         cin >> namefile;
        Nullmas(a,b,c,f);
        read_of_file(a,b,c,f, namefile);
        cout <<"Please, input name of file for write:\n";
        cin >> out_ans;
    if(diagPrevalence(a,b,c) == 0) // �������� �� ������������ ������������
    {
        Prorace(a,b,c,f,x); // ���������� ������ ��������
        out_ansver( x, out_ans); // ����� ���������� � ����
    }
    else
        printf("Not diagonal prevaletion\n");
    printf("%d\n\n",diagPrevalence(a,b,c));
    printarr(x); // ����� ���������� �� �������
    return asd.exec();
}
