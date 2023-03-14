#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "helper.h"

#define SIZE 4
#define Q 1

//g++ lab2.cpp -lgsl -lgslcblas -lm && ./a.out

int main(void)
{
	
	FILE *t = fopen("a.txt", "r");
	gsl_matrix *A = gsl_matrix_calloc(SIZE, SIZE);
	gsl_matrix *A_copy = gsl_matrix_calloc(SIZE, SIZE);
	gsl_matrix_fscanf(t, A);
	gsl_matrix_memcpy(A_copy,A);
	gsl_matrix_set(A,0,0,2*Q);
	fclose(t);

	t = fopen("b.txt", "r");
	gsl_vector *B = gsl_vector_calloc(SIZE);
	gsl_vector *B_copy = gsl_vector_calloc(SIZE);
	gsl_vector_fscanf(t, B);
	gsl_vector_memcpy(B_copy, B);
	fclose(t);
	std::fstream plik;
	plik.open("out.txt");
	
	for(size_t i = 0; i < SIZE; i++)
	{
		double div = gsl_matrix_get(A,i,i);
		gsl_vector_set(B,i,gsl_vector_get(B,i)/div);
		for(size_t j = i; j < SIZE; j++) // dzielenie wiersza
		{
			double new_val_row = gsl_matrix_get(A,i,j)/div;
			gsl_matrix_set(A,i,j,new_val_row);

		}
		for(size_t j = i + 1; j < SIZE; j++) // odejmowanie  wiersza
		{
			double row_multip = gsl_matrix_get(A,j,i) / gsl_matrix_get(A,i,i);
			gsl_vector_set(B,j,gsl_vector_get(B,j)- (gsl_vector_get(B,i) * row_multip));
			for(size_t k = i; k < SIZE; k++)
			{
				double new_val = gsl_matrix_get(A,j,k) - (gsl_matrix_get(A,i,k) * row_multip);
				gsl_matrix_set(A,j,k,new_val);
			}
		}
	}

	for(int i = SIZE - 1; i >= 0 ; i--)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			double row_multip = gsl_matrix_get(A,j,i) / gsl_matrix_get(A,i,i);
			gsl_vector_set(B,j,gsl_vector_get(B,j) - (gsl_vector_get(B,i) * row_multip));
			gsl_matrix_set(A,j,i,gsl_matrix_get(A,j,i) - (gsl_matrix_get(A,i,i)*row_multip));
		}

	}
	save_matrix(plik,A,"test A");
	gsl_matrix *B_m = gsl_matrix_calloc(SIZE, 1);
	for(size_t i = 0; i < SIZE; i++)
	 	gsl_matrix_set(B_m,i,0,gsl_vector_get(B,i));
	save_matrix(plik,B_m,"test B");
	gsl_matrix *C = gsl_matrix_calloc(SIZE, SIZE);
	C = multiply(A_copy,B_m);
	save_matrix(plik,C,"test C");
	double odchylenie = 0.;
	for(size_t i = 0; i < SIZE; i++)
	{
		double temp = gsl_matrix_get(C,i,0) - gsl_vector_get(B_copy,i);
		odchylenie += temp*temp;
	}
	odchylenie = sqrt(odchylenie)/5.;
	std::cout << odchylenie;

	gsl_matrix_free(A);
	gsl_vector_free(B);
	gsl_matrix_free(C);
	gsl_matrix_free(A_copy);
	gsl_matrix_free(B_m);
	plik.close();



	return 0; 
}