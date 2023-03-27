#ifndef _Shape_H_
#define _Shape_H_
		
#include <iostream>

namespace OOP
{
class Shape
{
public:
	Shape(double x = 0, double y = 0) : m_x(x), m_y(y)
	{}
	double GetX() const;
	double GetY() const;
	void SetX(double x);
	void SetY(double y);

	void Rys() const
	{ std::cout << "Nie wiem jak!\n"; }
	double Pole() const
	{ return 0.0; }

protected:
	double m_x, m_y;
};
double Shape::GetX() const
{
	return m_x;
}

/////////////////////////////////////////////////////////////////////////
double Shape::GetY() const
{
	return m_y;
}

/////////////////////////////////////////////////////////////////////////
void Shape::SetX(double x)
{
	m_x = x;
}

/////////////////////////////////////////////////////////////////////////
void Shape::SetY(double y)
{
	m_y = y;
}
} //namespace OOP
#endif