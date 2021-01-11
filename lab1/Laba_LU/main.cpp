#include "wid.h"
int main(/*int argc, char *argv[]*/) {
//    QCoreApplication a(argc, argv);
    /// ���������� ���
    char name1[30];// �������� ����� ��� ����������
    char name2[30];// �������� ����� ��� ������
    char ok;// ������������ ��� ���������� ���������� ���������
    double x[N][N];// ������� �������
    double y[N];// ������ ������ ������ �������
    double l[N][N];// ������� L
    double u[N][N];// ������� U
    double p[N][N];// ������� ������������
    double inv[N][N];// �������� �������
    double temp[N][N];// ��������� ��������� ������ ��� �������� ����������
    double temp2[N];// ��������� ���������� ������ ��� �������� ����������
    double I[N];// ������� ��������� �������
    int index; // ���������� ������������
    int okey;//���  ������������ ���������(���������� ����������)

    do {
    cout << "Please, enter the name of file for input matrix:\n";
        cin >> name1;
        cout << "Please, enter the name of file for output answer:\n";
        cin >> name2;
        index = 0.0;
        InputMas(x, y, name1);
        PLU(x, l, u, p, y, index);// ��������� LU ����������

        Determinant(u, index);// ��������� ������������

        MultiMas(l, u, temp);// ���������,��� ������������ L �� U ����
        //�������� ������� � ��������� �� ������������ �����

        PLUinverse(u, y);//������� ����� �� ������� U

        MultiMas(x, y, temp2);//���������,��� ������������ ��������
        //������� �� ������ ������ ����� ������ �����

        for(int i=0;i<N;i++)//����� �������� �������
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

        MultiMas(x, inv, temp);// ��������� �������� ������� ��
                              // ��������(������ ���������� ���������)

        OutputAnswer(l, u, p, inv, y, name2);//����� ����������� � ����
      // ������� ���������� � �������
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
