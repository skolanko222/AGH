#pragma once
#include "Data.h"

//klasa reprezentujaca liste
class List
{
	private:
		Data * _data;
		List * _next;
		void setPData(Data * a) {_data = a; }//_next = n;}
	public:
		//typ wyliczeniowy, gdzie ma zostac dodany elem
		enum side {Begin, End};
		//defaultowy konstruktor
		List(Data * d = nullptr, List * n = nullptr ) : _data(d), _next(n) {}
		//konstrutor kopiujacy
		List(List & obj);
		//destruktor
		~List();
		//metoda dodajaca IntData do listy
		List & insert(const IntData &obj, side where = End);
		//metoda dodajaca StringData do listy
		List & insert(const StringData &obj, side where = End);
		//metoda dodajaca FloatData do listy
		List & insert(const FloatData &obj, side where = End);
		//metoda sprawdzajaca czy dany elem jest w iscie
		bool find(const Data &obj);
		//przeladowany operator, ktory konkatenuje dwie listy
		List & operator<<(List & a);
		//metoda printujaca liste
		void print();
};