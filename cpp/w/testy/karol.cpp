/*
 Celem zadania jest przećwiczenie szablonowych parametrów szablonów.
 Jednym z zastosowań szablonowych parametrów szablonów jest "policy-based design",
 w którym tworzymy klasy tzw. policies odpowiadające za konkretne zachowanie i
 które będą podawane jako parametry szablonu. 
 To podejście pozwala na wybór konkretnego rozwiązania na etapie kompilacji. 
 
 Poniżej są zaimplentowane 2 klasy-policies, realizujące 2 rodzaje sortowania.
 Proszę napisać klasę szablonową Sorter, która przyjmuje jako parametry szablonu 
 typ danych oraz politykę/taktykę sortowania. Posiada ona funkcję sort, która 
 sortuje klasę szablonową NumArray w zależności od podanej polityki.
 
 */
 
#include <iostream>
#include <vector>
#include <algorithm>



// Sorting policy using IntroSort algorithm
template <typename T>
struct IntroSorter {
    static void sort(std::vector<T>& data) {
        std::sort(data.begin(), data.end());
        std::cout << "[IntroSorter] Sorting using IntroSort algorithm." << std::endl;
    }
};

// Sorting policy using BubbleSort algorithm
template <typename T>
struct BubbleSorter {
    static void sort(std::vector<T>& data) {
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (size_t i = 0; i < data.size() - 1; ++i) {
                if (data[i] > data[i + 1]) {
                    std::swap(data[i], data[i + 1]);
                    sorted = false;
                }
            }
        }
        std::cout << "[BubbleSorter] Sorting using BubbleSort algorithm." << std::endl;
    }
};

struct IntWrapper{
	int _val;
	IntWrapper(int a):_val(a){}
};

template<typename T>
void print(const std::vector<T> & data){
    for(const auto & el : data){
        std::cout << el << "\t";
    }
}

template<typename T, template<typename U=T> class SortingPolicy>
class Sorter{
    public:
    void sort(std::vector<T> & data){
        SortingPolicy<T>::sort(data);
    }
    private:
        SortingPolicy<T> sort_type;
};

int main(){
    std::vector<int> ints{5, 2, 8, 1, 4};
    print(ints);

    Sorter<int, IntroSorter> introSorter;
    introSorter.sort(ints);  // Sort using IntroSort algorithm

    print(ints);
    
    std::vector<double> doubles{0.5, 1.2, -1.5, 2.4, 10.2, -4.0};
    print(doubles);
    
    Sorter<double, BubbleSorter> bubbleSorter;
    bubbleSorter.sort(doubles);  // Sort using BubbleSort algorithm
    print(doubles);
        
    return 0;
}
/*
5	2	8	1	4	
[IntroSorter] Sorting using IntroSort algorithm.
1	2	4	5	8	
0.5	1.2	-1.5	2.4	10.2	-4	
[BubbleSorter] Sorting using BubbleSort algorithm.
-4	-1.5	0.5	1.2	2.4	10.2	
*/