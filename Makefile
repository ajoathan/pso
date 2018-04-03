.PHONY: clean run
.SILENT:

pso: main.cpp pso.o
	g++ -o pso main.cpp pso.o

pso.o: pso.h pso.cpp
	g++ -c -o pso.o pso.cpp

clean:
	rm *.o pso

run: pso
	./pso

