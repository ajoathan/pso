.PHONY: clean run
.SILENT:

pso: pso.o
	g++ -o pso pso.o

pso.o: pso.cpp
	g++ -c -o pso.o pso.cpp

clean:
	rm *.o pso

run: pso
	./pso

