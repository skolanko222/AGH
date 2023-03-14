#include <iostream>

#include "assoc.h"

void Assoc::insert(std::string name, double val)
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
	
	if(_arr != nullptr)		
		delete [] _arr;
	_arr = new_tab;
			
}


std::ostream &operator<<(std::ostream &o, const type &elem)
{
    return o << elem._key << " " << elem._val;
}

std::string print(bool val)
{
    std::string ret = val ? " Znaleziono" : "Nie znaleziono";
	return ret;
}

void Assoc::print(std::string n) const
{
	for(int i = 0; i < _size; i++)
	{
		std::cout << n << " " << _arr[i]._key << " wartosc " << _arr[i]._val << std::endl;
	}

}

type &Assoc::operator[](std::string name) const
{
	type *temp = _arr;

	for(int i = 0; i < _size; i++)
	{
		if(_arr[i]._key == name)
			break;
				
		temp++;

	}
	if(temp != _arr + _size) return (*temp);
	else
	{
		const_cast<Assoc*>(this)->insert(name, 1);
		return *(_arr + _size- 1);

	}
			
}
double Assoc::median()
{
	double sum = 0;
	for(int i = 0; i < _size; i++)
	{
		sum += _arr[i]._val;
	}

	return sum/_size;
}
bool Assoc::contains(std::string key) const
{
	for(int i = 0; i < _size; i++)
	{
		if(_arr[i]._key == key)
			return true;
	}
	return false;
}
Assoc &Assoc::operator=(Assoc &val) 
{
    if(this == &val)
        return *(this);

	//_arr = new type [_size];
	
	for(int i = 0; i < val._size; i++)
		insert(val._arr[i]._key,val._arr[i]._val);

	return *(this);

}