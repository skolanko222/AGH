#include <iostream>
#include <list>

template </* U1 */>
void print_to_if(/* U2 */)
{
	/* U3 */
}


template </* U4 */>
void change( /* U5 */)
{
	/* U6 */
}

/* U7  - f1, f2, f3*/




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
	print_to_if(std::cout << "All", begin(cl2), end(cl2), f1);

	return 0;
}

/* 
standardowe wyjście:
All: 1 2 3 4 5 6 7
Even: 2 4 6
All: 6 5 4 3 2 1 0
*/
