FLAGS = -Wall -march=native -Ofast -ffast-math
#FLAGS = -O2
all: test_main

test_main: State.o HashTable.o MinHeap.o Operation.o Fill.o Empty.o Pour.o Jug.o
	g++ $(FLAGS) State.o HashTable.o MinHeap.o Operation.o Fill.o Empty.o Pour.o Jug.o main.cpp -o test_main

testHashTable: State.o HashTable.o testHashTable.cpp 
	g++ $(FLAGS) State.o HashTable.o testHashTable.cpp -o testHashTable

testMinHeap: State.o MinHeap.o testMinHeap.cpp
	g++ $(FLAGS) State.o MinHeap.o testMinHeap.cpp -o testMinHeap

testState: State.o testState.cpp
	g++ $(FLAGS) State.o testState.cpp -o testState

testOperation: Operation.o Fill.o Empty.o Pour.o testOperation.cpp
	g++ $(FLAGS) Operation.o Fill.o Empty.o Pour.o testOperation.cpp -o testOperation

State.o: State.h State.cpp
	g++ $(FLAGS) -c State.cpp

HashTable.o: HashTable.h HashTable.cpp
	g++ $(FLAGS) -c HashTable.cpp

Operation.o: Operation.h Operation.cpp
	g++ $(FLAGS) -c Operation.cpp

Fill.o : Fill.h Fill.cpp 
	g++ $(FLAGS) -c Fill.cpp

Empty.o : Empty.h Empty.cpp 
	g++ $(FLAGS) -c Empty.cpp

Pour.o : Pour.h Pour.cpp 
	g++ $(FLAGS) -c Pour.cpp

Jug.o: Jug.h Jug.cpp
	g++ $(FLAGS) -c Jug.cpp

MinHeap.o: MinHeap.h MinHeap.cpp
	g++ $(FLAGS) -c MinHeap.cpp

clean:
	rm -f *.o all
