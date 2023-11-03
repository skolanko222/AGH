#include <iostream>
#include <functional>
template <typename T,typename L >
void my_for_each(T first,T last,L fun)
{
    for (T it = first; it != last; ++it )
    {
        fun(*it);
    }
}

int main()
{
    using namespace std;
    int c[] = {1,2,3,4,5};

    std::function<void(int)> print= [](int el){std::cout<< el<<" ";};
    auto print_eol= [](){std::cout<<endl;};
    my_for_each(begin(c),end(c),print); print_eol();

    int add_value = 1;
    auto add = [&](int & el){el+=add_value;};;
    my_for_each(begin(c),end(c),add);
    my_for_each(begin(c),end(c),print); print_eol();

    add_value = 10;
    my_for_each(begin(c),end(c),add);
    my_for_each(begin(c),end(c),print); print_eol();
}
