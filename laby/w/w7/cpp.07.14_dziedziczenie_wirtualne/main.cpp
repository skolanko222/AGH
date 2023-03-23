#include <iostream>
#include <string>
#include "Amf.h"


/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	using namespace std;
	using namespace OOP;
	
	Amf aAmf(1000);

	aAmf.travel(100);
	aAmf.travelAsAuto(10);
	aAmf.travelAsLodz(1);

	aAmf.printTraveled();

}

