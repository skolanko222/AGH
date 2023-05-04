#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{

	try
	{
		int a;
		cout << "Podaj rodazaj wyrzucenia wjateku\n1 - int, 2 - double, 3 - char\n";
		cin >> a;
		if(a == 1)
			throw a;
		else if(a == 2)
			throw (double)(a);
		else if(a == 3)
			throw 'a';
		else 
			throw (float)(a);

	}
	catch(int a)
	{
		cout << "Zlapany wyjatek int = " << a << "\n";
		return -1;
	}
	catch(const double f)
	{
		cout << "Zlapany wyjatek const double = " << f << "\n";
		return -1;
	}
	catch(const char& a)
	{
		cout << "Zlapany wyjatek char\n";
		cout << "Znak jaki przes³a³a: " << a << endl;
		return -1;
	}
	catch(...)
	{
		cout << "Zlapany wyjatek nieznanego typu\n";
		return -2;
	}
	cout << "Program zadzialal poprawnie\n";
	return 0;
}
