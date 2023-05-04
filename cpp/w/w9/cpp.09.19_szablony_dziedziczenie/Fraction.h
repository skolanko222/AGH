#ifndef _Fraction_H_
#define _Fraction_H_

#include <exception>
#include <iostream>

namespace OOP {
class Fraction
{
public:
  class MianZero : public std::exception
  {
  public:
    const char *what() const noexcept
    {
      return "mianownik = 0";
    }
  };

  class ReadError : public std::exception
  {
  public:
    const char *what() const noexcept
    {
      return "blad odczytu lub konwersji";
    }
  };

  friend std::ostream &operator<<(std::ostream &o, const Fraction &K)
  {
    o << K._l << '/' << K._m;
    return o;
  }
  friend std::istream &operator>>(std::istream &i, Fraction &K)
  {
    char znak;
    int  l, m;

    i >> l >> znak >> m;

    if (!i || znak != '/')
    {
      i.clear(~std::ios::failbit & std::ios::goodbit);
      i.ignore(255, '\n');
      throw ReadError();
    }

    if (m == 0)
      throw MianZero();

    if (m < 0)
    {
      K._l = -l;
      K._m = -m;
    }
    else
    {
      K._l = l;
      K._m = m;
    }
    return i;
  }

  Fraction(int l = 0, int m = 1) : _l(l), _m(m) {}

  int GetL() const
  {
    return _l;
  }

  int GetM() const
  {
    return _m;
  }

  void SetL(int v)
  {
    _l = v;
  }

  void SetM(int v)
  {
    _m = v;
  }

private:
  int _l;
  int _m;
};

inline bool operator<(const Fraction &a, const Fraction &b)
{
  return (a.GetL() * b.GetM() < a.GetM() * b.GetL()) ? true : false;
}
/////////////////////////////////////////////////////////////////////////
Fraction ReadFraction()
{
  Fraction x;
  bool     error;

  do
  {
    error = false;

    try
    {
      std::cout << "Podaj u³amek = ";
      std::cin >> x;
    }
    catch (const std::exception &e)
    {
      std::cout << "Wyjatek: " << e.what() << std::endl;
      error = true;
    }

  } while (error);

  return x;
}
} // End of namespace OOP

#endif //_Fraction_H_