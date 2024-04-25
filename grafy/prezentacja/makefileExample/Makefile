# create makefile for this project

# define the compiler

CC = g++

# define the compiler flags

CFLAGS = -c -Wall

# define the target

TARGET = main.exe

# w include/ znajduje się A.h i B.h i C.h. Plik A.h ma w sobie include "B.h" zaś plik
# "C.h" ma w sobie include "A.h". W związku z tym, że pliki są ze sobą powiązane
# to w makefile'u musimy podać ścieżki do plików nagłówkowych. W przeciwnym razie

# define the include path

INCLUDE = -I include/

$(TARGET): A1.o A2.o B.o C.o main.o
	$(CC) A1.o A2.o B.o C.o main.o -o $(TARGET)
A1.o: src/A1.c include/A.h
	$(CC) -c -o A1.o $(CFLAGS) $(INCLUDE) src/A1.c
A2.o: src/A2.c include/A.h 
	$(CC) -c -o A2.o $(CFLAGS) $(INCLUDE) src/A2.c
B.o: src/B.c include/B.h 
	$(CC) $(CFLAGS) $(INCLUDE) src/B.c 
C.o: src/C.c include/C.h 
	$(CC) $(CFLAGS) $(INCLUDE) src/C.c
main.o: main.c include/A.h include/B.h include/C.h
	$(CC) $(CFLAGS) $(INCLUDE) main.c



clean:	
	rm -rf *.o $(TARGET)