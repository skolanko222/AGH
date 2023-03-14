LIBS=-lsfml-system -lsfml-graphics -lsfml-window

name=main

all: $(name)

$(name).o: $(name).cpp
	g++ -std=c++17 -c $(name).cpp -o $(name).o

$(name): $(name).o
	@echo "** Jazda"
	g++ -std=c++17 -o $(name).exe $(name).o $(LIBS)
