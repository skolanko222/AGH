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
		//konstrutor przenoszacy w teorii :)
		List(List && obj);
		//przeładowany operator przypisania w teorii "przenoszacy" :)
		List & operator=(List && obj);
		//przeładowany operator przypisania
		List & operator=(List & obj);
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
			// List * temp = this;
			// while(temp != nullptr)
			// {
			// 	// StringData *obj = new StringData();
			// 	// delete temp->_data;
			// 	// temp->_data = obj;

			// 	// temp = temp->_next;
			// }
			
			return *this;
		}
		List &numeric()
		{
			List *ret_list = new List();
			List * temp = this;
			while(temp != nullptr)
			{
				if(temp->_data != nullptr && temp->_data->isNum()){
					(temp->_data)->addToList(ret_list);
				//temp->_data->printData();
				}
				temp = temp->_next;
			}
			return *ret_list;
		}
};