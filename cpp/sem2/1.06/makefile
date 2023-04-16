cycle_main.exe: cycle_main.o cycle.o
		gcc -o lista.exe  cycle.o cycle_main.o -Wall
cycle.o: cycle.c cycle.h
		gcc -c -g cycle.c -Wall
main.o: cycle_main.c cycle.h
		gcc -c -g cycle_main.h -Wall
