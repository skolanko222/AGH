#!/bin/bash

# Compile the C++ program
g++ lab9.cpp -lgsl -lgslcblas -lm -O4

# If the compilation is successful, run the program
if [ $? -eq 0 ]; then
	chmod +x a.out
    ./a.out	
else
    echo "Compilation failed."
fi