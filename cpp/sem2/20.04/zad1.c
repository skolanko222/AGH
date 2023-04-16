#include <stdio.h>
#include <math.h>

#define N 8
#define H 0.05

double fun0(double x){return log(x);}
double fun1(double x){return x*x;}
double fun2(double x){return sin(x);}
double fun3(double x){return cos(x);}

typedef double (*pointer)(double);

int  fcmpr(const  void *a, const  void *b);
pointer find_max(double (*(*wsk_fun))(double), double x);
void printf_fun(double (f)(double), char *name, double *data);

void sort_arg(double (*wsk_fun)(double), double *data, int size)
{
    double arr[size];
    for(int i = 0; i < size; i++)
        arr[i] = wsk_fun(data[i]);
    qsort(arr,size,sizeof(arr[0]),fcmpr);
    //for(int i = 0; i < size; i++)
        

}


int main(void)
{
    char * nazwy[4] = {"log", "pow", "sin", "cos"};
    double data[N] = { 3.5, 1.0, 2.5, 2.0, 1.5, 3.0, 0.5, 4.0 };
    double (*TAB_FUN[5])(double); 
    
    double (*(*wsk_fun))(double);
    char **str;

    wsk_fun = TAB_FUN;
    str = nazwy;
    
    TAB_FUN[0] = fun0;
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL; 

    do 
    {  
        printf_fun(*wsk_fun,*str,data);
        printf("\n");
    }while(++str,*++wsk_fun);

    double (*wsk_max)(double) = find_max(TAB_FUN, H);
    int licznik = 0;

    while(TAB_FUN[licznik] != wsk_max)
        licznik++;


    printf("dla x= %.2f najwieksza wartosc wynosi %.5f dla funkcji %s\n", H, wsk_max(H), nazwy[licznik]);

    sort_arg(TAB_FUN[1], data, 8);

    return 0;
}

pointer find_max(double (*(*wsk_fun))(double), double x)
{
    double (*(*temp))(double) = wsk_fun;
    for(double (*(*p))(double) = wsk_fun + 1; p < wsk_fun + 4; p++)
    {
        if((*p)(x) > (*temp)(x))
            temp = p;

    }

    return *temp;
}
void printf_fun(double (f)(double), char *name, double *data)
{
    for(int i = 0; i < N; i++)
        printf("%s(%lf) = %.4lf\n", name, data[i], f(data[i]));
}
int  fcmpr(const  void *a, const  void *b)
{
    double  fa = *(const  double  *)a;
    double  fb = *(const  double  *)b;
    return (fa > fb) - (fa < fb);
}