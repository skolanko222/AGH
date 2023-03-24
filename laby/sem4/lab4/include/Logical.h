#pragma once
class TwoArg
{
	public:
		//metoda czysto virtualna
		bool virtual result(bool a, bool b) const = 0;
	
};
class OneArg
{
	public:
		//metoda czysto virtualna
		bool virtual result(bool a) const = 0;
	
};
class OR : public TwoArg
{
	public:
		//metoda zwracajaca logiczna alternatywe argumentow
		bool virtual result(bool a, bool b) const {return a || b;}
};
class AND : public TwoArg
{
	public:
		//metoda zwracajaca logiczna koniunkcje argumentow
		bool virtual result(bool a, bool b) const {return a && b;}
};
class NOT : public OneArg
{
	public:
		//metoda zwracajaca negacje argumentu
		bool virtual result(bool a) const {return !a;}
};
namespace Logical
{
	//globalne funkcje ktora wywoluja odpowiednie funkcje virtualne
	bool eval(const TwoArg& obj, bool a, bool b) {return obj.result(a,b);}
	bool eval(const OneArg& obj, bool a) {return obj.result(a);}
};