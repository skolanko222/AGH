#include <iostream>

using namespace std;

class Punkt 
{
public :
	Punkt (double a, double b)
	{ _x = a ; _y = b ; }

	void print() const;
	// void print();

  void move(double a, double b);

private:
	double  _x ,_y ;
};

void Punkt::print() const
// void Punkt::print()
{
	cout << "_x, _y = " << _x << ", " << _y << endl ;
}
/*******************************************************/
void Punkt::move(double a, double b)
{
	_x = a;
	_y = b;
}
/*******************************************************/

/*******************************************************/
inline void print(const Punkt& a)
{
	a.print();
}
/*******************************************************/


int main()
{
	Punkt aPunkt(1,1), bPunkt(2,2);
	const Punkt cPunkt(10,10);

	aPunkt.print();
	bPunkt.print();
	cPunkt.print();
	
	print(aPunkt);
	print(cPunkt);

	aPunkt.move(10,10);
	bPunkt.move(20,20);
	// cPunkt.move(100,100); //BLAD
}
