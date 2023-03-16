#pragma once
#include <string>
#include <vector>
#include <iostream>


class MyString
{
	private:
		std::string _chain;

	public:
		MyString(const char * n) : _chain(n) {}
		void * operator new() {std::cout << "[MyString] Overloading new operator with size:" << sizeof(std::string); }

};