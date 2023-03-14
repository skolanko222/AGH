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
    
            file.width(10);
            file << gsl_vector_get(A, i);
    }
        file << "\n";
}
gsl_matrix * multiply(const gsl_matrix *A,const gsl_matrix *B)
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