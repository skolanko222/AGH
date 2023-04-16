#ifndef _SHAPE_H_
#define _SHAPE_H_
	
class Shape
{
public:
	double GetX() const;
	double GetY() const;
	void SetX(double x);
	void SetY(double y);
	double Pole() const
	{ return 0.0; }

protected:
	double _x,_y;
};
inline double Shape::GetX() const
{
	return _x;
}

/////////////////////////////////////////////////////////////////////////
inline double Shape::GetY() const
{
	return _y;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetX(double x)
{
	_x = x;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetY(double y)
{
	_y = y;
}

/////////////////////////////////////////////////////////////////////////
#endif