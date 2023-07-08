// https://solarianprogrammer.com/2012/10/17/cpp-11-async-tutorial/
// https://github.com/sol-prog/async_tutorial

#include <future>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "helper_func.h"

void make_perlin_noise(int id, int id_width, double z);

/*****************************************************************/
void do_task_serial(int frames, int id_width){
	std::cout << "Function: " << __func__ << "\n";

	for(int id = 0; id <= frames; ++id)
		make_perlin_noise(id, id_width, id / (double) frames);
}

/*****************************************************************/
void do_task_async(int frames, int id_width){
	std::cout << "Function: " << __func__ << "\n";
	
	std::vector<std::future<void>> futures;

	for(int id = 0; id <= frames; ++id)
		futures.push_back(std::async(std::launch::async, make_perlin_noise, id, id_width, id / (double) frames));
	
	for(auto &e : futures)
		e.get();
}

/*****************************************************************/
template<typename T>
auto do_task(T&& f){
// auto do_task(std::function<void(int,int)> f){
	auto start = std::chrono::steady_clock::now();

	f(10, 4);

	auto end = std::chrono::steady_clock::now();
 	auto diff = end - start;
	std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

	return std::chrono::duration <double, std::milli> (diff).count();
}


/*****************************************************************/
int main(int argc, char** argv) {

	auto cores = std::thread::hardware_concurrency();
	std:: cout << "Core count: " <<  cores << "\n";

	auto d1 = do_task(do_task_async);
	auto d2 = do_task(do_task_serial);

	std::cout << "Async time x cores: " << d1 * cores << ", sync time:  " << d2 << "\n";
}
