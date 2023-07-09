#include <iostream>

class Test
{
	public:
		// ~Test() {std::cout << "Test::~Test()" << std::endl;}
		Test() {std::cout << "Test::Test()" << std::endl;}
		Test(const Test & a) {std::cout << "Test::Test(Test &)" << std::endl;}
		// Test(Test && a) {std::cout << "Test::Test(Test &&)" << std::endl;}
};


int main(void)
{
	Test a;
	Test b(a);

	return 0;
}