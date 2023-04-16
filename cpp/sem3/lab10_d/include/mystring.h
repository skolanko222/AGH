#pragma once
#include <iostream>

int size(const char * n)
	{
		int i = 0;
		int counter = 0;
		while(*(n + i) != '\0'){
			counter++;
			i++;
		}
		return counter;
	}

namespace mystring{
	class String
	{
		private:
			char * _napis;
			int _size;
		
		public:
			String(char * n) 
			{
				int counter = ::size(n);
				_size = counter;
				_napis = new char [_size];
				_napis = n;
			}
			String(const String &n) : String(n._napis) {}
			String(const String &&n) {}
			~String() {delete [] _napis;}
			void print(const char * prt) const {
				std::cout << prt << " " << _napis << "\n";
			}
			bool operator ==(const char *n) const{
				int size = ::size(n);
				for(int i = 0; i < size; i++)
				{
					if(*(n+i) != *(_napis+i))
						return false;
				}
				return true;
			}
			bool operator ==(const String &n) const{
				
				return _napis == n._napis ? true : false;
			}
			String & operator=(char *n) {
				if(this->_napis == n)
					return *this;
				String temp(n);
				return temp;
			}
			char * getNapis() const{return _napis;}
			String & operator+(const String &n) const{}
			String & operator+(const char *n) const{}
			String & operator+(const char c) const{}
	};
	std::ostream &operator<<(std::ostream &o,const String &n);
	String & operator*(int i,const String & n) {}

}