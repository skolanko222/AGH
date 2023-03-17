#pragma once
#include <iostream>
#include <functional>
#include <string>
#include <vector>

class MyString
{
	private:	
		std::string _str;
	public:
		//constructor
		MyString(const char * a) : _str(a) {}
		MyString(MyString * str) : _str(str->_str) {}
		
		void * operator new(size_t size)
		{
	std::cout << "[MyString] Overloading new operator with size: " << size << '\n'; 
	return malloc(size);
}

		void operator delete(void* temp)
		{
			std::cout << "[MyString] Overloading delete operator\n";
			free(temp);
		}
		//getter of _str
		std::string str() const {return _str;}
		//oveloaded > operator 
		bool operator>(const MyString a) const {return _str < a._str? true : false;}
		//oveloaded < operator 
		bool operator<(const MyString a) const {return _str > a._str? true : false;}
		

};
/**
 * @brief functor checking if string is first in ascending alphabetical order
 * 
 */
class Less
{
	public:
		Less() {}
		bool operator()(const MyString a, const MyString b) const {return a>b ? true : false;}


};
/**
 * @brief functor checking if string is first in descending alphabetical order
 * 
 */

class Greater
{
	public:
		Greater() {}
		bool operator()(const MyString a, const MyString b) const {return a<b ? true : false;}


};
class MyStringContainer
{
	private:
		std::vector<MyString *> _str_vector;
		static std::vector<std::function<bool(const MyString a, const MyString b)>> _fun;
	public:
		MyStringContainer() {}
		MyStringContainer(const MyStringContainer &container) 
        {
            for(auto x : container._str_vector)
            {
                MyString * temp = new MyString(x);
                _str_vector.push_back(temp);
            }
        }
		~MyStringContainer() 
		{
			for(auto x : _str_vector)
			{
				delete x;
			}
		}
		void AddMStr(MyString * pointer) {_str_vector.push_back(pointer);}
		void AddMStr(const char * string) {_str_vector.push_back(new MyString(string));}
		std::vector<MyString> GetSorted(std::string option) 
		{
			//std::cout << __PRETTY_FUNCTION__ << "\n";
			std::vector<MyString> temp(_str_vector.begin(),_str_vector.end());
			if(option == "ASC")
			{
				std::sort(temp.begin(),temp.end(),_fun[0]);
				
			}
			else
			std::sort(temp.begin(),temp.end(),_fun[1]);
			return temp;
		}
		static std::vector<std::function<bool(const MyString, const MyString)>> SortFunc() {return _fun;}

};

std::vector<std::function<bool(const MyString a, const MyString b)>> MyStringContainer::_fun = {Less(), Greater()};



void PrintNames(const std::vector<MyString> vec)
{
	for(const MyString a : vec)
	{
		std::cout << a.str() << ' ';
	}
	std::cout << "\n";

}