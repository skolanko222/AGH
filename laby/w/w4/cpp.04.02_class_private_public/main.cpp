#include <iostream>
using namespace std;

class Punkt {

public:
	void SetX(double x) {
		_x = x;
	}
	void SetY(double y)
	{
		_y = y;
	}
	double GetX() const
	{
		return _x;
	}
	double GetY() const
	{
		return _y;
	}

private:
	double _x;
	double _y;
// private:

};

int main(int argc, char * argv[])
{
	Punkt aPunkt {};

	aPunkt.SetX(10.0);
	aPunkt.SetY(10.0);

	cout << "a._x, a._y = " << aPunkt.GetX() << ", " << aPunkt.GetX() << endl;
	// cout << "a._x, a._y = " << aPunkt._x << ", " << aPunkt._y << endl;  //BLAD
}
