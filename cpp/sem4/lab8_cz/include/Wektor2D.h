#pragma once
#include <string>
#include <set>
#include <cmath>

#include <iostream>

class Wektor2D
{
	private:
		int _x;
		int _y;
		std::string _s;
	public:
		Wektor2D(const char *c, int x, int y) : _x(x), _y(y), _s(c) {}
		double len() const {return std::sqrt(_x*_x + _y*_y);}
		bool operator<(const Wektor2D& obj) const {return len() < obj.len();}
		std::string getName() const {return _s;}
		int getX() const {return _x;}
		int getY() const {return _y;}

};
void print(const Wektor2D &v) {std::cout << v.getName() << " " << v.getX() << " " << v.getY() << "\n";}
void print(const Wektor2D * v) {std::cout << v->getName() << " " << v->getX() << " " << v->getY() << "\n";}
