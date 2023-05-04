#include <iostream>
#include "Fraction.h"

int main(int argc, char* argv[]) {
	OOP::Fraction a = OOP::ReadFraction();
	std::cout << a << '\n';
}