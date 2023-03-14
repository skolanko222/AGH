#include <stdio.h>
#include <math.h>

#define N 8
#define H 8

//{"log", "pow", "sin", "cos"}

double fun0(double x){return log(x);}
double fun1(double x){return x*x;}
double fun2(double x){return sin(x);}
double fun3(double x){return cos(x);}

typedef double (*pointer)(double);

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


int main(void)
{
    char * nazwy[4] = {"log", "pow", "sin", "cos"};
    double data[N] = {0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0};
    double (*TAB_FUN[5])(double); //TABLICA WSK NA FUNKCJE
    double (*(*wsk_fun))(double);
    char **str;

    wsk_fun = TAB_FUN;
    str = nazwy;
    
    TAB_FUN[0] = fun0;
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL; //PRZYPISANIE

    do 
    {  
        printf_fun(*wsk_fun,*str,data); //WYPISANIE WARTOŚCI FUNKCJI 
        printf("\n");
    }while(str++,*++wsk_fun);

    double (*wsk_max)(double) = find_max(TAB_FUN, H);
    int licznik = 0;
    while(TAB_FUN[licznik] != wsk_max)
        licznik++;


    printf("%lf %d ", (*wsk_max)(H), licznik + 1);


    return 0;
}