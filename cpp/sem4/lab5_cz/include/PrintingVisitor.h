#pragma once

class Data;
class FloatData;
class IntData;
class Visitor;

class PrintingVisitor : public Visitor
{
	public:
		virtual void visit(const FloatData * obj) const override {std::cout << obj->getValue() << ' ';}
		virtual void visit(const IntData * obj) const override {std::cout << obj->get()  << ' ';}
		~PrintingVisitor() { };


};