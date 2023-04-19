#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#define M 101

//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out
std::fstream plik;
double fun(double x)
{
	return std::exp(-(x*x));
}

gsl_vector *lagrange(gsl_vector *x, gsl_vector *y, gsl_vector *x_2, int n);
gsl_vector * czybyszew(double a, double b,double n);
int main()
{
	plik.open("out.txt");
	int n = 5;
	//int m = 10;
	gsl_vector *x = gsl_vector_calloc(n);
	gsl_vector *y = gsl_vector_calloc(n);
	gsl_vector *x_2 = gsl_vector_calloc(M);
	gsl_vector *y_2;

	//for(int i = -5; i < 5; i)
	gsl_vector_set(x,0,-5.);
	gsl_vector_set(x,1,-2.5);
	gsl_vector_set(x,2, 0.);
	gsl_vector_set(x,3, 2.5);
	gsl_vector_set(x,4, 5.);
	double temp = -5.;
	for(int i = 0; i < M; i++)
	{
		gsl_vector_set(x_2, i, temp);
		temp += 0.1;
	}
	std::cout << "test funkcji exp: \n";
	for(int i = 0; i < n; i++ )
	{
		double war = fun(gsl_vector_get(x,i));
		std::cout << war << std::endl;
		gsl_vector_set(y,i,war);
	}
	y_2 = lagrange(x,y,x_2,n);
	temp = -5.;
	plik << "zad1\n";
	for(int i = 0; i < M; i++)
	{
		plik << temp << " " <<  gsl_vector_get(y_2,i) << "\n";
		temp += 0.1;
	}
	plik << "zad2\n";
	gsl_vector *x_3 = czybyszew(-5.,5.,5);
	for(int i = 0; i < n; i++)
	{
		plik << i << " " <<  gsl_vector_get(x_3,i) << "\n";
	}
	

	plik.close();
	return 0;
}

gsl_vector *lagrange(gsl_vector *x, gsl_vector *y, gsl_vector *x_2, int n)
{
	gsl_vector *temp = gsl_vector_calloc(M);
	for(int i = 0; i < M; i++)
	{
		double w_n = 0;
		for(int j = 0; j < n; j++)
		{
			double y_war = gsl_vector_get(y,j);
			double l = 1;
			double m = 1;
			for(int k = 0; k < n; k++)
			{
				if(j != k)
				{
					l *= (gsl_vector_get(x_2,i) - gsl_vector_get(x,k));
					m *= (gsl_vector_get(x,j) - gsl_vector_get(x,k));
				}

			}
			w_n += y_war*(l/m);
			
		}
		//std::cout << w_n << "\n";
		gsl_vector_set(temp,i,w_n);
	}
	return temp;
}

gsl_vector * czybyszew(double a, double b, double n)
{
	gsl_vector * temp = gsl_vector_calloc(n);
	for(int i=0; i<n; i++)
	{
		double w;
		w = 0.5*((a-b)*cos(M_PI*((2*i +1)/(2*(n-1)))) + a + b);
		gsl_vector_set(temp,i,w);
	}
	return temp;
}