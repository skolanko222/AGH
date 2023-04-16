#ifndef _CSHAPE_H_
#define _CSHAPE_H_

#include <iostream>

namespace OOP {

class Shape {
public:
	Shape(double x = 0, double y = 0) : _x(x), _y(y)
	{ std::cout << "Konstruktor Shape\n"; }

	double GetX() const;
	double GetY() const;
	void SetX(double _x);
	void SetY(double _y);

	double Pole() const
	{ return 0.0; }

protected:
	double _x,_y;
};
/////////////////////////////////////////////////////////////////////////
inline double Shape::GetX() const {
	return _x;
}

/////////////////////////////////////////////////////////////////////////
inline double Shape::GetY() const {
	return _y;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetX(double x) {
	_x = x;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetY(double y) {
	_y = y;
}

}//end of namespace OOP
#endif
