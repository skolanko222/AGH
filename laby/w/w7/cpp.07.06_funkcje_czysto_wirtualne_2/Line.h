#ifndef _Line_H_
#define _Line_H_
	
#include <iostream>
#include "Shape.h"

#include <iostream>

namespace OOP
{
class Line : public Shape
{
public:
	Line(double x = 0, double y = 0, double a = 1, double b = 1) : Shape(x, y), m_a(a), m_b(b)
	{}
	double Pole() const
	{ return Shape::Pole(); }
	void Rys() const; 

protected:
	double m_a, m_b;
};

/////////////////////////////////////////////////////////////////////////
void Line::Rys() const
{
	std::cout << "Rysuj Line\n";
}
} //namespace OOP
#endif