#pragma once
#include "Data.h"

class List
{
	private:
		Data * _data;
		List * _next;
	public:
		enum side {Begin, End};
		List(Data * d = nullptr, List * n = nullptr ) : _data(d), _next(n) {}
		List(List & obj);
		~List();
		List & insert(const IntData &obj, side where = End);
		List & insert(const StringData &obj, side where = End);
		void print();
};