#include <iostream>
#include <string>
#include "Amf.h"


/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	using namespace std;
	using namespace OOP;
	
	Amf aAmf;

	//BLAD bo nie wiadomo, ktora funkcje uzyc z Auto czy z Lodz
	// aAmf.travel(10);

	//musimy uzyc operator zakresu
	aAmf.Auto::travel(100);
	aAmf.Lodz::travel(10);

	aAmf.printTraveled();

	//BLAD bo nie wiadomo, ktora funkcje uzyc z Auto czy z Lodz
	//pomimo tego ze nia ma dostepu do fun z Auto
	// aAmf.fun();

}