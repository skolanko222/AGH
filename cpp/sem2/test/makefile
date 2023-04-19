lista.exe : main.o lista.o
		gcc -o lista.exe lista.o main.o -Wall
lista.o: lista.c lista.h
		gcc -c -g lista.c -Wall
main.o: main.c lista.h
		gcc -c -g main.c -Wall