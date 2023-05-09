#pragma once
#include <iostream>
#include <string>


class Punkt
{
	private:
		std::string _str;
		int _x;
		int _y;
	public:
		// przeladowany globany operator << dla klasy Punkt
		friend std::ostream & operator<<(std::ostream &a, const Punkt &obj);
		// konstruktor
		Punkt(const char * s, int x, int y) : _x(x), _y(y), _str(s) {}
		Punkt(const Punkt &a) = default;
		// template gettera wspolrzednych _x i _y
		template<char i> int wsp() 
		{
			return i == 'x' ? _x : _y;
		}
		// template settera wspolrzednych _x i _y
		template<char i> void setWSP(int a) 
		{
			i == 'x' ? _x = a : _y = a;
		}
		// przeladowany operator < dla klasy Punkt
		bool operator<(const Punkt & rhs) const {return _x == rhs._x ? _y < rhs._y : _x < rhs._x;}
		//template metody statycznej max
		template<typename T>static T max(const T &a,const T &b) 
		{
			return a < b? b: a;
		} 
};
// template swapa
template<typename T> void swap(T &a, T &b) 
{
	T c(a);
	a = std::move(b);
	b = std::move(c);
}
// template wyspecjalizowanego swapa dla Punkt
template<> void swap<Punkt>(Punkt &a, Punkt &b);
std::ostream & operator<<(std::ostream &a, const Punkt &obj);