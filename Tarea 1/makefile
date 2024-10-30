FLAGS = -g
#FLAGS = -O2
all: State.o Operation.o Fill.o Empty.o Pour.o  Jug.o HashTable.o Heap.o Main.o

Main.o : main.cpp
	g++ $(FLAGS) -c main.cpp

Operation.o: Operation.h Operation.cpp
	g++ $(FLAGS) -c Operation.cpp

Fill.o : Fill.h Fill.cpp 
	g++ $(FLAGS) -c Fill.cpp

Empty.o : Empty.h Empty.cpp 
	g++ $(FLAGS) -c Empty.cpp

Pour.o : Pour.h Pour.cpp 
	g++ $(FLAGS) -c Pour.cpp

State.o: State.h State.cpp
	g++ $(FLAGS) -c State.cpp

Jug.o: Jug.h Jug.cpp
	g++ $(FLAGS) -c Jug.cpp

HashTable.o: HashTable.h HashTable.cpp
	g++ $(FLAGS) -c HashTable.cpp

Heap.o: Heap.h Heap.cpp
	g++ $(FLAGS) -c Heap.cpp

clean:
	rm -f *.o all
