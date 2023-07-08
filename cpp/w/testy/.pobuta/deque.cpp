#include<iostream>
#include<deque>

template<typename T = int, template<typename U = T, typename Allocator = std::allocator<U>> class StorageType = std::deque>
struct fifo{
  using storage_type = StorageType<T>;

  fifo(){
    std::cout<<__PRETTY_FUNCTION__<<"\n";
  }

  void push(int i){
    data.push_back(i);
  }

  T get(){
    T temp = data[0];
    data.pop_front();
    return temp;
  }

  int size(){ return data.size(); } 

  typename storage_type::const_iterator begin(){
    return data.begin();
  }

  typename storage_type::const_iterator end(){
    return data.end();
  }
  
  private:
    StorageType<T> data;
};

int main(){
    fifo<> ft;
    for(int i: {0,1,2,3,4})
        ft.push(i);

    fifo<int, std::deque> f = ft;

    std::cout << f.get();
    std::cout << f.size();

    for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
        std::cout << *i << ",";
}
/*
  Wynik:
  fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
  0
  4
  1,2,3,4,
*/