#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "/usr/include/gsl/gsl_deriv.h"

#define M 101

//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out

double my_f1(double x);
double my_f2(double x);
double my_f3(double x);
gsl_vector *second(gsl_vector *x, gsl_vector *y, double alpha, double beta, int N, std::fstream &plik);
gsl_vector *interpol(gsl_vector *x, gsl_vector *y, gsl_vector *m, gsl_vector *x2, int N);
gsl_vector *second_roznicowy(double (*fun)(double), gsl_vector *x, int N);

int main(void)
{
    std::fstream plik;
	plik.open("out.txt");

    double (*(funkcje[]))(double) = {my_f1, my_f2, my_f3};

    for(int z=0; z<3; z++)
    {
        plik.width(30);
        plik << "\n\nWYKRES " << z << "\n\n\n";

        double krok[3] = {2.5, 1.0, 0.5};
        int krok_w = 0;

        for(int N=5; N<21; N+=5)
        {
            if(N==15)
                continue;
            
            plik << "*********************************DLA " << N << " WEZLOW*********************************\n\n";

            gsl_vector *x = gsl_vector_calloc(N);
            gsl_vector *y = gsl_vector_calloc(N);
            gsl_vector *x2 = gsl_vector_calloc(M);
            gsl_vector *y2 = gsl_vector_calloc(M);
            gsl_vector *m = gsl_vector_calloc(N);
            gsl_vector *sr = gsl_vector_calloc(N);

            double b=-5.0;
            for(int i=0; i<N; i++)
            {
                gsl_vector_set(x,i,b);
                b+=krok[krok_w];
                if(!(N%2) && b==0)
                    b+=krok[krok_w];      
            }

            for(int i=0; i<N; i++)
            {
                gsl_vector_set(y, i, funkcje[z](gsl_vector_get(x,i)));
            }

            m = second(x, y, 0, 0, N, plik);

            double a=-5.0;
            for(int  i=0; i<M; i+=1)
            {
                gsl_vector_set(x2, i, a);
                a+=0.1;
            }

            sr = second_roznicowy(funkcje[z], x, N);
            plik << "\tDruga pochodna z ilorazu roznicowego:\n\t";
            for(int i=0; i<N; i++)
            {
                plik << gsl_vector_get(sr,i) << "\t";
            }

            y2 = interpol(x, y, m, x2, N);

            for(int  i=0; i<M; i+=1)
            {
                plik.width(15);
                plik << gsl_vector_get(x2,i) << "\t";
                plik.width(15);
                plik << gsl_vector_get(y2,i);
                plik << std::endl;
            }

            gsl_vector_free(x);
            gsl_vector_free(y);
            gsl_vector_free(x2);
            gsl_vector_free(y2);
            gsl_vector_free(m);
            gsl_vector_free(sr);
            krok_w++;
        }

    }

    plik.close();
    return 0;
}

double my_f1(double x)
{
    return exp(0-(x*x));
}

double my_f2(double x)
{
    if(x<0)
        return -1;
    else
        return 1;
}

double my_f3(double x)
{
    return cos(2*x);
}

gsl_vector *second(gsl_vector *x, gsl_vector *y, double alpha, double beta, int N, std::fstream &plik)
{
    gsl_matrix *A = gsl_matrix_calloc(N,N);
    gsl_vector *m = gsl_vector_calloc(N);
    gsl_vector *d = gsl_vector_calloc(N);

    gsl_vector *h = gsl_vector_calloc(N);
    for(int i=1; i<N; i++)
    {
        gsl_vector_set(h, i, gsl_vector_get(x,i) - gsl_vector_get(x,i-1));
    }

    gsl_vector_set(d,0,alpha);
    plik << "\n\tDruga pochodna wzorami:\n\t";
    plik <<  "0\t";
    for(int i=1; i<N-1; i++)
    {
        double temp = 6/(gsl_vector_get(h,i) + gsl_vector_get(h,i+1)) * ((gsl_vector_get(y,i+1) - gsl_vector_get(y,i))/(gsl_vector_get(h,i+1)) - (gsl_vector_get(y,i) - gsl_vector_get(y,i-1))/(gsl_vector_get(h,i)));
        plik << temp << "\t";
        gsl_vector_set(d,i,temp);
    }
    plik <<  "0\n";
    gsl_vector_set(d,N-1,beta);

    gsl_vector *l = gsl_vector_calloc(N);
    for(int i=1; i<N-1; i++)
    {
        gsl_vector_set(l,i,gsl_vector_get(h,i+1) / (gsl_vector_get(h,i) + gsl_vector_get(h,i+1)));
    }

    gsl_vector *u = gsl_vector_calloc(N);
    for(int i=1; i<N-1; i++)
    {
        gsl_vector_set(u, i, 1 - gsl_vector_get(l,i));
    }

    for(int i=1; i<N-1; i++)
    {
        gsl_matrix_set(A,i,i,2.0);
        gsl_matrix_set(A,i,i-1,gsl_vector_get(u,i));
        gsl_matrix_set(A,i,i+1,gsl_vector_get(l,i));
    }
    gsl_matrix_set(A,0,0,1.0);
    gsl_matrix_set(A,N-1,N-1,1.0);

    gsl_permutation *p = gsl_permutation_calloc(N);
    int signum;
    gsl_linalg_LU_decomp(A, p, &signum);
    gsl_linalg_LU_solve(A, p, d, m);

    gsl_matrix_free(A);
    gsl_vector_free(d);
    gsl_vector_free(h);
    gsl_vector_free(l);
    gsl_vector_free(u);
    gsl_permutation_free(p);

    return m;
}

gsl_vector *interpol(gsl_vector *x, gsl_vector *y, gsl_vector *m, gsl_vector *x2, int N)
{
    gsl_vector *a = gsl_vector_calloc(N);
    gsl_vector *b = gsl_vector_calloc(N);
    gsl_vector *s = gsl_vector_calloc(M);

    
    gsl_vector *h = gsl_vector_calloc(N);
    for(int i=1; i<N; i++)
    {
        gsl_vector_set(h, i, gsl_vector_get(x,i) - gsl_vector_get(x,i-1));
    }

    for(int i=1; i<N; i++)
    {
        double temp = (gsl_vector_get(y,i) - gsl_vector_get(y,i-1)) / gsl_vector_get(h,i)  -  gsl_vector_get(h,i)/6 * (gsl_vector_get(m,i) - gsl_vector_get(m,i-1));
        gsl_vector_set(a,i,temp);
    }

    for(int i=1; i<N; i++)
    {
        double temp = gsl_vector_get(y,i-1) - gsl_vector_get(m,i-1) * (gsl_vector_get(h,i)*gsl_vector_get(h,i))/6;
        gsl_vector_set(b,i,temp);
    }

    int i=1;
    double check1[3] = {-2.6 , -0.1, 2.5};
    int number1[3] = {2,3,4};
    double check2[8] = {-4.1, -3.1, -2.1, -1.1, 1.0, 2.0, 3.0, 4.0}; 
    int number2[8] = {2,3,4,5,6,7,8,9};
    double check3[18] = {-4.6, -4.1, -3.6, -3.1, -2.6, -2.1, -1.6, -1.1, -0.6, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5};
    int number3[18] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

    for(int j=0; j<M; j++)
    {
        for(int k=0; k<N-2; k++)
        {
            if(N==5)
                if(gsl_vector_get(x2,j) >= check1[k])
                    i=number1[k];
            if(N==10)
                if(gsl_vector_get(x2,j) >= check2[k])
                    i=number2[k];
            if(N==20)
                if(gsl_vector_get(x2,j) >= check3[k])
                    i=number3[k];         
        }

        double temp1 = gsl_vector_get(m,i-1) * pow(gsl_vector_get(x,i) - gsl_vector_get(x2,j), 3) / (6*gsl_vector_get(h,i));
        double temp2 = gsl_vector_get(m,i) * pow(gsl_vector_get(x2,j) - gsl_vector_get(x,i-1), 3) / (6*gsl_vector_get(h,i));
        double temp3 = gsl_vector_get(a,i) * (gsl_vector_get(x2,j) - gsl_vector_get(x,i-1)) + gsl_vector_get(b,i);
        gsl_vector_set(s,j,temp1 + temp2 + temp3);
    }

    gsl_vector_free(a);
    gsl_vector_free(b);
    gsl_vector_free(h);

    return s;
}

gsl_vector *second_roznicowy(double (*fun)(double), gsl_vector *x, int N)
{
    gsl_vector *tmp = gsl_vector_calloc(N);
    double h=0.1;
    for(int i=0; i<N; i++)
    {
        double temp = (fun(gsl_vector_get(x,i) - h) - 2*fun(gsl_vector_get(x,i)) + fun(gsl_vector_get(x,i) + h)) / (h*h);
        gsl_vector_set(tmp, i, temp);
    }
    return tmp;
}