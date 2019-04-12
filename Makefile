CFLAGS = -Wall -g -std=c++11 #definition de variable

all : main

PolyAbstr.o: code.hpp code.cpp
	g++ $(CFLAGS) -c code.cpp

main: main.cpp code.o
	g++ $(CFLAGS) main.cpp code.o -o main

clean:
	rm -f main code.o
