#include <iostream>
#include <random>
#include <chrono>



int main(void)
{
	static std::random_device entropy;
	static std::mt19937 randGen(entropy());
	auto start = std::chrono::high_resolution_clock::now();		std::uniform_int_distribution<int> intDistribution(0,99);
	for(auto i = 0; i < 1'000'000'000; i++)
	{
		volatile auto r = intDistribution(randGen);
	}
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
	std::cout << duration.count() << std::endl;
	return 0;
}