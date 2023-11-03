#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
// you can use includes, for example:
#include <algorithm>
using namespace std;
vector<int> solution1(int N, vector<int> &A) {
    
    if(A.empty()) return A;
    vector<int> retVec(N,0);
    int maxVal = 0;
    int treshold = 0;
    for(unsigned i = 0; i < A.size(); i++)
    {
        if(A[i] == N+1)
        {        
            treshold = maxVal;
        }
        else
        {
            retVec[A[i]-1] = max(retVec[A[i]-1],treshold) + 1;
            if(retVec[A[i]-1] > maxVal)
                maxVal = retVec[A[i]-1];
        }
    }
    for_each(retVec.begin(), retVec.end(), [treshold](int& argVal){if(argVal < treshold) argVal = treshold;});
    return retVec;

}
// Write a function:

// int solution(vector<int> &A);

// that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

// For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

// Given A = [1, 2, 3], the function should return 4.

// Given A = [−1, −3], the function should return 1.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array A is an integer within the range [−1,000,000..1,000,000].
int solution2(vector<int> &A)
{
    if(A.empty()) return 1;
    sort(A.begin(), A.end());
    int ret = 1;
    for(unsigned i = 0; i < A.size(); i++)
    {
        if(A[i] > 0)
        {
            if(A[i] == ret)
                ret++;
            else if(A[i] > ret)
                return ret;
        }
    }
    return ret;
}

bool Solution(int x, int y)
{
    map<int,int> xMap;
    map<int,int> yMap;
    while(x > 0)
    {
        xMap[x%10]++;
        x /= 10;
    }
    while(y > 0)
    {
        yMap[y%10]++;
        y /= 10;
    }
    if(xMap == yMap)
        return true;
    else
        return false;
}


int main()
{
	vector<int> A = {3, 4, 4, 6, 1, 4, 4};
	vector<int> retVec = solution1(5,A);
	cout << "\n";
	cout << "\n";

	std::for_each(retVec.begin(), retVec.end(), [](int argVal){std::cout << argVal << ' ';}); 

	return 0;
}