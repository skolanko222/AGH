#include <iostream>
#include <fstream>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "helper.h"
#include <cstdlib>
#include <ctime>

//g++ lab2.cpp -lgsl -lgslcblas -lm && ./a.out

#define SIZE 4

int main()
{   
    gsl_matrix *A = gsl_matrix_calloc(SIZE, SIZE);
    gsl_matrix *A_copy = gsl_matrix_calloc(SIZE, SIZE);
    int value = 10;
    int signum = 1;
    std::fstream file;
    file.open("output.txt", std::fstream::out);
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            double a = 1./(i+j+2.);
            gsl_matrix_set(A, i, j, a);
        }
    }
    save_matrix(file, A, "zad1\nMacierz A");
    gsl_matrix_memcpy(A_copy,A);
    gsl_permutation *p = gsl_permutation_calloc(SIZE);

    gsl_linalg_LU_decomp(A, p, &signum);
    
    double det = 1;
    file << "\nzad2\n";

    for(int i = 0; i < SIZE; i++)
    {
        file << gsl_matrix_get(A, i, i) << ", ";
        det *= gsl_matrix_get(A, i, i);

    }

    file << "\n" << "wyznacznik: " << det << '\n';
    
    //zad3
    file << "\nzad3\n";

    gsl_vector *vec_b[SIZE];
    gsl_vector *vec_x[SIZE];
    gsl_matrix *B = gsl_matrix_calloc(SIZE, SIZE);
    
    for(int i = 0; i < SIZE; i++)
    {
        vec_b[i] = gsl_vector_calloc(SIZE);
        vec_x[i] = gsl_vector_calloc(SIZE);
        gsl_vector_set(vec_b[i],i,1);
        gsl_linalg_LU_solve(A, p, vec_b[i], vec_x[i]);
    }

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            gsl_matrix_set(B, i, j, gsl_vector_get(vec_x[j],i));
        }
    }
    save_matrix(file, B, "Macierz odwrotna");
    //zad4
    file << "\nzad4\n";

    gsl_matrix *C = gsl_matrix_calloc(SIZE, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            double temp = gsl_matrix_get(C,i,j);
            for (int k=0; k < SIZE; k++)
            {
                temp += gsl_matrix_get(A_copy,i,k) * gsl_matrix_get(B,k,j);
            }
            gsl_matrix_set(C,i,j, temp);
        }
    }

    save_matrix(file,C,"Iloczyn AA^-1");
    
    //zad5
    file << "\nzad5\n";
    double cond = 0.;
    double sum_A[SIZE], sum_B[SIZE]; 
    for(int i = 0; i < SIZE; i++)
    {
        sum_A[i] = 0;
        sum_B[i] = 0;
        for(int j = 0; j < SIZE; j++)
        {
            sum_A[i] += fabs(gsl_matrix_get(A_copy,i,j));
            sum_B[i] += fabs(gsl_matrix_get(B,i,j));
        }

    }
    cond = max_arr(sum_A,SIZE)*max_arr(sum_B,SIZE);
    file << "wskaznik uwarunkowania macierzy cond = " << cond;
    file.close();

    return 0;
}