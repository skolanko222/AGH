#pragma once

class Data;
class FloatData;
class IntData;

class Visitor
{
	public:
		virtual void visit(const FloatData * obj) const = 0;
		virtual void visit(const IntData * obj) const = 0;
		virtual ~Visitor() {};

};