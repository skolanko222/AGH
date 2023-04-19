#include <iostream>

class Punkt 
{
public :
	friend void raport(const Punkt& pPunkt)
	{
		std::cout << "Prywatne skladowe Punkt: _x, _y = " << pPunkt._x << ", " << pPunkt._y << std::endl;
	}
	

	Punkt (double a, double b)
	{ _x = a ; _y = b ; }

	void print() const;
  void move(double a, double b);

private:
	double  _x ,_y ;
};

void Punkt::print() const
{
	std::cout << "_x, _y = " << _x << ", " << _y << std::endl ;
}
/*******************************************************/
void Punkt::move(double a, double b)
{
	_x = a;
	_y = b;
}
/*******************************************************/

// void raport(const Punkt& pPunkt)

int main()
{
	Punkt aPunkt(1,1);
	raport(aPunkt);
	aPunkt.print();
	
	aPunkt.move(10,10);
	raport(aPunkt);
	aPunkt.print();
}
