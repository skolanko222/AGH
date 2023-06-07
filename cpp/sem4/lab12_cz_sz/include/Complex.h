#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include "Pair.h"

/**
 * @brief Templated aggregated class for complex numbers. Derived from Pair class.
 * 
 * @tparam T 
 * @tparam U 
 */
template <typename T, typename U>
struct Complex : public Pair<T,U>
{
    /**
     * @brief Method returning conjugate of complex number
     * 
     * @return Complex<T,U> 
     */
    Complex<T,U> Conjugate() const
    {
        return Complex{this->getX(),-this->getY()};
    }
};

/**
 * @brief Deduction
 * 
 * @tparam T 
 * @tparam U 
 */
template <typename T, typename U>
Complex(T, U) -> Complex<T, U>;

/**
 * @brief Overloading operator<< for Complex class
 * 
 * @tparam T 
 * @tparam U 
 * @param out 
 * @param z 
 * @return std::ostream& 
 */
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const Complex<T, U>& z)
{
    return out << z.getX() << ((z.getY() < 0) ? " - " : " + ") << std::abs(z.getY()) << "i";
}

#endif // _COMPLEX_H_