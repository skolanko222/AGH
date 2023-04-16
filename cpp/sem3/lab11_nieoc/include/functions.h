#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Linear
{
	private:
		double _a;
		double _b;
	public:
		Linear(double a, double b) : _a(a), _b(b) {};
		double getA() const {return _a;}
		double getB() const {return _b;}
		double operator()(double x) const {return _a*x + _b;}

};

class Sqrt
{
	public:
		Sqrt() {};
		double operator()(double x) const {return sqrt(x);}


};

class Sin
{
	private:
		Linear _f;
	public:
		Sin(double a, double b) : _f(a, b) {};
		double operator()(double x) const {return sin(_f(x));}

		
};

std::ostream &operator<<(std::ostream &o,const Linear & ob)
{
	return o << ob.getA() << "x" << ob.getB();
}