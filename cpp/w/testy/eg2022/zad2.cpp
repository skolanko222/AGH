#include <iostream>
#include <list>
#include <functional>

template <typename T = int>
void print_to_if(std::ostream &stream, const T * beg, const T * end,std::function<bool(int)> t )
{
	for(const T * it = beg; it != end; ++it)
	{
		if(t(*it))
		{
			stream << *it << " ";
		}
	}
}


template <typename T = std::list<int>::iterator>
void change( T beg, T end, std::function<int()> t)
{
	for(T it = beg; it != end; it++)
	{
		*it += t();
	}
}

bool f1(int x) {return true; }
bool f2(int x) {return x%2 ? false : true; }
class f3
{
	private:
		int _x;
	public:
		f3(int x) : _x(x) {}
		int operator()() const
		{
			return _x;
		}
};



int main()
{
	const auto c1 = {1, 2, 3, 4, 5};

	print_to_if(std::cout << "All", begin(c1), end(c1), f1);
	print_to_if(std::cout << "Even", begin(c1), end(c1), f2);

	int add_value{-1}; //należy wykorzystać add_value do zmiany cl2
	std::list<int> cl2{7,6,5,4,3,2,1};
	change(begin(cl2), end(cl2), f3(add_value));
	
	print_to_if(std::cout << "All", begin(cl2), end(cl2), f1);

}

/* 
standardowe wyjście:
All: 1 2 3 4 5 6 7
Even: 2 4 6
All: 6 5 4 3 2 1 0
*/
