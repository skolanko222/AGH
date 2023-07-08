#include <future>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "../type.hpp"

/*****************************************************************/
int main(int argc, char** argv) {

  auto lmb = [](int a, int b){ int sum = 0; for(int i = a; i < b; ++i){ sum += i; } return sum; };

  std::future<int> f1 = std::async(std::launch::async, lmb,       0, 1000000000);
  auto f2             = std::async(std::launch::async, lmb,   -1000, 1000000000);
  auto f3             = std::async(std::launch::async, lmb,    1000, 1000000000);


	std::cout << type(f1) << "\n";
	std::cout << type(f2) << "\n";
	std::cout << "Waiting..." << std::flush;

  f1.wait();
  f2.wait();
  f3.wait();

  auto sum = f1.get() + f2.get() + f3.get();

  std::cout << "Done!\nSum: " << sum << '\n';

}
