#ifndef _CFRACTION_H_
#define _CFRACTION_H_

#ifdef _WIN32
#pragma warning(disable : 4290)
#endif

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
    o << K.m_l << '/' << K.m_m;
    return o;
  }
  friend std::istream &operator>>(std::istream &i,
                                  Fraction &    K)
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
      K.m_l = -l;
      K.m_m = -m;
    }
    else
    {
      K.m_l = l;
      K.m_m = m;
    }
    return i;
  }

  Fraction(int l = 0, int m = 1) : m_l(l), m_m(m)
  {
  }

  int GetL() const
  {
    return m_l;
  }

  int GetM() const
  {
    return m_m;
  }

  void SetL(int l)
  {
    m_l = l;
  }

  void SetM(int m)
  {
    m_m = m;
  }

private:
  int m_l;
  int m_m;
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

#endif //_CFRACTION_H_