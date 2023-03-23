#ifndef _Rec_H_
#define _Rec_H_	

#include <iostream>
#include "Shape.h"

namespace OOP {
class Rec: public Shape {
public:
	Rec(double x = 0, double y = 0) : Shape(x, y)
	{}
	double Pole() const;
	void rys() const;

	char a;
};

/////////////////////////////////////////////////////////////////////////
inline double Rec::Pole() const
{
	return m_x * m_y;
}

/////////////////////////////////////////////////////////////////////////
inline void Rec::rys() const
{
	std::cout << "Rysuj CRrec\n";
}

/////////////////////////////////////////////////////////////////////////
} //namespace OOP
#endif