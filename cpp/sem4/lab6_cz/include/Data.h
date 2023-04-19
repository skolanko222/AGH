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
		virtual bool isEqual(int x) {return true;};
		virtual bool isEqual(std::string s) {return true;};
		virtual bool isEqual(bool val) {return true;};
		virtual std::string toString() const = 0;
		
		virtual ~Data() {}
	
};

class IntData : public Data
{
	public:
		int _x;
	public:
		IntData(int x = 0) : _x(x) {}
		IntData(IntData & o) : _x(o._x) {}
		int operator*() {return _x;} 
		~IntData();
		virtual void addToList(List * list) override;
		int getData() const { return _x;}
		void printData() override { std::cout << _x;}
		virtual bool isEqual(int x) override 
		{
			if(x == _x) return true;
			return false;}
			
		virtual std::string toString()const override { return std::to_string(_x);}
	
};

class StringData : public Data
{
	private:
		std::string _str;
	public:
		StringData(std::string str = "") : _str(str) {}
		StringData(StringData & o) : _str(o._str) {}
		std::string operator*() {return _str;} 
		~StringData();
		virtual void addToList(List * list) override;
		std::string getData() const { return _str;}
		void printData() override { std::cout << _str;}
		virtual bool isEqual(std::string s) override {return s==_str ? true: false;}
		virtual std::string toString()const override { return _str;}
	
};

class Boolean : public Data
{
	public:
		bool _val;
	public:
		Boolean(bool x = 0) : _val(x) {}
		Boolean(Boolean & o) : _val(o._val) {}
		~Boolean();
		virtual void addToList(List * list) override;
		bool getData() const { return _val;}
		void printData() override { std::cout << (_val ? "true" : "false");}
		virtual bool isEqual(bool val) override {return val==_val ? true: false;}
		virtual std::string toString()const override { return _val ? "true": "false";}
		
	
};