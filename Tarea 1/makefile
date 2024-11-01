FLAGS = -g
#FLAGS = -O2
all: test_main

test_main: State.o HashTable.o Heap.o Operation.o Fill.o Empty.o Pour.o Jug.o
	g++ $(FLAGS) State.o HashTable.o Heap.o Operation.o Fill.o Empty.o Pour.o Jug.o main.cpp -o test_main

State.o: State.h State.cpp
	g++ $(FLAGS) -c State.cpp

HashTable.o: HashTable.h HashTable.cpp
	g++ $(FLAGS) -c HashTable.cpp

Heap.o: Heap.h Heap.cpp
	g++ $(FLAGS) -c Heap.cpp

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

clean:
	rm -f *.o all
