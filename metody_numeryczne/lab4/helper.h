#pragma once
#include <iostream>
#include <fstream>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#define max(X,Y) ((X)>(Y)? (X):(Y))
#define min(X,Y) ((X)<(Y)? (X):(Y))
#define abs(X) ((X)>0? (X):-(X))

void save_matrix(const char * file_name, gsl_matrix *A, const char * str);
void save_vector(std::fstream &file, gsl_vector *A, const char * str);
double max_arr(const double * arr, const size_t size);
gsl_matrix * multiply(const gsl_matrix *A,const gsl_matrix *B);
gsl_matrix * multiplymm(const gsl_matrix *A,const gsl_matrix *B);
gsl_vector * multiplymw(const gsl_matrix *A,const gsl_vector *B);
double multiplyww(const gsl_vector *A,const gsl_vector *B);
void rotate_matrix(gsl_matrix **X);
double vector_norm(gsl_vector * X)
{
	double norm = 0.;
	for(int i = 0; i < X->size; i++)
		norm += gsl_vector_get(X,i)*gsl_vector_get(X,i);
	return sqrt(norm);

}
gsl_matrix * read_matrix(const char * file_name, const size_t size_x, const size_t size_y)
{
    FILE *t = fopen("a.txt", "r");
	gsl_matrix *A = gsl_matrix_calloc(size_x, size_y);
    gsl_matrix_fscanf(t, A);
    fclose(t);
    return A;
}

void save_matrix(const char * file_name, gsl_matrix *A, const char * str)
{
    std::ofstream file(file_name, std::ios_base::app);
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
    file.close();
}

double max_arr(const double * arr, const size_t size)
{
    double max = arr[0];
    for(int i = 0; i < size; i++)
    {
        arr[i] > max ? max = arr[i] : 0;
    }

    return max;
}

void save_vector(const char * file_name, gsl_vector *A, const char * str)
{
    std::ofstream file(file_name, std::ios_base::app);
    file << str << std::endl;
    for(int i = 0; i < A->size; i++)
    {
    
            file.width(10);
            file << gsl_vector_get(A, i);
    }
        file << "\n";
    file.close();
}
gsl_matrix * multiply(gsl_matrix *A,gsl_matrix *B)
{ 
    if(A->size2 != B->size1)
    {
        std::cout << "Zle wymiary: A=" << A->size1 << 'x'<< A->size2 << " B="<< B->size1 << 'x'<< B->size2  <<std::endl;
        return nullptr; 

    }
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
gsl_matrix * multiplymm(const gsl_matrix *A,const gsl_matrix *B)
{ 
    if(A->size2 != B->size1)
    {
        std::cout << "zle wymiary";
        return nullptr; 
    }
    gsl_matrix *C = gsl_matrix_calloc(A->size1, B->size2);
    for (int i = 0; i < A->size1; i++)
    {
        for (int j = 0; j < B->size2; j++)
        {
            double temp = gsl_matrix_get(C,i,j);
            for (int k=0; k < A->size2; k++)
            {
                temp += gsl_matrix_get(A,i,k) * gsl_matrix_get(B,k,j);
            }
            gsl_matrix_set(C,i,j, temp);
        }
    }
    return C;
}

gsl_vector * multiplymw(const gsl_matrix *A,const gsl_vector *B)
{ 
    if(A->size2 != B->size)
    {
        std::cout << "zle wymiary";
        return nullptr; 
    }
    gsl_vector *C = gsl_vector_calloc(B->size);
    for (int i = 0; i < A->size1; i++)
    {
        for (int j = 0; j < B->size; j++)
        {
            double temp = gsl_vector_get(C,i);
            for (int k=0; k < A->size2; k++)
            {
                temp += gsl_matrix_get(A,i,k) * gsl_vector_get(B,k);
            }
            gsl_vector_set(C, i, temp);
        }
    }
    return C;
}

double multiplyww(const gsl_vector *A,const gsl_vector *B)
{ 
    if(A->size != B->size)
    {
        std::cout << "zle wymiary";
        return 0; 
    }
    double C = 0;
    for (int i = 0; i < A->size; i++)
    {
        for (int j = 0; j < B->size; j++)
        {
            double temp = C;
            temp += gsl_vector_get(A,i) * gsl_vector_get(B,j);
            C+=temp;
        }
    }
    return C;
}

void rotate_matrix(gsl_matrix **X)
{
	gsl_matrix *new_X;
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

}
