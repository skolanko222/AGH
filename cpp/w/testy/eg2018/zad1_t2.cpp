namespace std {class auto_ptr{}; class unique_ptr{}; class shared_ptr{} ; }
#include <iostream>
struct A { int i = 1; };
template<typename T>
class ptr
{
	T * data;
	public:
		ptr(T * p ) : data(p) {}
		ptr() : data(new A) {}
		ptr(const ptr & a) = delete;
		ptr & operator=(const ptr & a) const = delete;
		T & operator*() const {return *data;}
		T * operator->() const {return data;}
		// int operator==(const ptr<T>  &a) const
		// {
		// 	return 0;
		// }
		// int operator!=(const ptr<T> &a) const
		// {
		// 	return 1;
		// }


};

int operator==(const ptr<A> & a, const ptr<A> & b) 
{
	return a->i < b->i ? 1 : 0;
}
int operator!=(const ptr<A> & a, const ptr<A> & b) 
{
	return a->i < b->i ? 0 : 1;
}


int main() {
	const ptr<A>  a(new A);
	const ptr<A> b;
	ptr<A> c(new A);

	// ptr<A>  _b_error = new A;      // Odkomentowanie powoduje błąd kompilacji 
	// a = a; 			  // Odkomentowanie powoduje błąd kompilacji 
	// const ptr<A> _c_error = a;     // Odkomentowanie powoduje błąd kompilacji 

	std::cout << ((*a).i, a->i)        << " " << ++c->i << " ";
	std::cout << (a == ptr<A>() ) << " " << (a != b) << " ";
}
/* output/wyjście:
1 2 0 1
*/ 
