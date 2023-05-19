#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "helper.h"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
//g++ lab9.cpp -lgsl -lgslcblas -lm && ./a.out

std::fstream plik;

#define N 101
#define M 4

double funny(double x);
gsl_vector * fit(gsl_vector * x, gsl_vector * y);

int main(void)
{
	plik.open("out.txt");
    srand(time(NULL));
	gsl_vector *x = gsl_vector_calloc(N);
	gsl_vector *y = gsl_vector_calloc(N);

	double x_a = -5.;
	double r = 10.;

	for(int i = 0; i < N; i++)
	{
		gsl_vector_set(x,i,x_a);
		gsl_vector_set(y,i,funny(gsl_vector_get(x,i)));
		//std::cout << x_a << " " << funny(gsl_vector_get(x,i)) << std::endl;
		x_a += r/(N-1.);
	}
	save_vector(plik,x,"real");
	save_vector(plik,y,"");
	gsl_vector *b = gsl_vector_calloc(N);
    b = fit(x,y);

	save_vector(plik,b,"Współczynniki: ");

    plik.close();
    return 0;
}

double funny(double x)
{
    double random = ((double) rand() / (RAND_MAX));
    return -0.25*pow(x,3)-0.5*pow(x,2)+5*x+5+5*(random-0.5);
}

gsl_vector * fit(gsl_vector * x, gsl_vector * y)
{
	gsl_matrix *X = gsl_matrix_calloc(N,M);
	gsl_matrix *X_t = gsl_matrix_calloc(M,N);
	gsl_matrix *D = gsl_matrix_calloc(M,M);
	gsl_vector *r = gsl_vector_calloc(M);
	gsl_vector *b = gsl_vector_calloc(M);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			gsl_matrix_set(X,i,j,pow(gsl_vector_get(x,i), j));
            gsl_matrix_set(X_t,j,i,pow(gsl_vector_get(x,i), j));
		}

	}
	// save_matrix("test.txt",X,"X: ");
	// save_matrix("test.txt",X_t,"X_t: ");
	D = multiplymm(X_t,X);

	//save_matrix("test.txt",D,"D: ");

	r = multiplymw(X_t, y);
	//save_vector("test.txt", r, "r: ");
	
	gsl_permutation *p = gsl_permutation_calloc(M);
    int signum;
    gsl_linalg_LU_decomp(D, p, &signum);
    gsl_linalg_LU_solve(D, p, r, b);

	gsl_vector *y_t;
	y_t = multiplymw(X,b);
	std::cout<< y_t->size << " " << x->size << std::endl;
	save_vector(plik,x,"Wartości transponowane: ");
	save_vector(plik,y_t,"");

	return b;
}