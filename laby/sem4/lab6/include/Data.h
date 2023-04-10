#pragma once
#include <string>

class Data
{
	public:
		Data() {}
		virtual void printData() = 0;
		virtual ~Data() {}
	
};

class IntData : public Data
{
	public:
		int _x;
	public:
		IntData(int x = 0) : _x(x) {}
		~IntData() override {}
		//void printData() override { std::cout << _x;}
	
};

class StringData : public Data
{
	private:
		std::string _str;
	public:
		StringData(std::string str = "") : _str(str) {}
		~StringData() override {}
		//void printData() override { std::cout << _str;}
	
};