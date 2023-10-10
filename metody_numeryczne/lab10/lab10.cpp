#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"
//g++ lab10.cpp -lgsl -lgslcblas -lm && ./a.out

std::fstream plik;

double U1(bool o = false)
{
	int a = 17;
	int m = 8191;
	static long long int x_0 = 10;
	if(o) x_0 = 10;
	long long int temp = (a*x_0)%m;
	x_0 = temp;
	return static_cast<double>(temp)/(m-1);

}

double U2(bool o = false)
{
	int a = 85;
	int m = 8191;
	static long long int x_0 = 10;
	if(o) x_0 = 10;
	long long int temp = (a*x_0)%m;
	x_0 = temp;
	return static_cast<double>(temp)/(m-1);
}

double U3(bool o = false)
{
	int a = 1176;
	int b = 1476;
	int c = 1776;
	unsigned int m = std::pow(2,32) - 5;
	static long long int x_1 = 10;
	static long long int x_2 = 10;
	static long long int x_3 = 10;
	if(o) {x_1 = 10; x_2 = 10; x_3 = 10;}
	long long int temp = (a*x_1 + b*x_2 + c*x_3)%m;
	x_3 = x_2;
	x_2 = x_1;
	x_1 = temp;
	return static_cast<double>(temp)/(m-1);
	
}


double monteCarlo()
{
	float r = 1.;
	double pole = M_PI*r*r;
	int c_in = 0;
	double p2[2] = {0., 0.};
	int n = 20000;
	double l = 2;
	// for(int i = 1; i < n +1; i++)
	// 	plik << i << " ";
	for(int i = 1; i < n +1; i++)
	{
		double p1[2] = {U2(), U2()};
		double d = std::sqrt(std::pow(p2[0] - p1[0],2) + std::pow(p2[1] - p1[1],2));
		if(d<r) 
			c_in++;
		if(i%100 == 0)
			// plik << std::log(std::fabs(M_PI - static_cast<double>(c_in*l*l)/(i*r*r))) << " ";
			plik << i << ". " << static_cast<double>(c_in*l*l)/(i*r*r) << " err: " << std::log(std::fabs(M_PI - static_cast<double>(c_in*l*l)/(i*r*r))) << "\n";

	}

	return static_cast<double>(c_in*l*l)/(n*r*r);

}


int main(void)
{
	plik.open("out.txt");
	// plik << "\tU1 \t\t U2 \t\t U3\n";

	for(int i = 1; i < 2001; i++)
		plik  << U1() << " ";
	plik << "\n";
	U1(true);
	for(int i = 1; i < 2001; i++)
		plik  << U1() << " ";
	plik << "\n";
	U1(true);U1();
	for(int i = 1; i < 2001; i++)
		plik  << U1() << " ";
	plik << "\n";
	U1(true);U1();U1();
	for(int i = 1; i < 2001; i++)
		plik  << U1() << " ";
	plik << "\n";

	for(int i = 1; i < 2001; i++)
		plik  << U2() << " ";
	plik << "\n";
	U2(true);
	for(int i = 1; i < 2001; i++)
		plik  << U2() << " ";
	plik << "\n";
	U2(true);U2();
	for(int i = 1; i < 2001; i++)
		plik  << U2() << " ";
	plik << "\n";
	U2(true);U2();U2();
	for(int i = 1; i < 2001; i++)
		plik  << U2() << " ";
	plik << "\n";

	for(int i = 1; i < 2001; i++)
		plik  << U3() << " ";
	plik << "\n";
	U3(true);
	for(int i = 1; i < 2001; i++)
		plik  << U3() << " ";
	plik << "\n";
	U3(true);U3();
	for(int i = 1; i < 2001; i++)
		plik  << U3() << " ";
	plik << "\n";
	U3(true);U3();U3();
	for(int i = 1; i < 2001; i++)
		plik  << U3() << " ";
	plik << "\n";
	plik.close();

	plik.open("log.txt");
	monteCarlo();
	plik.close();

	return 0;
}


