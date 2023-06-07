#ifndef _PAIR_H_
#define _PAIR_H_

/**
 * @brief Templated aggregated Pair class stroing pairs of two types of data
 * 
 * @tparam T 
 * @tparam U 
 */
template <typename T, typename U>
struct Pair
{
    /**
     * @brief 
     * 
     * @return T 
     */
    T getX() const { return _x; }
    U getY() const { return _y; }
    T _x;
    U _y;
};

/**
 * @brief Deduction
 * 
 * @tparam T 
 * @tparam U 
 */
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

/**
 * @brief Overloading operator<< for Pair class
 * 
 * @tparam T 
 * @tparam U 
 * @param out 
 * @param z 
 * @return std::ostream& 
 */
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const Pair<T, U>& pair)
{
    return out << pair.getX() << ", " << pair.getY();
}

#endif // _PAIR_H_