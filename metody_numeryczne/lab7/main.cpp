#include <iostream>
#include <fstream>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "helper.h"
#include <cstdlib>
#include <ctime>

#define SIZE 5
#define FUN 0
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
		std::cout << gsl_vector_get(x,i) << " " << gsl_vector_get(y,i)<< std::endl;
		x_val += 10./(SIZE-1.);
	}

	for(int i = 1; i < SIZE - 1; i++)
	{
		double mi;
		double lambda;
		double h_i = gsl_vector_get();
		double h_i1;

		gsl_matrix_set(A,i - 1, i, mi);
		gsl_matrix_set(A,i, i, 2.);
		gsl_matrix_set(A,i + 1, i, lambda);
	}


	gsl_linalg_LU_decomp(A, p, &signum);
	gsl_linalg_LU_solve(A,p,d,m);

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
