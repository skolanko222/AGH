#include <iostream>
#include "Punkt.h"

int main(int argc, char * argv[])
{
	using namespace std;
	Punkt aPunkt;

	aPunkt.SetX(10.0);
	aPunkt.SetY(10.0);


	// double *a = new double(2);

	cout << "aPunkt.m_x, aPunkt.m_y = " << aPunkt.GetX() << ", " << aPunkt.GetX() << endl;

}
