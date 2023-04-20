#include <iostream>

class Punkt
{
public:
	double x;
	double y;
};

int main(int argc, char *argv[])
{
	using namespace std;

	Punkt aPunkt;
	Punkt *fPunkt = new Punkt;
	Punkt &cPunkt = aPunkt;

	aPunkt.x = 1;
	aPunkt.y = 1;
	cout << "aPunkt.x, aPunkt.y = " << aPunkt.x << ", " << aPunkt.y << endl;

	fPunkt->x = 2;
	(*fPunkt).y = 2;
	cout << "fPunkt->x, fPunkt->y = " << (*fPunkt).x << ", " << fPunkt->y << endl;

	cPunkt.x = 3;
	cPunkt.y = 3;
	cout << "aPunkt.x, aPunkt.y = " << aPunkt.x << ", " << aPunkt.y << endl;

	delete fPunkt;
}
