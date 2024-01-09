#!/bin/bash

# Compile the C++ program
g++ -O4 lab10.cpp

# If the compilation is successful, run the program
if [ $? -eq 0 ]; then
	chmod +x a.out
    ./a.out
    python3 lab10.py	
else
    echo "Compilation failed."
fi