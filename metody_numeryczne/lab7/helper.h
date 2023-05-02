#pragma once
#include <iostream>
#include <fstream>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#define max(X,Y) ((X)>(Y)? (X):(Y))
#define min(X,Y) ((X)<(Y)? (X):(Y))
#define abs(X) ((X)>0? (X):-(X))

void save_matrix(std::fstream &file, gsl_matrix *A, const char * str);
double max_arr(const double * arr, const size_t size);
gsl_vector *gauss(const gsl_matrix * _A,const gsl_vector * _B);

void save_matrix(std::fstream &file, gsl_matrix *A, const char * str)
{
    file << str << std::endl;
    for(int i = 0; i < A->size1; i++)
    {
        for(int j = 0; j < A->size2; j++)
        {
            file.width(10);
            file << gsl_matrix_get(A, i, j) << "\t";
        }
        file << "\n";
    }
    file << "\n";
}

double max_arr(const double * arr, const size_t size)
{
    double max = arr[0];
    for(int i = 0; i < size; i++){
        arr[i] > max ? max = arr[i] : 0;
    }
    return max;
}

void save_vector(std::fstream &file, gsl_vector *A, const char * str)
{
    file << str << std::endl;
    for(int i = 0; i < A->size; i++)
    {
    
            //file.width(15);
            file << gsl_vector_get(A, i) << ", ";
    }
        file << "\n";
}
gsl_matrix * multiply(const gsl_matrix *A, const gsl_matrix *B)
{ 
    gsl_matrix *C = gsl_matrix_calloc(A->size1, B->size2);
    for (int i = 0; i < A->size1; i++)
    {
        for (int j = 0; j < B->size2; j++)
        {
            double temp = gsl_matrix_get(C,i,j);
            for (int k=0; k < A->size2; k++)
            {
                //std::cout << i << ' ' << j << ' ' << k << '\n';
                temp += gsl_matrix_get(A,i,k) * gsl_matrix_get(B,k,j);
            }
            gsl_matrix_set(C,i,j, temp);
        }
    }
    return C;

}

gsl_vector *gauss(const gsl_matrix * _A,const gsl_vector * _B)
{
	gsl_matrix *A_copy = gsl_matrix_calloc(_A->size1,_A->size2);
	gsl_vector *B_copy = gsl_vector_calloc(_B->size);

	gsl_matrix_memcpy(A_copy,_A);
	gsl_vector_memcpy(B_copy,_B);

	for(size_t i = 0; i < _A->size1; i++)
	{
		double div = gsl_matrix_get(A_copy,i,i);
		gsl_vector_set(B_copy,i,gsl_vector_get(B_copy,i)/div);
		for(size_t j = i; j < _A->size1; j++) // dzielenie wiersza
		{
			double new_val_row = gsl_matrix_get(A_copy,i,j)/div;
			gsl_matrix_set(A_copy,i,j,new_val_row);

		}
		for(size_t j = i + 1; j < _A->size1; j++) // odejmowanie  wiersza
		{
			double row_multip = gsl_matrix_get(A_copy,j,i) / gsl_matrix_get(A_copy,i,i);
			gsl_vector_set(B_copy,j,gsl_vector_get(B_copy,j)- (gsl_vector_get(B_copy,i) * row_multip));
			for(size_t k = i; k < _A->size1; k++)
			{
				double new_val = gsl_matrix_get(A_copy,j,k) - (gsl_matrix_get(A_copy,i,k) * row_multip);
				gsl_matrix_set(A_copy,j,k,new_val);
			}
		}


	}
	for(int i = _A->size1 - 1; i >= 0 ; i--)
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