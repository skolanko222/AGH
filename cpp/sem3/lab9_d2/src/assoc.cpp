#include <assoc.h>

Assoc::Assoc(int len): _len{len}, _arr{new Element[len]} {}
Assoc::Assoc(const Assoc &to_copy): Assoc{to_copy._len}
{
	for(int i=0;i<_len;i++)
	{
		_arr[i]._key=to_copy._arr[i]._key;
		_arr[i]._val=to_copy._arr[i]._val;
	}
}
Assoc::Assoc(Assoc &&to_move): Assoc{to_move}
{
	delete [] to_move._arr;
}
Assoc::~Assoc()
{
	delete [] _arr;
	_len=0;
}
void Assoc::insert(const std::string key,double val)
{
	Assoc tmp(std::move(*this));
	_len++;
	_arr=new Element[_len];
	for(int i=0;i<_len-1;i++)
	{
		_arr[i]._key=tmp._arr[i]._key;
		_arr[i]._val=tmp._arr[i]._val;
	}
	_arr[_len-1]._key=key;
	_arr[_len-1]._val=val;
}
void Assoc::print(const std::string str) const
{
	for(int i=0;i<_len;i++)
		std::cout<<str<<" Klucz: "<<_arr[i]._key<<" wartosc: "<<_arr[i]._val<<std::endl;
}
double &Assoc::operator[](const std::string key)
{
	for(int i=0;i<_len;i++)
	{
		if(_arr[i]._key==key)
			return _arr[i]._val;
	}
	insert(key,0);
	return _arr[_len-1]._val;
}
double &Assoc::operator[](const std::string key) const
{
	for(int i=0;i<_len;i++)
	{
		if(_arr[i]._key==key)
			return _arr[i]._val;
	}
	return _arr[_len-1]._val;
}
Assoc &Assoc::operator=(const Assoc &to_assign)
{
	if(this==&to_assign)
		return *this;
	else
	{
		delete [] _arr;
		_len=to_assign._len;
		_arr=new Element[_len];
		for(int i=0;i<_len;i++)
		{
			_arr[i]._key=to_assign._arr[i]._key;
			_arr[i]._val=to_assign._arr[i]._val;
		}
	}
	return *this;
}
bool Assoc::contains(const std::string key) const
{
	for(int i=0;i<_len;i++)
	{
		if(_arr[i]._key==key)
			return true;
	}
	return false;
}

std::string print(bool var)
{
	if(var)
		return "Znaleziono";
	return "Nie znaleziono";
}