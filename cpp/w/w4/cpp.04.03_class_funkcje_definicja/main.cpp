#include <iostream>
using namespace std;

class Punkt
{
public:
	void SetX(double x);
	void SetY(double y);
	double GetX() const;
	double GetY() const;

private:
	double _x;
	double _y;
};
/////////////////////////////////////////////////////////////////////////
void Punkt::SetX(double x)
{
	_x = x;
}
/////////////////////////////////////////////////////////////////////////
inline void Punkt::SetY(double y)
{
	_y = y;
}
/////////////////////////////////////////////////////////////////////////
double Punkt::GetX() const
{
	return _x;
}
/////////////////////////////////////////////////////////////////////////
double Punkt::GetY() const
{
	return _y;
}
/////////////////////////////////////////////////////////////////////////

int main(int argc, char * argv[])
{
	Punkt aPunkt;

	aPunkt.SetX(10.0);
	aPunkt.SetY(10.0);

	cout << "a._x, a._y = " << aPunkt.GetX() << ", " << aPunkt.GetX() << endl;

}
