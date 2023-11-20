#!/bin/bash

# Compile the C++ program
g++ -O4 --std=c++17 lab4.cpp

# If the compilation is successful, run the program
if [ $? -eq 0 ]; then
	chmod +x a.out
    ./a.out	
else
    echo "Compilation failed."
fi