#include <iostream>
#include <vector>
#include <memory>

//zaimplementuj potrzebne klasy (Base,Derived) tak aby przedstawiony kody wykonywał się poprawnie.
//Lista ma przyjmować elementy dowolnego typu
//metoda print ma wypisać elementy klasy List w kolejnych wierszach
class Base{
    public:
    virtual void print()const = 0;
    virtual ~Base() = default;
};
template <typename T>
class Derived: public Base{
    T obj;
    public:
    Derived(const T &o): obj{o} {}
    void print()const override{
        std::cout<<obj<<std::endl;
    }
};

class List{
    std::vector<std::unique_ptr<Base>> v;
    public:
    template <typename T>
    void add(const T &o){
        v.push_back(std::make_unique<Derived<T>>(o));
    }
    void print()const{
        for(auto &i : v){
            i->print();
        }
    }
};
int main(){
    List l;
    l.add<int>(10);
    l.add<float>(5.7);
    l.print();
}





































