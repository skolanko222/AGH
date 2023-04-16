#ifndef _CSHAPE_H_
#define _CSHAPE_H_

#include <iostream>

class Shape {
public:
	Shape(double x = 0, double y = 0) : m_x(x), m_y(y)
	{ }

	virtual ~Shape()
	{}

	Shape(const Shape& v) : m_x(v.m_x), m_y(v.m_y) { 
		std::cout << __PRETTY_FUNCTION__ << std::endl; 
	}

	double GetX() const;
	double GetY() const;
	void SetX(double m_x);
	void SetY(double m_y);

	double Pole() const
	{ return 0.0; }

	virtual void rys() const
	{ std::cout << "m_x: " << m_x << ", m_y: " << m_y << "\n";}

protected:
	double m_x,m_y;
};

/////////////////////////////////////////////////////////////////////////
inline double Shape::GetX() const {
	return m_x;
}

/////////////////////////////////////////////////////////////////////////
inline double Shape::GetY() const {
	return m_y;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetX(double x) {
	m_x = x;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetY(double y) {
	m_y = y;
}
#endif