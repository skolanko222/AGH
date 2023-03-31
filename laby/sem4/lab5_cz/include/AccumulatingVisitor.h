#pragma once
#include <iostream>

class Data;
class FloatData;
class IntData;
class Visitor;

class AccumulatingVisitor : public Visitor
{
	public:
		AccumulatingVisitor() : _total_sum(0.) {}
		virtual void visit(const FloatData * obj) const override { const_cast<AccumulatingVisitor*>(this)->_total_sum += obj->getValue();}
		virtual void visit(const IntData * obj) const override { const_cast<AccumulatingVisitor*>(this)->_total_sum += obj->get();}
		double getTotalSum() {return _total_sum;}

	private:
		double _total_sum ;


};