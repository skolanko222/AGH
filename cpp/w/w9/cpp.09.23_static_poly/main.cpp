// The curiously recurring template pattern (CRTP)
#include <iostream>

template <typename Derived> struct Shape {
  int draw(int a = 0)
  {
    static_cast<Derived *>(this)->draw_impl();
    return 0;
  }

  static void static_func()
  {
    Derived::static_func_impl();
  }
};

struct Square : Shape<Square> {
  void        draw_impl()
  {
    std::cout << "Draw: " << __PRETTY_FUNCTION__ << "\n";
  }

  static void static_func_impl()
  {
    std::cout << "Static: " << __PRETTY_FUNCTION__ << "\n";
  }
};

struct Triangle : Shape<Triangle> {
  void        draw_impl()
  {
    std::cout << "Draw: " << __PRETTY_FUNCTION__ << "\n";
  }

  static void static_func_impl()
  {
    std::cout << "Static: " << __PRETTY_FUNCTION__ << "\n";
  }
};

struct Circle : Shape<Circle> {
  void        draw_impl()
  {
    std::cout << "Draw: " << __PRETTY_FUNCTION__ << "\n";
  }

  static void static_func_impl()
  {
    std::cout << "Static: " << __PRETTY_FUNCTION__ << "\n";
  }
};


template <class T> 
void test(Shape<T>& s){
  s.draw();
  Shape<T>::static_func();
}

template <class T> 
void test(Shape<T>* s){
  s->draw();
  Shape<T>::static_func();
}

int main()
{
  Square s;
  Triangle t;
  Circle c;

  test(s);
  test(t);
  test(c);

  test(&s);
  test(&t);
  test(&c);
}
