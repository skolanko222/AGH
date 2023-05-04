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

	virtual ~Test1()
	{}

	virtual void Test() throw()
	{ throw m_nazwa;}

	virtual void print() const
	{  cout << m_nazwa << "\n"; }

protected:
	string m_nazwa;
};

/////////////////////////////////////////////////////////////////////////
void MyUnExpec()
{
	cout << "Wlasna funkcja unexpected\n";
	std::exit(-1);
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	set_unexpected(MyUnExpec);

	try
	{
		Test1 a("aTest1");
		cout << "\nRzucam\n";

		a.Test();
	}
	catch(string &K)
	{
		cout << "\nPo zlapaniu wyjatku " << K << "\n";
	}
}