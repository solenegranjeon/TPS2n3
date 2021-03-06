all: main

main: main.o DLA.o ImagePPM.o CellularAutomaton.o
	g++ main.o DLA.o ImagePPM.o CellularAutomaton.o -o main -g
	
main.o: main.cpp DLA.h ImagePPM.h CellularAutomaton.h
	g++ -c main.cpp -o main.o -std=c++11 -g
	
DLA.o: DLA.cpp DLA.h ImagePPM.h
	g++ -c DLA.cpp -o DLA.o -std=c++11 -g
	
CellularAutomaton.o: CellularAutomaton.cpp CellularAutomaton.h ImagePPM.h
	g++ -c CellularAutomaton.cpp -o CellularAutomaton.o -std=c++11 -g
	
ImagePPM.o: ImagePPM.cpp ImagePPM.h
	g++ -c ImagePPM.cpp -o ImagePPM.o -std=c++11 -g
	
clean:
	rm *.o


