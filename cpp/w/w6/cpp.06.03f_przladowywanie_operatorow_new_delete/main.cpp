#include <iostream>
#include <vector>

/////////////////////////////////////////////////////////
void *operator new(std::size_t sz)
{
  std::cout << "Global op new called, size = " << sz << std::endl;
  return std::malloc(sz);
}
void operator delete(void *ptr) noexcept
{
  std::cout << "Global op delete called" << std::endl;
  std::free(ptr);
}

/////////////////////////////////////////////////////////
class NewTest
{
public:
  static void *operator new(size_t size)
  {
    std::cout << "  >--NewTest--< In overloaded new.\n";
    void *p = ::operator new(size);

    return p;
  }
  static void operator delete(void *p)
  {
    std::cout << "  >--NewTest--< In overloaded delete.\n";
    ::operator delete(p);
  }

  static void *operator new[](size_t size)
  {
    std::cout << "  >--NewTest--< In overloaded new[].\n";
    void *p = ::operator new(size);

    return p;
  }
  static void operator delete[](void *p)
  {
    std::cout << "  >--NewTest--< In overloaded delete[].\n";
    ::operator delete(p);
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
