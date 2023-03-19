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
void rotate_vector(gsl_matrix **X)
{
	gsl_matrix *new_X;
	//std::cout << "stare " <<(*X)->size1 <<'x'<<(*X)->size2 <<'\n';
	if((*X)->size1 > (*X)->size2)
	{
		
		new_X = gsl_matrix_calloc((*X)->size2,(*X)->size1);
		for(short i = 0; i < (*X)->size1; i++)
			gsl_matrix_set(new_X,0,i,gsl_matrix_get(*X,i,0));

	}
	else if((*X)->size1 < (*X)->size2)
	{
		new_X = gsl_matrix_calloc((*X)->size2,(*X)->size1);
		for(short i = 0; i < (*X)->size2; i++)
			gsl_matrix_set(new_X,i,0,gsl_matrix_get(*X,0,i));
	}
	else
		return;
	gsl_matrix_free(*X);
	*X = new_X;
	//std::cout << "nowe "<<(*X)->size1 <<'x'<<(*X)->size2 <<'\n';

}
gsl_matrix * to_guwno(gsl_matrix * A, gsl_matrix *B)
{
	gsl_matrix *r_k = gsl_matrix_calloc(B->size1,1); //wektor reszt
	gsl_matrix *x_k = gsl_matrix_calloc(B->size1,1); //wektor rozwiązań
	gsl_matrix *temp;
	gsl_matrix *temp_2; // A*r_k
	gsl_matrix *temp_3; // {r_k^t}*{A}*{r_k}
	double alpha = 0.;
	int i = 0;
	do
	{
		double alpha;
		double vec_norm_sqr = 0.;

		for(short i = 0; i < B->size1; i++) //r_k
		{
			temp = multiply(A,x_k); // A*x_k
			gsl_matrix_set(r_k,i,0,gsl_matrix_get(B,i,0) - gsl_matrix_get(temp,i,0));
			gsl_matrix_free(temp);
		}
		//rk obliczony
		for(short i = 0; i < B->size1; i++)
		{
			temp_2 = multiply(A,r_k);
			rotate_vector(&r_k);
			temp_3 = multiply(r_k,temp_2);
			rotate_vector(&r_k);
			alpha = vector_norm(r_k)/gsl_matrix_get(temp_3,0,0);
			gsl_matrix_free(temp_2);
			gsl_matrix_free(temp_3);

		}
		for(short i = 0; i < B->size1; i++)	
		{
			gsl_matrix_set(x_k,i,0,gsl_matrix_get(x_k,i,0) + alpha*gsl_matrix_get(r_k,i,0));
		}
		i++;
	} while(sqrt(vector_norm(r_k)) > 0.000006 && i < 60000);
	gsl_matrix_free(r_k);

	return x_k;

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

	gsl_matrix * X = to_guwno(A,B);
	save_matrix("out.txt",X,"x:");
	gsl_matrix_free(A);
	gsl_matrix_free(B);
	return 0; 
}