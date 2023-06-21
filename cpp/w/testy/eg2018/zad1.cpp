#include <iostream>
#include <vector>

class Base
{
	public:
		virtual std::ostream& print(std::ostream&) const = 0;
		virtual ~Base() = default;
};
class Derived1 : public Base
{
	public:
		std::ostream& print(std::ostream& out) const override
		{
			return out << __PRETTY_FUNCTION__;
		}
};
class Derived2 : public Base
{
	public:
		std::ostream& print(std::ostream& out) const override
		{
			return out << __PRETTY_FUNCTION__;
		}
		// Derived2(const Derived2&) = default;
};
class Derived3 : public Derived2
{
	public:
		std::ostream& print(std::ostream& out) const override
		{
			return out << __PRETTY_FUNCTION__;
		}
};
std::ostream& operator<<(std::ostream& out, const Base& b)
{
	return b.print(out);
}
std::ostream& operator<<(std::ostream& out, const std::vector<Base*> & v)
{
	out << "[\n";
	for (const auto& b : v)
		out << *b << ",\n";
	return out << "]";
}

int main()
{
    Derived1 d1;
    Derived3 d3;
    Derived2 d2 = d3;
    // Derived1 d1_make_err = d2;

    // std::vector<Base> v_make_err = {d1, d2, d3};
    std::vector<Base*> v = {&d1, &d2, &d3};

    std::cout << *v.front()<<std::endl;
    std::cout << v;
}


// virtual std::ostream& Derived1::print(std::ostream&) const
// [
// virtual std::ostream& Derived1::print(std::ostream&) const,
// virtual std::ostream& Derived2::print(std::ostream&) const,
// virtual std::ostream& Derived3::print(std::ostream&) const
// ]
