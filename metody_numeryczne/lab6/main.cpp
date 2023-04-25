#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#define M 101

//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out
std::fstream plik;
double fun(double x,int nr)
{
	switch(nr)
	{
		case 0:
			return std::exp(-(x*x));
		case 1:
			if(x < 0.)
				return -1;
			else
				return 1;
		case 2:
			return std::cos(2*x);
	}
	return x;
}

gsl_vector *lagrange(gsl_vector *x, gsl_vector *y, gsl_vector *x_2, int n);
gsl_vector * czybyszew(double a, double b,double n);
int main()
{
	plik.open("out.txt");
	
	int n = 20; // ilosc wezlow
	int nr_f = 0; // nr funkcji
	
	
	//int m = 10;
	gsl_vector *x = gsl_vector_calloc(n);
	gsl_vector *y = gsl_vector_calloc(n);
	gsl_vector *x_2 = gsl_vector_calloc(M);
	gsl_vector *y_2;
	double x_val = -5.;
	for(int i = 0; i < n; i++)
	{
		std::cout << x_val << std::endl;
		gsl_vector_set(x,i,x_val);
		x_val += 10./(n-1.);
	}
	double temp = -5.;
	std::vector<double> arg,wyniki;
	for(int i = 0; i < M; i++)
	{
		gsl_vector_set(x_2, i, temp);
		arg.push_back(temp);
		temp += 0.1;
	}
	std::cout << "test funkcji exp: \n";
	for(int i = 0; i < n; i++ )
	{
		double war = fun(gsl_vector_get(x,i),nr_f);
		std::cout << war << std::endl;
		gsl_vector_set(y,i,war);
	}
	y_2 = lagrange(x,y,x_2,n);
	temp = -5.;
	plik << "zad1\n";
	for(int i = 0; i < M; i++ )
	{
		wyniki.push_back(gsl_vector_get(y_2,i) );
	}
	
	for(auto x: arg) {plik.width(0);plik << x << " ";}
	plik << "\n";
	for(auto x: wyniki) {plik.width(0);plik << x << " ";}
	plik << "\n";

	plik << "zad2\n";
	gsl_vector_free(x);
	x = czybyszew(-5.,5.,n);
	for(int i = 0; i < n; i++)plik,x_2,"wektor X_2");
	gsl_vector_free(y_2);
	y_2 = lagrange(x, y, x_2, n);
	wyniki.clear();
	plik << "\n\nczybyszew\n";
	for(int i = 0; i < M; i++)
	{
		wyniki.push_back(gsl_vector_get(y_2,i));
	}
	for(auto x: arg) {plik.width(0);plik << x << " ";}
	plik << "\n";
	for(auto x: wyniki) {plik.width(0);plik << x << " ";}
	plik << "\n";
	
	gsl_vector_free(x);
	gsl_vector_free(y);
	gsl_vector_free(x_2);
	gsl_vector_free(y_2);
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
		w = 0.5*((a-b)*cos(M_PI*(2*i +1)/(2*(n-1) + 2) ) + a + b);
		gsl_vector_set(temp,i,w);
	}
	return temp;
}