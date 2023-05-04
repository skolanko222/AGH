#include <vector>
#include <iostream>

#include "any.h"


template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, const std::pair<T1, T2>& p)
{
	return o << "[" << p.first << ", " << p.second << "]";
}

int main()
{
  std::vector<any> v;

  v.push_back(1);
  v.push_back(std::make_pair(1,2));
  v.push_back(std::make_pair(std::make_pair(1,2), 2));
  v.push_back(std::vector<any>());


  std::cout << any_cast<int>(v[0]) << std::endl;
  std::cout << any_cast<std::pair<int, int>>(v[1]) << std::endl;
  std::cout << any_cast<std::pair<std::pair<int, int>, int>>(v[2]) << std::endl;
  
}
