#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include "m.cpp"
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
#define EPS 0.000001
//g++ lab8.cpp -lgsl -lgslcblas -lm && ./a.out
std::fstream plik;
double maximum(std::function<double(double, int)> fun,bool flag, double a, double b)
{

	double x_1;
	double x_2;
	double x_a = a;
	double x_b = b;
	double l_2 = (std::sqrt(5)-1.)/2.;
	double git = 50.8057242086663;
	double l_1 = l_2*l_2;

	int i = 0;
	while(std::fabs(x_b - x_a) > EPS)
	{
		x_1 = x_a + l_1*(x_b - x_a);
		x_2 = x_a + l_2*(x_b - x_a);
		if(-fun(x_1,0) > -fun(x_2,0))
			x_a = x_1;
		else
			x_b = x_2;
		if(flag)
			plik << i << "\t" << std::log(std::fabs((x_a + x_b)/2-git)) << std::endl;
		i++;

	}

	return (x_a + x_b)/2.;

}

double maximum_przyb(std::function<double(double, int)> fun,bool flag, double a, double b)
{

	double x_1;
	double x_2;
	double x_a = a;
	double x_b = b;
	double l_2 = 2./3;
	double l_1 = 1./3.;
	double git = 50.8057242086663;
	int i = 0;
	while(std::fabs(x_b - x_a) > EPS)
	{
		x_1 = x_a + l_1*(x_b - x_a);
		x_2 = x_a + l_2*(x_b - x_a);
		if(-fun(x_1,0) > -fun(x_2,0))
			x_a = x_1;
		else
			x_b = x_2;
		if(flag)
			plik << i << "\t" << std::log(std::fabs((x_a + x_b)/2-git)) << std::endl;
		i++;
	}

	return (x_a + x_b)/2.;
}

double hit_zombie(std::function<double(double, int, double, double)> fun, double a, double b, double heigth, double range)
{

	double x_1;
	double x_2;
	double x_a = a;
	double x_b = b;
	double l_2 = (std::sqrt(5)-1.)/2.;
	double l_1 = l_2*l_2;
	while(std::fabs(x_b - x_a) > EPS)
	{
		x_1 = x_a + l_1*(x_b - x_a);
		x_2 = x_a + l_2*(x_b - x_a);
		if(fun(x_1,0,heigth,range) > fun(x_2,0,heigth,range) )
			x_a = x_1;
		else
			x_b = x_2;
	}

	return (x_a + x_b)/2.;
}

int main()
{
	plik.open("out.txt");
	plik_tr.open("trajektoria.txt");
	double kat_max = maximum(wziuuum,true,20.,70.);
	plik << "kat: " << kat_max << "\n";
	plik << "zasieg w funkcji kata: \n";
	for(double i = 22.; i < 70.; i += 2)
	{
		double zasieg = wziuuum(i,0);
		if(std::fabs(i-kat_max) < 1.)
			plik << "MAX ";
		plik << i<< "\t" << zasieg << "\n";
		
	}
	wziuuum(kat_max, 1);

	// 3c
	plik << "logarytm \n";
	maximum(wziuuum,true,20.,70.);
	plik << "logarytm (przyblizony) \n";
	maximum_przyb(wziuuum,true,20.,70.);

	//4
	double kat_ostrzalu1 = hit_zombie(wziuuum_range,20.,70.,0.,30000.);
	std::cout << "kat ostrzalu dla h = 0, l = 30000: " << kat_ostrzalu1 << "\n";
	std::cout << "odleglosc " << wziuuum(kat_ostrzalu1,2)<< "\n";
	double kat_ostrzalu2 = hit_zombie(wziuuum_range,20.,70.,300.,30000.);
	std::cout << "kat ostrzalu dla h = 300, l = 30000: " << kat_ostrzalu2 << "\n";
	std::cout << "odleglosc " << wziuuum(kat_ostrzalu2,3)<< "\n";

	plik << "kat ostrzalu dla h = 0, l = 30000: " << kat_ostrzalu1 << "\n";
	plik << "kat ostrzalu dla h = 300, l = 30000: " << kat_ostrzalu2 << "\n";

	plik.close();
	plik_tr.close();
	return 0;
}