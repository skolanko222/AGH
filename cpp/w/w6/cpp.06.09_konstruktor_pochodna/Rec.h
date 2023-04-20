#ifndef _CREC_H_
#define _CREC_H_	

#include <iostream>

#include "Shape.h"

namespace OOP {
class Rec : public Shape {
public:
	Rec(double x = 0, double y = 0) : Shape(x, y)
	{std::cout << "Konstruktor Rec\n"; }

	double Pole() const;
	void rys(void) const;
};

/////////////////////////////////////////////////////////////////////////
inline double Rec::Pole() const {
	return _x * _y;
}

/////////////////////////////////////////////////////////////////////////
inline void Rec::rys(void) const {
	std::cout << "Rysuj CRrec\n";
}

}//end of namespace OOP

#endif