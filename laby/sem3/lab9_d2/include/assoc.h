#pragma once

#include <iostream>

class Element
{
friend class Assoc;
private:
	Element(const std::string key="",double val=0): _key{key}, _val{val} {}
	std::string _key;
	double _val;
};

class Assoc
{
public:
	Assoc(int len=0);
	Assoc(const Assoc &to_copy);
	Assoc(Assoc &&to_move);
	~Assoc();
	void insert(const std::string key,double val);
	void print(const std::string str) const;
	double &operator[](const std::string key);
	double &operator[](const std::string key) const;
	Assoc &operator=(const Assoc &to_assign);
	bool contains(const std::string key) const;
private:
	int _len;
	Element *_arr;
};

std::string print(bool var);