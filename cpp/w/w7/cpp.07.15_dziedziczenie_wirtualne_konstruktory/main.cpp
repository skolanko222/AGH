#include <iostream>
#include <string>
#include "Amf.h"
using namespace std;
using namespace OOP;

class aAmf2 : public Amf
{
	public:
		aAmf2(int a) : Amf(a) {std::cout << "aAmf2" << std::endl;}
		~aAmf2() {std::cout << "~aAmf2" << std::endl;}
};

/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
		
	aAmf2 aAmf(1000);
	aAmf.travel(100);
	aAmf.travelAsAuto(10);
	aAmf.travelAsLodz(1);

	aAmf.printTraveled();

}

