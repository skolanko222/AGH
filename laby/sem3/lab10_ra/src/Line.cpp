#include "Line.h"

LArray::~LArray(){
    delete [] _array;
}

Line& LArray::operator[](unsigned int index)
{
    if(index<0 || index >_size ){
        std::cout << "No element on index "<< index << ". Out Of Bounds Exception."<< std::endl; 
        exit (0);
    }
    return _array[index];
}