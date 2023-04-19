#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

//g++ main.cpp -lgsl -lgslcblas -lm && ./a.out

#define H 0.000000001
using namespace std;
double fun(double d, double a =2., double b=2., double k=0.25);
double fun_deriv(double d, double a =2., double b=2., double k=0.25);
double newton(double d0, double d1, double a, double b, double k)
{	
	double dp0, dp1;
	do
	{
		d1 = d0 - (fun(d0,a,b,k)/fun_deriv(d0,a,b,k));
		dp0 = d0;
		dp1 = d1;
		d0 = d1;
	}while(fabs(dp1-dp0) > 0.0000001);
	return d0;
}


int main()
{

	double d0 = 1.1;
	double d1 = 1.;
	fstream plik, graph;
	plik.open("out.txt");
	graph.open("graph.txt");
	
	double rozwiazanie = newton(d0,d1,2.,2.,0.25);
	plik << "zad1: " << rozwiazanie << '\n';
	//zad2 i 3
	//plik << "zad2: \n";
	double min;
	std::vector<double> C, B, D;
	for(double c = 2.; c < 10.; c+=0.01)
	{
		rozwiazanie = newton(c/2.,1.0, c,c,0.25);
		//plik << "C: " << c << " B = A: " << c - rozwiazanie << " D:" << rozwiazanie << '\n';
		C.push_back(c);
		D.push_back(rozwiazanie);
		B.push_back(c - rozwiazanie);
		if(fabs(2*rozwiazanie - c) < 0.0000001)
			min = c;
	}
	graph << "zad2 (dane do wykresu)\nC: ";
	for(auto x: C) graph << x << " ";
	graph << "\nD: ";
	for(auto x: D) graph << x << " ";
	graph << "\nB: ";
	for(auto x: B) graph << x << " ";
	plik << "zad3:\n";
	plik << "c = " << min;

	//zad4
	plik << "\nzad4\n";

	double dp0, dp1;
	for (double i = 0.6; i < 1.9; i+=0.2137)
	{
		d0 = i;
		plik << "przyb\t krok\t wartosc f\t wartosc pochodnej\t d0 = " <<d0 << '\n';
		do 
		{
			d1 = d0 - fun(d0)/fun_deriv(d0);
			dp0 = d0;
			dp1 = d1;
			d0 = d1;
			// przyblizenie          krok 				 wartosc f         wartosc pochodnej
			plik << d0 << " " << fabs(dp1 - dp0) << " " << fun(d0) << " " << fun_deriv(d0) << "\n";
		}while(fabs(dp1-dp0) > 0.0000001);
		plik << '\n';
	}
	plik.close();
	return 0;
}

double fun(double d, double a, double b, double k)
{

    return d/((a-d)*(b-d)) - k;
}

double fun_deriv(double d, double a, double b, double k)
{
	return (fun(d + H,a,b,k) - fun(d,a,b,k))/H;

}