#pragma once
#include <string>
#include <iostream>
class List;

//klasa wirtualna
class Data
{
	public:
		//metoda virtualna wypisujaca elem. listy
		virtual void printData() = 0;
		//metoda polimorficznie dodajaca elementy do listy
		virtual void addToList(List * list) = 0;
		//wirtualny destruktor
		virtual ~Data() {}
	
};

//klasa reprezentujacac typ całkowity
class IntData : public Data
{
	public:
		int _x;
	public:
		//konstruktor
		IntData(int x = 0) : _x(x) {}
		//konstruktor kopiujący
		IntData(IntData & o) : _x(o._x) {}
		//destruktor
		~IntData();
		//metoda dodajaca obiekt IntData do listy
		virtual void addToList(List * list) override;
		//getter
		int getData() const { return _x;}
		//metoda virtualna wypisujaca przechowywana liczbe
		void printData() override { std::cout << _x;}
	
};

//klasa reprezentujacac napis
class StringData : public Data
{
	private:
		std::string _str;
	public:
		//konstruktor
		StringData(std::string str = "") : _str(str) {}
		//konstruktor kopiujący
		StringData(StringData & o) : _str(o._str) {}
		//destruktor
		~StringData();
		//metoda dodajaca obiekt StringData do listy
		virtual void addToList(List * list) override;
		//getter
		std::string getData() const { return _str;}
		//metoda virtualna wypisujaca przechowywanego sttringa
		void printData() override { std::cout << _str;}
	
};