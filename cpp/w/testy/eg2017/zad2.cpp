#include <iostream>
class is_printable 
{
	public:
		virtual void printFun(std::ostream & o) const = 0;
		friend std::ostream& operator << (std::ostream& s, const is_printable& o)
		{
			o.printFun(s);
			return s;
		}
};
class A : public is_printable
{
	private:
		const char * _napis;
	public:
		A(const char * n) : _napis(n) {}
		void printFun(std::ostream & o) const override
		{
			o << "\t" << _napis;
		}
};

class B : public is_printable
{
	private:
		int _data;
	public:
		B(int d) : _data(d) {}
		void printFun(std::ostream & o) const override
		{
			o << "\t" << _data;
		}

};
std::ostream& operator << (std::ostream& s, const is_printable& o);

int main() {
	A a{"Tekst"};
	B b{123};

	std::cout << "a=" << a << ";\tb=" << b << ";\n";
	is_printable& a_r = a; is_printable& b_r = b; 
	std::cout << "a=" << a_r << ";\tb=" << b_r << ";\n";

    return 0;
}

/*
a: Tekst: b: 123
a_r: Tekst: b_r: 123
*/