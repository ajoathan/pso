.PHONY: clean run
.SILENT:

# Variaveis expostas (podem ser sobreescritas)
CXX=g++
CXXFLAGS=--std=c++11 -g -Og

# Variaveis internas (usadas para organizacao)
override BUILD=$(CXX) $(CXXFLAGS)
override COMPILE=$(CXX) -c $(CXXFLAGS)

pso: main.cpp pso.o
	$(BUILD) -o pso main.cpp pso.o

pso.o: pso.h pso.cpp
	$(COMPILE) -o pso.o pso.cpp

clean:
	rm *.o pso

run: pso
	./pso

