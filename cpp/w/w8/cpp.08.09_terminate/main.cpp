#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

using namespace std;

/////////////////////////////////////////////////////////////////////////
class Test1
{
public:
	Test1(string nazwa = "") : m_nazwa(nazwa)
	{  cout << "Konstruktor Test1(" << m_nazwa << ")\n"; }

	Test1(const Test1& K)
	{ 
		m_nazwa = K.m_nazwa;
		cout << "Konstruktor kopiujacy Test1(" << m_nazwa << ")\n"; 
	}

	virtual ~Test1()
	{  cout << "Destruktor Test1(" << m_nazwa << ")\n";}

	virtual void print() const
	{  cout << m_nazwa << "\n"; }

protected:
	string m_nazwa;
};

void MyTerm()
{
	cout << "Wlasna funkcja terminate\n";
	std::exit(-1);
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{

	void (*ptrTerm)() = MyTerm;

	set_terminate(ptrTerm);

	try
	{
		Test1 a("aTest1");
		cout << "\nRzucam\n";

		throw a;
	}
	catch(int)
	{
		cout << "\nPo zlapaniu wyjatku\n";
	}

	cout << "\nZa 1. blokiem catch\n";
}