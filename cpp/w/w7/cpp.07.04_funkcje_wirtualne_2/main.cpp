#include <iostream>

class Shape {
public:
	Shape(double x = 0, double y = 0) : m_x(x), m_y(y)
	{}
	virtual ~Shape() 
	{}
	double GetX() const
	{ return m_x; }
	double GetY() const
	{ return m_y; }
	void SetX(double x)
	{ m_x = x; }
	void SetY(double y)
	{ m_y = y; }

	virtual void Rys() const
	{ std::cout << "Nie wiem jak!\n"; }
	virtual double Pole() const
	{ return 0.0; }

protected:
	double m_x, m_y;
};

/////////////////////////////////////////////////////////////////////////
class ShapeNoVirtual {
public:
	ShapeNoVirtual(double x = 0, double y = 0) : m_x(x), m_y(y)
	{}
	~ShapeNoVirtual() 
	{}
	double GetX() const
	{ return m_x; }
	double GetY() const
	{ return m_y; }
	void SetX(double x)
	{ m_x = x; }
	void SetY(double y)
	{ m_y = y; }

	void Rys() const
	{ std::cout << "Nie wiem jak!\n"; }
	double Pole() const
	{ return 0.0; }

protected:
	double m_x, m_y;
};

/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	using namespace std;

	cout << "Rozmiar ShapeNoVirtual = " << sizeof(ShapeNoVirtual) << endl;
	cout << "Rozmiar Shape =          " << sizeof(Shape) << endl;
}
