#include <iostream>

class DynamicArray
{
    private:
        int capacity;
        int * arrPtr;
        int lenght; // from user's perspective
    
    public:
        DynamicArray();
        DynamicArray(int size) 
        :capacity(size),arrPtr(new int [capacity]), lenght(capacity) {};
        ~DynamicArray();
        int size() const;
        void print() const;
        void add(int value, int index);
        inline int get(int index)
        {
            if(index + 1 > lenght)
            {
                std::cout << "Ty" << std::endl;
                return 2137;
            }
            return arrPtr[index];
        }

};