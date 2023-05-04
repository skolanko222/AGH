#include "Fraction.h"
#include "OOPFunTemplates.h"
#include <cstring>
#include <exception>
#include <iostream>
#include <string>

namespace OOP {
/////////////////////////////////////////////////////////////////////////
template <typename T> class BoxOpis
{
public:
  void SetT(const T &obj)
  {
    box = obj;
  }

  void SetOpis(const std::string opis)
  {
    this->opis = opis;
  }

  T GetT() const
  {
    return box;
  }

  std::string GetOpis() const
  {
    return opis;
  }

private:
  T           box;
  std::string opis;
};
/////////////////////////////////////////////////////////////////////////
template <typename T>
std::ostream &operator<<(std::ostream &o, const BoxOpis<T> &K)
{
  o << K.GetOpis().c_str() << ": " << K.GetT();
  return o;
}

/////////////////////////////////////////////////////////////////////////
template <> class BoxOpis<char *>
{
public:
  BoxOpis()
  {
    box = new char[1];
    box[0] = '\0';
  }

  ~BoxOpis()
  {
    delete[] box;
  }

  void SetT(const char *obj)
  {
    if (strlen(box) < strlen(obj))
    {
      delete[] box;
      box = new char[strlen(obj) + 1];
    }
    strcpy(box, obj);
  }

  void SetOpis(const std::string opis)
  {
    this->opis = opis;
  }

  char *GetT() const
  {
    char *copy = new char[strlen(box) + 1];
    strcpy(copy, box);
    return copy;
  }

  std::string GetOpis() const
  {
    return opis;
  }

private:
  char *      box;
  std::string opis;
};
/////////////////////////////////////////////////////////////////////////
std::ostream &operator<<(std::ostream &o, const BoxOpis<char *> &K)
{
  char *tmp = K.GetT();
  o << K.GetOpis().c_str();
  o << ": ";
  o << tmp;
  delete[] tmp;
  return o;
}

} // End of namespace

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;

  OOP::BoxOpis<char *> a;

  a.SetT("Zmienna");
  a.SetOpis("char*");

  cout << a << endl;

  OOP::BoxOpis<OOP::Fraction> aFrac;
  aFrac.SetT(OOP::Fraction(2, 3));
  aFrac.SetOpis("Ulamek");

  cout << aFrac << endl;
}
