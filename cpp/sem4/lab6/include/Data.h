#pragma once
#include <string>
#include <iostream>
class List;

//klasa wirtualna
class Data
{
	public:
		Data() {}
		//metoda printujaca dane elementu
		virtual void printData() = 0;
		//metoda dodaje element do listy
		virtual void addToList(List * list) = 0;
		//metoda sprawdza czy dane sa sobie rowne
		virtual bool isSame( const Data& a) const = 0;
		//wirtualny desruktor
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
		int getData() const { return _x;}
		void printData() override { std::cout << _x;}
		virtual bool isSame( const Data& a) const override
		{
			try {
				if(_x ==dynamic_cast<const IntData &>(a)._x)
				return true;
			} catch(std::bad_cast) {
			return false; // w kontekście zadania
			}
			return false;
		}
	
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
		std::string getData() const { return _str;}
		void printData() override { std::cout << _str;}
		virtual bool isSame( const Data& a) const override
		{
			try {
				if(_str ==dynamic_cast<const StringData &>(a)._str)
				return true;
			} catch(std::bad_cast) {
			return false; // w kontekście zadania
			}
			return false;
		}
	
};

class FloatData : public Data
{
	private:
		float _f;
	public:
		FloatData(float f) : _f(f) {}
		FloatData(FloatData & o) : _f(o._f) {}
		~FloatData();
		virtual void addToList(List * list) override;
		float getData() const { return _f;}
		void printData() override { std::cout << _f;}
		virtual bool isSame( const Data& a) const override
		{
			try {
				if(_f ==dynamic_cast<const FloatData &>(a)._f)
				return true;
			} catch(std::bad_cast) {
			return false; // w kontekście zadania
			}
			return false;
		}
	
};