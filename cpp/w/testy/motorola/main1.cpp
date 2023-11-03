#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include <cstring>

bool palindrome(char * &inputstring)
{
int len=std::strlen( inputstring);
int start= 0;
char * end =inputstring + len-1;
for(; inputstring<end && *inputstring==*end; ++inputstring , --end);
return(*inputstring==*end); 
}

struct Obj
{
	Obj(int x, const char * nm) : x(x), _name(nm) {}
	void print() const {std::cout << _name<< ' ' << x << std::endl;}
	int x = 0;
	private:
	std::string _name;
};

int main(int argCount, char *argVal[])
{

	// print ARGC
	if(argCount > 1)
		std::for_each(argVal, argVal + argCount, [](char *argVal){std::cout << argVal << std::endl;});


	std::vector<Obj> vecObj;

	vecObj.emplace_back(1,"test");
	std::for_each(vecObj.begin(), vecObj.end(), [](const Obj & o ){o.print();});

	
	return 0;
}