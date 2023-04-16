#include <iostream>
#include "Punkt.h"

int main(int argc, char * argv[])
{
	using namespace std;
	
	cout << "Punkt::n = " << Punkt::GetN() << endl;
	
	Punkt *f;
	f = new Punkt(10,20);

	cout << "Punkt::n = "  << f->GetN() << endl;
	
	delete f;

	Punkt a[3];
	cout << "Punkt::n = "  << a[0].GetN() << endl;
	//a[0].n = 0; //BLAD bo n jest prywatne
}
