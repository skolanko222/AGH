#include <iostream>
#include <string>
#include "Amf.h"


/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	using namespace std;
	using namespace OOP;
	
	Amf aAmf(10,100);
	aAmf.printTraveled();
	
	Auto& refAuto = aAmf;
	refAuto.printTraveled();
	
	Lodz* ptrLodz = &aAmf;
	ptrLodz->printTraveled();

}

