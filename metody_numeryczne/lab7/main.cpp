#include <iostream>
#include <fstream>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "helper.h"
#include <cmath>
#include <ctime>

#define SIZE 5 // ilość węzłów
#define FUN 0 // nr funkcji
#define M 101 // ilość interpolowanych wartości


std::fstream plik;


//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out
double fun(double x,int nr);

int main(void)
{
	plik.open("out.txt");
	int signum = 1;
	gsl_matrix * A = gsl_matrix_calloc(SIZE,SIZE);
	gsl_vector * x = gsl_vector_calloc(SIZE);
	gsl_vector * y = gsl_vector_calloc(SIZE);

	gsl_vector * d = gsl_vector_calloc(SIZE);
	gsl_vector * m = gsl_vector_calloc(SIZE);
	gsl_permutation *p = gsl_permutation_calloc(SIZE);

	double x_val = -5.;
	for(int i = 0; i < SIZE; i++)
	{
		gsl_vector_set(x,i,x_val);
		gsl_vector_set(y,i,fun(gsl_vector_get(x,i),FUN));
		//std::cout << gsl_vector_get(x,i) << " " << gsl_vector_get(y,i)<< std::endl;
		x_val += 10./(SIZE-1.);
	}
	gsl_matrix_set(A,0,0,1.);
	gsl_matrix_set(A,SIZE-1,SIZE-1,1.);
	gsl_vector_set(d,0,0);
	gsl_vector_set(d,SIZE-1,0);
	
	// uzupelnienie macierzy A
	for(int i = 1; i < SIZE - 1; i++)
	{
		double mi;
		double lambda;
		double d_val;
		double h_i = gsl_vector_get(x,i) - gsl_vector_get(x,i-1);
		double h_i1 = gsl_vector_get(x,i +1) - gsl_vector_get(x,i);
		lambda = h_i1/(h_i + h_i1);
		mi = 1. - lambda;
		d_val = (6./(h_i + h_i1))
						*((gsl_vector_get(y,i + 1) - gsl_vector_get(y,i))/h_i1
						- (gsl_vector_get(y,i)-gsl_vector_get(y,i -1))/h_i);

		gsl_matrix_set(A,i , i -1, mi);
		gsl_matrix_set(A,i, i, 2.);
		gsl_matrix_set(A,i, i+1, lambda);
		gsl_vector_set(d,i,d_val);	
	}
	//save_matrix(plik,A,"macierz A:");

	gsl_linalg_LU_decomp(A, p, &signum);
	gsl_linalg_LU_solve(A,p,d,m);
	//save_vector(plik,m,"wektor M");

	//miedzywezlowy
	gsl_vector * x_2 = gsl_vector_calloc(M);
	gsl_vector * y_2 = gsl_vector_calloc(M);

	x_val = -5.;
	for(int i = 0; i < M; i++)
	{
		gsl_vector_set(x_2,i,x_val);
		x_val += 0.1; //TODO: zależne od M
	}
	//save_vector(plik,x_2,"wektor X_2");
		  
	//interpolacja
	int i = 1;
	int temp = double(M)/double(SIZE - 1);
	//std::cout << temp;

	gsl_vector * s_1 = gsl_vector_calloc(M);

	for(int j = 0; j < M; j++)
	{
		double h_i = gsl_vector_get(x,i) - gsl_vector_get(x,i-1);
		double a;
		double b;
		double m_i1 = gsl_vector_get(m,i - 1);
		double m_i = gsl_vector_get(m,i);
		double y_i1 = gsl_vector_get(y,i - 1);// wartosc wezla
		double y_i = gsl_vector_get(y,i);
		double x_i1 = gsl_vector_get(x,i - 1);		
		double x_i = gsl_vector_get(x,i); // wezeł
		double x = gsl_vector_get(x_2,j);
		double s;
		a = (y_i - y_i1)/h_i - h_i/6.*(m_i - m_i1);
		b = y_i1 - m_i1*(h_i*h_i)/6.;
		s = m_i1*std::pow(x_i - x,3)/(6*h_i) + m_i*std::pow(x - x_i1,3)/(6*h_i) + a*(x - x_i1) + b;
		gsl_vector_set(s_1,j,s);
		std::cout << j << " " << a << " " << b << " " << s << std::endl;
		if(j!= 0 && j%temp == 0)
			i++; // licznik przedziału
	}
	save_vector(plik,s_1,"Interpolacja:");
	save_vector(plik,x_2,"");
	plik.close();
	return 0;
}

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
