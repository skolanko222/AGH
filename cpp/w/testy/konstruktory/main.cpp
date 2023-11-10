#include <iostream>

class Test
{
	public:
		// ~Test() {std::cout << "Test::~Test()" << std::endl;}
		Test() {std::cout << "Test::Test()" << std::endl;}
		Test(const Test & a) {std::cout << "Test::Test(Test &)" << std::endl;}
		Test(Test && a) {std::cout << "Test::Test(Test &&)" << std::endl;}
		static Test fun() {return Test();}
};


int main(void)
{
	// Test a;
	Test b = Test::fun();

	return 0;
}