#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#define N 7
#define IT_MAX 12

//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out

void save_matrix(std::fstream &file , gsl_matrix *A, const char * str);
gsl_matrix * multiplymm(const gsl_matrix *A,const gsl_matrix *B);
gsl_vector * multiplymw(const gsl_matrix *A,const gsl_vector *B);
double multiplyww(const gsl_vector *A,const gsl_vector *B);
double vector_norm(gsl_matrix * X);
void rotate_matrix(gsl_matrix **X);
void poteg(gsl_matrix * A, gsl_matrix *X, std::fstream &file);

int main()
{
    std::fstream plik;
	plik.open("out.txt");
    
    gsl_matrix *A = gsl_matrix_calloc(N, N);
    gsl_matrix *X = gsl_matrix_calloc(N, N);
    gsl_matrix *D = gsl_matrix_calloc(N, N);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            gsl_matrix_set(A,i,j,(1.0/sqrt(2+fabs(i-j))));
        }
    }

    save_matrix(plik, A, "macierz A");
    
    poteg(A,X , plik);

    plik << std::endl;
    save_matrix(plik, X, "macierz X");

    rotate_matrix(&X);
    gsl_matrix *temp = gsl_matrix_calloc(N, N);
    temp=multiplymm(X,A);
    rotate_matrix(&X);
    D=multiplymm(temp, X);
    save_matrix(plik, D, "macierz D");

    gsl_matrix_free(A);
    gsl_matrix_free(X);
    gsl_matrix_free(temp);
    gsl_matrix_free(D);
    plik.close();
    return 0;
}

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

double vector_norm(gsl_vector * X)
{
	double norm = 0.;
	for(int i = 0; i < X->size; i++)
		norm += gsl_vector_get(X,i)*gsl_vector_get(X,i);
	return sqrt(norm);

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

void poteg(gsl_matrix * A, gsl_matrix *X, std::fstream &file)
{
    gsl_matrix *W = gsl_matrix_calloc(N, N);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            gsl_matrix_set(W,i,j,gsl_matrix_get(A,i,j));
        }
    }

    file << "Lambdy: " << std::endl;

    for(int k=0; k<N; k++)
    {
        gsl_vector *Xroz = gsl_vector_calloc(N);
        for(int i=0; i<N; i++)
            gsl_vector_set(Xroz, i, 1);
        
        gsl_vector *Xtemp = gsl_vector_calloc(N);
        double lambda = 0.0;

        for(int i=0; i<IT_MAX; i++)
        {
            Xtemp = multiplymw(W, Xroz);

            double temp1 = 0.0;
            temp1=multiplyww(Xtemp, Xroz);
            double temp2 =0.0;
            temp2=multiplyww(Xroz, Xroz);
            lambda=temp1/temp2;
            
            file.width(15);
            file << lambda << "\t";

            for(int j=0; j<N; j++)
                gsl_vector_set(Xroz, j, gsl_vector_get(Xtemp, j)/vector_norm(Xtemp));
        }
        
        for(int i=0; i<N; i++)
            gsl_matrix_set(X, k, i, gsl_vector_get(Xroz, i));

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                gsl_matrix_set(W, i, j, gsl_matrix_get(W, i, j) - lambda*multiplyww(Xroz, Xroz));

        file << std::endl;

        gsl_vector_free(Xtemp);
    }

}