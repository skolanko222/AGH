#include <iostream>
#include <list>
#include <functional>

template <typename T>
void print_to_if(std::ostream &stream,  T beg, T end, std::function<bool(int)> t )
{
	for(T it = beg; it != end; ++it)
	{
		if(t(*it))
		{
			stream << *it << " ";
		}
	}
	stream << std::endl;
}
// class f3
// {
// 	private:
// 		int _x;
		
// 	public:
// 		f3(int x) : _x(x) {}
// 		int operator()() const
// 		{
// 			return _x;
// 		}
// };
template <typename T>
T & f3(T & x)
{
	return x;
}
template <typename T, typename U >
void change( T beg, T end, U t)
{
	for(T it = beg; it != end; it++)
	{
		*it += t;
	}
}

bool f1(int x) {return true; }
bool f2(int x) {return x%2 ? false : true; }

int main()
{
	const auto c1 = {1, 2, 3, 4, 5, 6, 7};

	print_to_if(std::cout << "All", begin(c1), end(c1), f1);
	print_to_if(std::cout << "Even", begin(c1), end(c1), f2);
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	print_to_if(std::cout << "Even", std::begin(arr), std::end(arr), f2);

	int add_value{-1}; //należy wykorzystać add_value do zmiany cl2
	std::list<int> cl2{7,6,5,4,3,2,1};
	change(begin(cl2), end(cl2), f3(add_value));
	// goto end;
	print_to_if(std::cout << "All", begin(cl2), end(cl2), f1);

	// end:
	return 0;
}

/* 
standardowe wyjście:
All: 1 2 3 4 5 6 7
Even: 2 4 6
All: 6 5 4 3 2 1 0
*/
