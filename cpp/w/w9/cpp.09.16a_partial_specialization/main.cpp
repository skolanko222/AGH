#include "Printer.h"
#include "Printer2.h"
#include "Fraction.h"

/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;
  using namespace OOP;

  using f_pr = Printer<Fraction>;

  {
    f_pr p(f_pr::value_typu(1, 2), "Normal class template [", "]");
    p.print(cout);
  }
  {
    Printer<Fraction *> p(new Fraction(1, 2), "Specialized class template for __ptr__ [", "]");
    p.print(cout);
  }
  {
    unique_ptr<Fraction> f(new Fraction(1, 2));

    Printer2 p("Normal class with template method [", "]");
    p.print(cout, *f);
    p.print(cout, f.get());
    p.print(cout, f);
  }
}
