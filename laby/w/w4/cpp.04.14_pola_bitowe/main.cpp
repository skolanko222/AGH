#include <iostream>
class Port
{
public:
	unsigned read : 1;
	unsigned status : 1;
	unsigned data : 6;
};
/////////////////////////////////////////////////////////////////////////
class PortInt
{
public:
	unsigned read;
	unsigned status;
	unsigned data;
};
/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace std;

	Port aPort;
	aPort.read = 1;
	aPort.status = 0;
	aPort.data = 63;	
	cout << aPort.read << ", " << aPort.status << ", " << aPort.data << endl;

	aPort.read = 0;
	aPort.status = 2;
	aPort.data = 562;	
	cout << aPort.read << ", " << aPort.status << ", " << aPort.data << endl;

	cout << "sizeof(Port)    = " << sizeof(Port) << endl;
	cout << "sizeof(PortInt) = " << sizeof(PortInt) << endl;
}
