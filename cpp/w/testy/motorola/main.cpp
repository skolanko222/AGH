#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <memory>
#include <cstring>
#include <set>

/*Write a function:
int solution(vector<int> &A);
that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
Given A = [1, 2, 3], the function should return 4.
Given A = [−1, −3], the function should return 1.
Write an efficient algorithm for the following assumptions:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].*/
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;
// int solution2(int N) {
    
//     int n = N;
//     int counter = 0;
//     int max = 0;
//     while(n != 0 && N > 0)
//     {
//         if((n & 1) == 1)
//         {
//             n >>= 1;
//             counter=0;
//             while((n & 1) == 0 && n != 0)
//             {
//                 n >>= 1;
//                 counter++;
//             }
//             if(counter > max) max = counter;
//         }
//         else {
//             n >>= 1;

//         }
//     }
//     return max;
// }
// int solution3(vector<int> &A) {
//     std::set<int> set;
//     for(auto & i : A)
//     {
//         if(set.find(i) == set.end())
//         {
//             set.emplace(i);
//         }
//         else
//         {
//             set.erase(i);
//         }
//     }
//     return *set.begin();
// }


int main()
{
	//Write a function:
	//int solution(vector<int> &A);
	//that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
	//For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
	//Given A = [1, 2, 3], the function should return 4.
	//Given A = [−1, −3], the function should return 1.
	//Write an efficient algorithm for the following assumptions:

	std::vector<int> A(10,0);
    a.em
	std::for_each(A.begin(), A.end(), [](int argVal){std::cout << argVal << std::endl;});


	return 0;
}