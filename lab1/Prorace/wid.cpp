
#include "wid.h"

using namespace std;

void read_of_file(double a[N],double b[N],double c[N],double f[N], char* _namefile)//считать из файла
{
    ifstream in;
    in.open(_namefile);
    for(int i=0;i<N;i++)
    {
        if(i==N-1)
        {
            in >> c[i];
            in >> f[i];
        }
        else
        {
            in >> c[i];
            in >> b[i];
            in >> f[i];
            in >> a[i+1];
        }
    }
    in.close();
}



void printarr(double x[N])
{
    for(int i=0;i<N;i++)
    {
        printf("x%d = %f\n", i, x[i]);
    }
}

void Prorace(double *a,double *b,double *c,double *f, double *x)
{
  for(int i=1;i<N;i++)
  {
        double m =a[i]/c[i-1];
        c[i]=c[i]-m*b[i-1];
        f[i]=f[i]-m*f[i-1];
  }
  x[N-1]=f[N-1]/c[N-1];
    for(int i=N-2;i>=0;i--)
    {
        x[i]=(f[i]-b[i]*x[i+1])/c[i];
    }
}
void Nullmas(double a[N],double b[N],double c[N],double f[N])
{
    for(int i=0;i<N;i++)
    {
        a[i]=0;
        b[i]=0;
        c[i]=0;
        f[i]=0;
    }
}
 void out_ansver(double x[N], char *out_ans)
 {
     ofstream out;
     out.open(out_ans);
     out << "ansver\n";
     for( int i=0;i<N;i++)
     {
         out<<"x"<<i+1<<"="<<x[i]<<"\n";
     }
     out.close();
 }

 int diagPrevalence(double a[N],double b[N],double c[N])
 {

    for(int i=0;i<N;i++)
    {
        if (abs(c[i]) < abs(b[i])+abs(a[i]))
            return 1;
    }
    return 0;
 }
