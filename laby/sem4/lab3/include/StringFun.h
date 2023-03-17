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
		//constructor of MyString, takes const char *
		MyString(const char * a) : _str(a) {}
		//constructor of MyString, takes MyString *
		MyString(MyString * str) : _str(str->_str) {}
		//overloaded new operator
		void * operator new(size_t size)
		{
		std::cout << "[MyString] Overloading new operator with size: " << size << '\n'; 
		return malloc(size);
		}
		//overloaded delete operator
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
 * @brief functor checking which string is first in ascending alphabetical order
 * 
 */
class Less
{
	public:
		Less() {}
		bool operator()(const MyString a, const MyString b) const {return a>b ? true : false;}


};
/**
 * @brief functor checking which string is first in descending alphabetical order
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
		//constructor of MyStringContainer
		MyStringContainer() {}
		//copy constructor of MyStringContainer
		MyStringContainer(const MyStringContainer &container) 
        {
            for(auto x : container._str_vector)
            {
                MyString * temp = new MyString(x);
                _str_vector.push_back(temp);
            }
        }
		//destructor of MyStringContainer
		~MyStringContainer() 
		{
			for(auto x : _str_vector)
			{
				delete x;
			}
		}
		//method adding a pointer to a vector _str_vector of MyString *
		void AddMStr(MyString * pointer) {_str_vector.push_back(pointer);}
		//method creating a MyString object and adding its pointer to a vector of MyString *
		void AddMStr(const char * string) {_str_vector.push_back(new MyString(string));}
		//method sorting _str_vector in given order
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
		//static method returning vector of functors
		static std::vector<std::function<bool(const MyString, const MyString)>> SortFunc() {return _fun;}

};

std::vector<std::function<bool(const MyString a, const MyString b)>> MyStringContainer::_fun = {Less(), Greater()};

//function printing vector of MyStrings
void PrintNames(const std::vector<MyString> vec)
{
	for(const MyString a : vec)
	{
		std::cout << a.str() << ' ';
	}
	std::cout << "\n";

}