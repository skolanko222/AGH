#pragma once
#include <iostream>
#include <string>

class ListaWektorow;
class DzialaniaNaZbiorach;

class Wektor2D
{
	private:
		std::string _str;
		int _x;
		int _y;
	public:
		friend void print (const Wektor2D * temp);
		friend void print2 (const Wektor2D & temp);
		friend class ListaWektorow;
		friend class DzialaniaNaZbiorach;
		Wektor2D(const char * s , int x = 0, int y = 0) : _str(s), _x(x), _y(y) {}
		Wektor2D(std::string s , int x = 0, int y = 0) : _str(s), _x(x), _y(y) {}
		bool operator<(const Wektor2D &a) const
		{
			return _x < a._x;
		}
		bool operator==(const Wektor2D &a) const
		{
			return _x == a._x;
		}

};

void print(const Wektor2D * temp);
void print2(const Wektor2D & temp);