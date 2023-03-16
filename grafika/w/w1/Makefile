LIBS=-lsfml-graphics -lsfml-window -lsfml-system
name =01-Okno
all: $(name)

$(name).o: $(name).cpp
	g++ -c $(name).cpp -o $(name).o

$(name): $(name).o
	g++ -o $(name) $(name).o $(LIBS)
