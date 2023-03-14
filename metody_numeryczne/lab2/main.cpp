#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "helper.h"

#define SIZE 5

gsl_vector *gauss(const gsl_matrix * _A,const gsl_vector * _B);

int main()
{
	FILE * plik = fopen("a.txt","r");
	gsl_matrix *A = gsl_matrix_calloc(SIZE,SIZE);
	gsl_matrix_fscanf(plik,A);
	fclose(plik);

	plik = fopen("b.txt", "r");
	gsl_vector *B = gsl_vector_calloc(SIZE);
	gsl_vector_fscanf(plik,B);
	std::fstream plik2;
	plik2.open("out.txt");
	std::string _ = "Wektor wynikow";

	for(double q = 0; q <=3 ;q+=0.01)
	{
		gsl_matrix_set(A,0,0,2*q);
		gsl_vector *X = gauss(A,B);
		gsl_matrix *X_m = gsl_matrix_calloc(SIZE,1); //zamiana wektora na macierz 
		for(size_t i = 0; i < SIZE; i++)
			gsl_matrix_set(X_m,i,0,gsl_vector_get(X,i));
		gsl_matrix *C = multiply(A,X_m);
		double temp = 0.;
		double odchylenie = 0.;
		for(size_t i; i < SIZE; i++)
		{
			temp += pow(gsl_matrix_get(C,i,0) - gsl_vector_get(B,i),2);
		}
		odchylenie = sqrt(temp)/SIZE;

		std::string text = _ + " Q: " + std::to_string(q) + " odchylenie: " +std::to_string(odchylenie);
		save_vector(plik2,X,text.c_str());
			
		
		gsl_matrix_free(X_m);
		gsl_vector_free(X);
	}
	
	return 0;
}

gsl_vector *gauss(const gsl_matrix * _A,const gsl_vector * _B)
{
	gsl_matrix *A_copy = gsl_matrix_calloc(_A->size1,_A->size2);
	gsl_vector *B_copy = gsl_vector_calloc(_B->size);

	gsl_matrix_memcpy(A_copy,_A);
	gsl_vector_memcpy(B_copy,_B);

	for(size_t i = 0; i < SIZE; i++)
	{
		double div = gsl_matrix_get(A_copy,i,i);
		gsl_vector_set(B_copy,i,gsl_vector_get(B_copy,i)/div);
		for(size_t j = i; j < SIZE; j++) // dzielenie wiersza
		{
			double new_val_row = gsl_matrix_get(A_copy,i,j)/div;
			gsl_matrix_set(A_copy,i,j,new_val_row);

		}
		for(size_t j = i + 1; j < SIZE; j++) // odejmowanie  wiersza
		{
			double row_multip = gsl_matrix_get(A_copy,j,i) / gsl_matrix_get(A_copy,i,i);
			gsl_vector_set(B_copy,j,gsl_vector_get(B_copy,j)- (gsl_vector_get(B_copy,i) * row_multip));
			for(size_t k = i; k < SIZE; k++)
			{
				double new_val = gsl_matrix_get(A_copy,j,k) - (gsl_matrix_get(A_copy,i,k) * row_multip);
				gsl_matrix_set(A_copy,j,k,new_val);
			}
		}


	}
	for(int i = SIZE - 1; i >= 0 ; i--)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			double row_multip = gsl_matrix_get(A_copy,j,i) / gsl_matrix_get(A_copy,i,i);
			gsl_vector_set(B_copy,j,gsl_vector_get(B_copy,j) - (gsl_vector_get(B_copy,i) * row_multip));
			gsl_matrix_set(A_copy,j,i,gsl_matrix_get(A_copy,j,i) - (gsl_matrix_get(A_copy,i,i)*row_multip));
		}

	}
	gsl_matrix_free(A_copy);

	return B_copy;

}