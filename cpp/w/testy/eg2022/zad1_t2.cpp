#include<iostream>

using namespace std;
#define f cout << __PRETTY_FUNCTION__ << ": _a=" << _a << " b="<<_b<< endl;

struct A
{
	A() : A(0,0) {f}
	A(int a, int b) : _a(a), _b(b){f}
	explicit A(int a) : A(a,0) {f}
	A(const A && o) : _a(o._a), _b(o._b){f}
	A(const A & o) = delete;

	private:
		int _a;
		int _b;

};

int main()
{
    cout << "a->"; A a;
    cout << "b->"; A b(1);
    cout << "c->"; A c(1,2);

    cout << "d->"; A d = std::move(c);

    // A e = c;
    // A f = 1;
}
/*
a-> A::A(int,int): _a=0,_b=0
A::A(): _a=0,_b=0
b-> A::A(int,int): _a=1,_b=0
A::A(int): _a=1,_b=0
c-> A::A(int,int): _a=1,_b=2
d-> A::[...]: _a=1,_b=2
*/