#include <stdio.h>
// zakladając, że w obecnym katalogu są pliki nr.h, nrutil.h, nrutil.c, gaussj.c
#include "nr.h"
#include "nrutil.h"

// alternatywnie, pracując na Taurusie można skorzystać z poniższych dyrektyw
// #include "/home/NR/numerical_recipes.c//nrutil.h"
// #include "/home/NR/numerical_recipes.c/nrutil.c"
// #include "/home/NR/numerical_recipes.c/gaussj.c"

int main(){
	int n = 10;

	float **vec = matrix(1, n, 1, 1);
	float **A = matrix(1, n, 1, n);

	// zerowanie macierzy:
	for (int i = 1; i < n+1; ++i){
		for (int j = 1; j < n+1; ++j){
			A[i][j] = 0;
		}
		vec[i][1] = 0;
	}
	// wypelnianie macierzy:
	A[2][1] = -1;
	for (int i = 1; i < n+1; ++i){
		A[i][i] = 1;
	}
	for (int i = 3; i < n+1; ++i){
		A[i][i-2] = -1;
	}
	// wypelnianie wektora:
	vec[1][1] = 10;

	// wypisanie macierzy:
	// for (int i = 1; i < n+1; ++i){
	// 	for (int j = 1; j < n+1; ++j){
	// 		printf( "%.2lf\t", A[i][j] );
	// 	}
	// 	printf( "\n");
	// }

	// rozwiazanie ukladu rownan
	gaussj(A, n, vec, 1);

	// wypisanie wyniku
	for (int i = 1; i < n+1; ++i){
		printf( "%i\t%.6lf\n", (i-1), vec[i][1] );
	}

	free_matrix(vec, 1, n, 1, 1);
	free_matrix(A, 1, n, 1, n);
	return 0;
}
