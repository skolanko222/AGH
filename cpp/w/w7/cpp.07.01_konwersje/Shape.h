#ifndef _Shape_H_
#define _Shape_H_

namespace OOP {
class Shape {
public:
	Shape(double x = 0, double y = 0) : m_x(x), m_y(y)
	{}

	double GetX() const;
	double GetY() const;
	void SetX(double m_x);
	void SetY(double m_y);
	double Pole() const
	{ return 0.0; }

protected:
	double m_x,m_y;
};
double Shape::GetX() const
{
	return m_x;
}

/////////////////////////////////////////////////////////////////////////
inline double Shape::GetY() const
{
	return m_y;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetX(double x)
{
	m_x = x;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetY(double y)
{
	m_y = y;
}

/////////////////////////////////////////////////////////////////////////
} //namespace OOP
#endif
