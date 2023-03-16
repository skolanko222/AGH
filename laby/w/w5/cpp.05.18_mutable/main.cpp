#include <iostream>
#include <string>
#include "Frac.h"

/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace OOP;
	const Frac aFraction(1, 2, "aFraction");
	const Frac bFraction;

	aFraction.printOut();

	bFraction.SetOpis("bFraction"); //OK mimo i¿ obiekt sta³y
	// bFraction.SetLM(1, 2); //Blad bo obiekt sta³y

	bFraction.printOut();
}
