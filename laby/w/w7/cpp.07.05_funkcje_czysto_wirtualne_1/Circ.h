#ifndef _CIRC_H_
#define _CIRC_H_
	
#include <iostream>
#include "Shape.h"
	
namespace OOP
{
class Circ : public Shape
{
public:
	Circ(double x = 0, double y = 0, double rad = 1) : Shape(x, y), m_rad(rad)
	{}
	double Pole() const;
	void Rys() const;

protected:
	double m_rad;
};

/////////////////////////////////////////////////////////////////////////
inline double Circ::Pole() const
{
	return 3.14159 * m_rad * m_rad;
}

/////////////////////////////////////////////////////////////////////////
inline void Circ::Rys() const
{
	std::cout << "Rysuj Circ\n";
}
} //namespace OOP
#endif