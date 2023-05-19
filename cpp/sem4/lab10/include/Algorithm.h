#pragma once
#include <string>
#include <iostream>

template<typename T>
void swap(T & a, T &b)
{
	T c(a);
	a = std::move(b);
	b = std::move(c);
}