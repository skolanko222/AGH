#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "helper.h"

#define SIZE 100
#define M 2

//g++ lab2.cpp -lgsl -lgslcblas -lm && ./a.out
double vector_norm(gsl_matrix * X)
{
	double norm = 0.;
	for(short i = 0; i < X->size1; i++)
		norm += gsl_matrix_get(X,i,0)*gsl_matrix_get(X,i,0);
	return norm;

}
gsl_vector * to_guwno(gsl_matrix * A, gsl_matrix *B)
{
	gsl_matrix *r_k = gsl_matrix_calloc(B->size1,1);
	gsl_matrix *x_k = gsl_matrix_calloc(B->size1,1);
	double alpha = 0.;
	do
	{
		gsl_matrix *temp;

		for(short i = 0; i < B->size1; i++) //r_k
		{
			temp = multiply(A,x_k);
			gsl_matrix_set(r_k,i,0,gsl_matrix_get(B,i,0) - gsl_matrix_get(x_k,i,0));
		}


	} while(sqrt(vector_norm(r_k)) < 0.);


}

int main(void)
{
	gsl_matrix * A = gsl_matrix_calloc(SIZE,SIZE);
	for(short i = 0; i < SIZE; i++)
	{
		for(short j = 0; j < SIZE; j++)
		{
			if(fabs(i - j) <= 5.)
				gsl_matrix_set(A,i,j, double(1./(1.+ fabs(i - j))) );
			else
				gsl_matrix_set(A,i,j, 0.);
		}

	}
	save_matrix("out.txt",A,"Test A");

	gsl_matrix * B = gsl_matrix_calloc(SIZE,1);
	for(short i = 0; i < SIZE; i++)
		gsl_matrix_set(B,i,0,i);


	to_guwno(A,B);
	gsl_matrix_free(A);
	return 0; 
}