#pragma once

#include <string>

class Named
{
	private:
		std::string _name;
	public:
		Named(std::string n = "None") : _name(n) {};
		std::string Name() const {return _name;}
		void setName(std::string n) {_name = n;}


};

std::string operator>>(std::string n, Named &obj);