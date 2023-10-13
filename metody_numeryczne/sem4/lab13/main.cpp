#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
std::fstream plik;


using d_vec = std::tuple<std::vector<double>,std::vector<double>,std::vector<double>>;

d_vec euler(double a,double b,double c,double d,double K,double Z,double t0,double tk, double dt)
{
	std::vector<double> vec0;
	std::vector<double> vec1;
	std::vector<double> vec2;
	for(double i = t0; i < tk; i += dt)
	{
		K += (a*K - b*K*Z)*dt;
		Z += (c*K*Z - d*Z)*dt;
		vec0.push_back(i);
		vec1.push_back(K);
		vec2.push_back(Z);
	}
	return d_vec{vec0,vec1, vec2};
}
d_vec Runge_Kuttys(double a,double b,double c,double d,double K,double Z,double t0,double tk, double dt)
{
	std::vector<double> vec0;
	std::vector<double> vec1;
	std::vector<double> vec2;
	for(double i = t0; i < tk; i += dt)
	{
		double K1 = (a*K - b*K*Z)*dt;
		double Z1 = (c*K*Z -d*Z)*dt;
		K += (a*(K + K1/2.) - b * (K + K1/2.) * (Z + Z1/2.))*dt;
        Z += (c*(K + K1/2.)*(Z + Z1/2.) - d* (Z + Z1/2.))*dt;

		vec0.push_back(i);
		vec1.push_back(K);
		vec2.push_back(Z);
	}
	return d_vec{vec0,vec1, vec2};
}
int main()
{
	plik.open("out.txt");
	double a = 1.;
    double b = 1.;
    double c = 1.;
    double d = 1.;
	double K = 1.;
	double Z = .5;

	double t0 = 0.;
	double tk = 40.;

	double dt = 0.1;
	d_vec e1 = euler(a,b,c,d,K,Z,t0,tk,dt);
	for(const auto & a : std::get<0>(e1))
		plik << a << ' ';
	plik << "\n";
	for(const auto & a : std::get<1>(e1))
		plik << a << ' ';
	plik << "\n";
	for(const auto & a : std::get<2>(e1))
		plik << a << ' ';
	plik << "\n\n";

	d_vec r1 = Runge_Kuttys(a,b,c,d,K,Z,t0,tk,dt);
	for(const auto & a : std::get<0>(r1))
		plik << a << ' ';
	plik << "\n";
	for(const auto & a : std::get<1>(r1))
		plik << a << ' ';
	plik << "\n";
	for(const auto & a : std::get<2>(r1))
		plik << a << ' ';
	plik << "\n";

	return 0;
}