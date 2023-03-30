#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "helper.h"

#define SIZE 99

//g++ lab3.cpp -lgsl -lgslcblas -lm && ./a.out
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
gsl_matrix * fun(gsl_matrix * A, gsl_matrix *B)
{
	gsl_matrix *r_k = gsl_matrix_calloc(B->size1,1); //wektor reszt
	gsl_matrix *x_k = gsl_matrix_calloc(B->size1,1); //wektor rozwiązań
	for(int i=0; i<B->size1; i++)
    {
        gsl_matrix_set(x_k,i,0,0);
    }
	std::fstream plik1, plik2;
	plik1.open("r_k.txt");
	plik2.open("t_k.txt");
	gsl_matrix *temp;
	gsl_matrix *temp_2; // A*r_k
	gsl_matrix *temp_3; // {r_k^t}*{A}*{r_k}
	double alpha = 0.f;
	float norm = 0.f;
	int i = 0;
	do
	{

		for(short i = 0; i < B->size1; i++) //r_k
		{
			temp = multiply(A,x_k); // A*x_k
			gsl_matrix_set(r_k,i,0,gsl_matrix_get(B,i,0) - gsl_matrix_get(temp,i,0));
			gsl_matrix_free(temp);
		}
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
		norm = sqrt(vector_norm(r_k));
		plik1 << std::log10(norm) << ',';
		norm = sqrt(vector_norm(x_k));
		plik2 << norm << ',';
	} while(sqrt(vector_norm(r_k)) < 0.000001);
	gsl_matrix_free(r_k);
	plik1.close();
	plik2.close();

	return x_k;

}
float lambda(float x)
{
	if(x>=0 && x < 40)
		return 0.3f;
	else if(x>= 40 && x < 70)
		return 0.2f;
	else
		return 0.1f;

}


int main(void)
{
	gsl_matrix * A = gsl_matrix_calloc(SIZE,SIZE);
	int x = 0;
	for(short i = 0; i < SIZE; i++)
	{
		x = (i + 1)*(100/(SIZE+1));
		gsl_matrix_set(A,i,i,- lambda(x - 0.5) - lambda(x + 0.5));
		if(i != SIZE-1)
		{
			gsl_matrix_set(A,i + 1,i,lambda(x + 0.5));
			gsl_matrix_set(A,i, i + 1,lambda(x + 0.5));
		}
	}
	save_matrix("out.txt",A,"A:");
	gsl_matrix * B = gsl_matrix_calloc(SIZE,1);
	gsl_matrix_set(B,0,0,-lambda( 1*(100/(SIZE+1)) - 0.5)*1000 );
	gsl_matrix_set(B,SIZE-1,0,-lambda(SIZE*(100/(SIZE+1))- 0.5)*100 );


	gsl_matrix * X = fun(A,B);
	save_matrix("out.txt",X,"wektor wynikow x:");
	gsl_matrix_free(A);
	gsl_matrix_free(B);
	return 0; 
}