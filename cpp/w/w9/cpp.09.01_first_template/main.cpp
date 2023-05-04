#include <iostream>
#include <string>
#include <typeinfo>

#include "Fraction.h"

namespace OOP{

	template<typename T> T max(T a, T b)
	{
		std::cout << "Nazawa typu obiektu: " << typeid(T).name() << std::endl;
		return (a < b) ? b : a;
		// return (a > b) ? a : b;
	}

	template<typename T> T min(T a, T b)
	{
		std::cout << "Nazawa typu obiektu: " << typeid(T).name() << std::endl;
		return (a < b) ? a : b;
	}
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	using namespace std;
	
	cout << "max(2, 3) = " << OOP::max(2, 3) << endl;
	cout << "min(2, 3) = " << OOP::min(2, 3) << endl;

	cout << "max(2.3, 3.3) = " << OOP::max(2.3, 3.3) << endl;
	cout << "min(2.3, 3.3) = " << OOP::min(2.3, 3.3) << endl;

	cout << "max('a', 'b') = " << OOP::max('a', 'b') << endl;
	cout << "min('a', 'b') = " << OOP::min('a', 'b') << endl;

	cout << "max(OOP::Fraction{2, 5}, OOP::Fraction{13, 50}) = " 
		<< OOP::max(OOP::Fraction{2, 5}, OOP::Fraction{13, 50}) << endl;
	cout << "min(OOP::Fraction{2, 5}, OOP::Fraction{13, 50}) = " 
		<< OOP::min(OOP::Fraction{2, 5}, OOP::Fraction{13, 50}) << endl;

	cout << R"-(max(std::string("Ala"), std::string("Ola")) = )-" 
		<< OOP::max(std::string("Ala"), std::string("Ola")) << endl;
	cout << R"*(min(std::string("Ala"), std::string("Ola")) = )*" 
		<< OOP::min(std::string("Ala"), std::string("Ola")) << endl;

}