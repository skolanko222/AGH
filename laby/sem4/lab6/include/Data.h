#pragma once
#include <string>
#include <iostream>
class List;

class Data
{
	public:
		Data() {}
		virtual void printData() = 0;
		virtual void addToList(List * list) = 0;
		virtual ~Data() {}
	
};

class IntData : public Data
{
	public:
		int _x;
	public:
		IntData(int x = 0) : _x(x) {}
		IntData(IntData & o) : _x(o._x) {}
		~IntData();
		virtual void addToList(List * list) override;
		int getData() { return _x;}
		void printData() override { std::cout << _x;}
	
};

class StringData : public Data
{
	private:
		std::string _str;
	public:
		StringData(std::string str = "") : _str(str) {}
		StringData(StringData & o) : _str(o._str) {}
		~StringData();
		virtual void addToList(List * list) override;
		std::string getData() { return _str;}
		void printData() override { std::cout << _str;}
	
};