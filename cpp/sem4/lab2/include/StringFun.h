#pragma once
#include <string>
#include <vector>

/**
 * @brief wrapper for string
 * 
 */
class MyString
{
	private:	
		std::string _str;
	public:
		//constructor
		MyString(const char * a) : _str(a) {}
		//getter of _str
		std::string str() const {return _str;}
		//oveloaded > operator 
		bool operator>(const MyString a) const {return _str < a._str? true : false;}
		//oveloaded < operator 
		bool operator<(const MyString a) const {return _str > a._str? true : false;}
		//returns lenght of _str string
		int lengthMyString() const {return _str.length();}
		

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
/**
 * @brief functor checking which string is longer
 * 
 */
class Length
{
	public:
		Length() {}
		bool operator()(const MyString a, const MyString b) const {return a.lengthMyString()<b.lengthMyString() ? true : false;}


};

/**
 * @brief global function for printing a vector of MyString strings
 * 
 * @param vec 
 */
void PrintNames(const std::vector<MyString> vec)
{
	for(const MyString a : vec)
	{
		std::cout << a.str() << ' ';
	}
	std::cout << "\n\n";

}