#include <iostream>

void print(int);

int main(int argc, char *argv[])
{
	int a = 1;
	float b = 1.1;

	print(a);
	{
		void print(float); //zasloniêcie a nie przeladowanie
		std::cout << "-------------------------------------------\n";
		print(a);
		print(b);
		std::cout << "-------------------------------------------\n";
	}
	print(b);

	{
		void print(float);
		std::cout << "-------------------------------------------\n";
		::print(a);  //odwolanie do zakresu globalnego
		print(b);
		std::cout << "-------------------------------------------\n";
	}

	{
		void print(int);
		void print(float); //przeladowanie w zakresie lokalnym
		std::cout << "-------------------------------------------\n";
		print(a);
		print(b);
		std::cout << "-------------------------------------------\n";
	}

}
