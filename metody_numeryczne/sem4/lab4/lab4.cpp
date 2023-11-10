#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#include "helper.h"

//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out

void oblicz(gsl_matrix *A,gsl_matrix *X_rozw);

#define N 7
#define M 12

int main()
{


	gsl_matrix * A = gsl_matrix_calloc(N,N);
	gsl_matrix * X_rozw = gsl_matrix_calloc(N,N);

	for( short i =0; i < N; i++)
	{
		for( short j =0; j < N; j++)
		{
			double temp = pow((2 + fabs(i-j)),(-fabs(i-j)/2.));
			gsl_matrix_set(A,i,j,temp);			
		}
	}
	save_matrix("A.txt",A,"Macierz A:");
	oblicz(A,X_rozw);


	return 0;
}
void oblicz(gsl_matrix *A,gsl_matrix *X_rozw)
{
	gsl_matrix *W = gsl_matrix_calloc(A->size1,A->size2);
	gsl_matrix_memcpy(W,A);

	gsl_vector *X = gsl_vector_calloc(A->size1);
	
	save_vector("x.txt",X,"wektor X:");

	gsl_vector *X_1 = gsl_vector_calloc(A->size1);
	std::fstream lamba_plik("l.txt", std::ios_base::app);
	for(size_t j = 0; j < N; j++)
	{	
		for(size_t i = 0; i < A->size1; i++ )
			gsl_vector_set(X,i,1);

		double lambda = 0.;
		for(size_t i = 0; i < M; i++ )
		{
			X_1 = multiplymw(W,X);
			lambda = multiplyww(X_1,X)/multiplyww(X,X);
			//lamba_plik << lambda << ' ';
			for(int k=0; k<N; k++)
            	gsl_vector_set(X_1, k, gsl_vector_get(X, k)/vector_norm(X));

		}
		lamba_plik << lambda << ' ';
		// for(int i=0; i<N; i++)
        //     gsl_matrix_set(X_rozw, j, i, gsl_vector_get(X_1, i));

		// save_vector(lamba_plik,X_rozw,"wektor wlasny:");

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                gsl_matrix_set(W, i, j, gsl_matrix_get(W, i, j) - lambda*multiplyww(X, X));
	
	}
	lamba_plik << '\n';
	lamba_plik.close();

}