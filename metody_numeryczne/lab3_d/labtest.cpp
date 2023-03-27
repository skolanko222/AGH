#include <iostream>
#include <fstream>
#include <cmath>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#include "gsl_wrapper.hpp"

#define SIZE 100
#define M 2

//g++ lab2.cpp -lgsl -lgslcblas -lm && ./a.out

int main(void)
{
	my_gsl::matrix macierz("a.txt",4,4);
	//my_gsl::matrix macierz_kopia = macierz;
	my_gsl::matrix macierz_3; 
	//macierz = macierz;
	macierz_3 = macierz;

	return 0; 
}