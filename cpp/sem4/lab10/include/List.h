#pragma once
#include "Data.h"

//klasa reprezentujaca liste
class List
{
	private:
		Data * _data;
		List * _next;
		void setPData(Data * a, List * b) {_data = a; _next = b;}
	public:
		//typ wyliczeniowy, gdzie ma zostac dodany elem
		enum side {Begin, End};
		//defaultowy konstruktor
		List(Data * d = nullptr, List * n = nullptr ) : _data(d), _next(n) {}
		//konstrutor kopiujacy
		List(List & obj);
		//przeładowany operator przypisania
		List & operator=(List & obj)
		{
			if(this == &obj)
				return *this;
			if(_next != nullptr)
			{
				delete _next;
				_next = nullptr;
			}
			if(_data != nullptr)
			{
				delete _data;
				_data = nullptr;
			}
			List *old_list = &obj;
			while (old_list != nullptr)
			{
				old_list->_data->addToList(this);
				old_list = old_list->_next;
			}
			return *this;
		}
		//destruktor
		~List();
		//metoda dodajaca IntData do listy
		List & insert(const IntData &obj, side where = End);
		//metoda dodajaca StringData do listy
		List & insert(const StringData &obj, side where = End);
		//metoda dodajaca FloatData do listy
		List & insert(const FloatData &obj, side where = End);
		//
		List & insert(const Boolean &obj, side where = End);
		//metoda sprawdzajaca czy dany elem jest w iscie
		bool find(const Data &obj);
		//przeladowany operator, ktory konkatenuje dwie listy
		List & operator<<(List & a);
		//metoda printujaca liste
		void print();
		//funkcja List::convert_to_stringdata która zwraca nową listę, w której wszystkie dane 
    	//przekonwertowane zostały na typ StringData
		List & convert_to_stringdata()
		{
			
			return *this;
		}
};