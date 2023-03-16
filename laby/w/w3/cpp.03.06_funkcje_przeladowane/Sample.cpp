#include <iostream>

int max(int, int);
float max(float, float);

void print(int);
void print(float);
void print(char);

int main(int argc, char *argv[])
{
	int a = 1, b = 2;
	float c = 1.1, d = 2.2;

	print(max(a, b));
	print(max(c, d));
	print(max((float)a, d));
	print(max((int)c, (int)d));

	print('A');
}

int max(int a, int b)
{
	return b < a ? a : b;
}

float max(float a, float b)
{
	return b < a ? a : b;
}

void print(int a)
{
	std::cout << "Liczba calkowita =   " << a << std::endl;
}

void print(float a)
{
	std::cout << "Liczba rzeczywista = " << a << std::endl;
}

void print(char a)
{
	std::cout << "Znak =               " << a << std::endl;
}

