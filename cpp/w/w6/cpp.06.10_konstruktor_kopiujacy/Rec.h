#ifndef _CREC_H_
#define _CREC_H_	

#include <iostream>

#include "Shape.h"

namespace OOP {
class Rec : public Shape {
public:
	Rec(double x = 0, double y = 0) : Shape(x, y)
	{std::cout << "Konstruktor Rec\n"; }

	//tak nie mo¿e byæ
	// Rec(Rec& K)
	Rec(const Rec& K)
	{
		_x = K._x;
		_y = K._y;
		std::cout << "Konstruktor kopiujacy Rec\n"; 
	}

	double Pole() const;
	void rys() const;
};

/////////////////////////////////////////////////////////////////////////
inline double Rec::Pole() const
{
	return _x * _y;
}

/////////////////////////////////////////////////////////////////////////
inline void Rec::rys() const
{
	std::cout << "Rysuj CRrec\n";
}

}//end of namespace OOP
#endif