#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

#include "StringFun.h"
class MyString
{
	private:
		std::string _str;

	public:
		MyString(const char * n) : _str(n) {/*std::cout << "Konstruktor MyString: " << n << "\n";*/}
		MyString(MyString * str) : _str(str->_str) {}
		void * operator new(size_t size) 
		{
			std::cout << "[MyString] Overloading new operator with size: " << sizeof(MyString) << '\n'; 
			return malloc(sizeof(MyString));
		}
		//getter of _str
		std::string str() const {return _str;}
		//oveloaded > operator 
		bool operator>(const MyString a) const {return _str < a._str? true : false;}
		//oveloaded < operator 
		bool operator<(const MyString a) const {return _str > a._str? true : false;}
		//returns lenght of _str string
		void operator delete(void* temp)
		{
			std::cout << "[MyString] Overloading delete operator\n";
			free(temp);
		}

};

/**
 * @brief functor checking if string is first in ascending alphabetical order
 * 
 */
class Less
{
	public:
		bool operator()(const MyString a, const MyString b) const {return a>b ? true : false;}


};
/**
 * @brief functor checking if string is first in descending alphabetical order
 * 
 */

class Greater
{
	public:
		bool operator()(const MyString a, const MyString b) const {return a<b ? true : false;}


};

class MyStringContainer
{
	private:
		std::vector<MyString *> _ptr_vector;
		std::vector<std::function<bool(const MyString, const MyString)>> _fun = {Less(), Greater()};

	public:
		MyStringContainer() {}
	 	MyStringContainer(const MyStringContainer &container)
        {
            for(auto x : container._ptr_vector)
            {
                MyString * temp = new MyString(x);
                _ptr_vector.push_back(temp);
            }
        }
		void AddMStr(MyString * pointer) {_ptr_vector.push_back(pointer);}
		void AddMStr(const char * string) {_ptr_vector.push_back(new MyString(string));}

		std::vector<MyString> GetSorted(std::string option) 
		{
			std::vector<MyString> temp(_ptr_vector.begin(),_ptr_vector.end());
			if(option == "ASC")
			{
				std::sort(temp.begin(),temp.end(),_fun[0]);
				
			}
			else
				std::sort(temp.begin(),temp.end(),_fun[1]);
			return temp;
		}
		std::vector<std::function<bool(const MyString, const MyString)>> SortFunc() {return _fun;}
		~MyStringContainer()
        {
            for(auto x : _ptr_vector)
            {
                delete x;
            }
        } 
};

void PrintNames(const std::vector<MyString> vec)
{
	for(const MyString a : vec)
	{
		std::cout << a.str() << ' ';
	}
	std::cout << "\n\n";

}