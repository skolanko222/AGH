#pragma once

#include <iostream>
#include <string>

struct type
{
	std::string _key;
	double _val;
	type &operator=(double val)
		{
			type *a = new type;
			a->_val = val;
			return *a;
		}
	friend std::ostream &operator<<(std::ostream &o, const type &K);

};

class Assoc
{
	private:
		type *_arr;
		int _size;

	public:
		Assoc() : _arr(nullptr), _size(0) {} 
		~Assoc()
		{
			delete [] _arr;
		}
		void insert(std::string name, double val)
		{
			_size++;
			type * new_tab = new type[_size];
			for(int i = 0; i < _size - 1; i++)
			{
				new_tab[i]._key = _arr[i]._key;
				new_tab[i]._val = _arr[i]._val;
			}

			new_tab[_size - 1]._key = name;
			new_tab[_size - 1]._val = val;
			
			delete [] _arr;
			_arr = new_tab;
			
		}
		void print(std::string n) const
		{
			for(int i= 0; i < _size; i++)
			{
				std::cout << n << " "<< _arr[i]._key << " wartosc " << _arr[i]._val << std::endl;
			}

		}
		type &operator[](std::string name) 
		{
			type *temp = _arr;
			for(int i = 0; i< _size; i++)
			{
				if(temp->_key == name)
					break;
				temp++;
			}
			
			if(temp != (_arr + _size)) return *temp;
			else
			{ 
			
				insert(name, 0.);
				return *(_arr + _size);
			}
		}
		Assoc &operator=(Assoc val) 
		{
			Assoc a;
			return a;
		}
		bool contains(std::string key) const
		{

			return 1;
		}

};

std::ostream &operator<<(std::ostream &o, const type &K)
{
  return o << K._key << std::endl;
}

std::string print(bool val)
{
	std::string ret = val ? "Znalezniono" : "nie Znalezniono";
	return ret;
}