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
	virtual ~Shape() 
	{}
	double GetX() const;
	double GetY() const;
	void SetX(double x);
	void SetY(double y);

	virtual void Rys() const = 0;
	virtual double Pole() const = 0;

protected:
	double m_x, m_y;
};
void Shape::Rys() const
{ std::cout << "Nie wiem jak\n"; }

double Shape::Pole() const
{	return 0; }


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