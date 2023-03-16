#include <iostream>
#include <vector>

/////////////////////////////////////////////////////////
class NewTest
{
public:
  static void *operator new(size_t size)
  {
    std::cout << "In overloaded new.\n";
    void *p = malloc(size);

    return p;
  }
  static void operator delete(void *p)
  {
    std::cout << "In overloaded delete.\n";
    free(p);
  }

  static void *operator new[](size_t size)
  {
    std::cout << "In overloaded new[].\n";
    void *p = malloc(size);

    return p;
  }
  static void operator delete[](void *p)
  {
    std::cout << "In overloaded delete[].\n";
    free(p);
  }
};

/////////////////////////////////////////////////////////
int main()
{
  NewTest *ptr = new NewTest;
  delete ptr;

  NewTest *ptr_tab = new NewTest[10];
  delete[] ptr_tab;

  int *p1 = new int;
  delete p1;

  int *p2 = new int[10];
  delete[] p2;
}
