#ifndef _Rec_H_
#define _Rec_H_
	
#include <iostream>
#include "Shape.h"

#include <iostream>

namespace OOP
{
class Rec : public Shape
{
public:
	Rec(double x = 0, double y = 0, double a = 1, double b = 1) : Shape(x, y), m_a(a), m_b(b)
	{}
	double Pole() const;
	void Rys() const; 

protected:
	double m_a, m_b;
};

/////////////////////////////////////////////////////////////////////////
inline double Rec::Pole() const
{
	return m_a * m_b;
}

/////////////////////////////////////////////////////////////////////////
inline void Rec::Rys() const
{
	std::cout << "Rysuj Rec\n";
}
} //namespace OOP
#endif