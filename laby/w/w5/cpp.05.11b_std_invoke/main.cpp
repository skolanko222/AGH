
#include <functional>
#include <iostream>
 
struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    void print_sub(int i) const { std::cout << num_-i << '\n'; }
    int num_;
};
 
void print_num(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};
 
int main()
{
    // invoke a free function
    std::invoke(print_num, -9);
 
    // invoke a lambda
    std::invoke([]() { print_num(42); });
 
    // invoke a member function
    const Foo foo(10);
    std::invoke(&Foo::print_add, foo, 1);
 
    // invoke (access) a data member
    std::cout << "num_: " << std::invoke(&Foo::num_, foo) << '\n';
 
    // invoke a function object
    std::invoke(PrintNum{}, 18);

    // invoke pointer to member function
    void (Foo::*mf_ptr)(int) const = &Foo::print_add;
    std::invoke(mf_ptr, foo, 5);
    
    // invoke pointer to member function
    mf_ptr = &Foo::print_sub;
    std::invoke(mf_ptr, foo, 5);

}
