#include <iostream>

/////////////////////////////////////////////////////////
class DoubleArray
{
public:
  explicit DoubleArray(unsigned n) : m_size(n)
  {
    m_ptr = new double[m_size];
    for (unsigned i = 0; i < m_size; ++i)
      m_ptr[i] = 0.0;
  }

  ~DoubleArray()
  {
    delete[] m_ptr;
  }

  double &operator[](unsigned i)
  {
    if (i >= m_size)
    {
      double * ptr;
      unsigned new_size = i + 1;
      ptr = new double[new_size];

      for (unsigned k = 0; k < m_size; ++k)
        ptr[k] = m_ptr[k];

      for (unsigned k = m_size; k < new_size; ++k)
        ptr[k] = 0.0;

      m_size = new_size;
      delete[] m_ptr;
      m_ptr = ptr;
    }

    return m_ptr[i];
  }

  const double &operator[](unsigned i) const
  {
    return i >= m_size ? m_ptr[m_size - 1] : m_ptr[i];
  }

private:
  double * m_ptr;
  unsigned m_size;
};

/////////////////////////////////////////////////////////
int main()
{
  DoubleArray a(5);

  for (int i = 0; i < 5; ++i)
    a[i] = (i + 1) * 2.2;

  for (int i = 0; i < 10; ++i)
    std::cout << i << ": " << a[i] << std::endl;
}
