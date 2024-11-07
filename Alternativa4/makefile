FLAGS = -pg -Wall -march=native -Ofast -ffast-math

all: test_main

test_main: State.o AVLNode.o AVLTree.o HashTable.o PriorityQueue.o Operation.o Fill.o Empty.o Pour.o Jug.o
	g++ $(FLAGS) State.o AVLNode.o AVLTree.o HashTable.o PriorityQueue.o Operation.o Fill.o Empty.o Pour.o Jug.o main.cpp -o test_main

test_priority_queue: PriorityQueue.o testPriorityQueue.cpp
	g++ $(FLAGS) PriorityQueue.o test_priority_queue.cpp -o test_priority_queue

test_hash_table: HashTable.o testHashTable.cpp
	g++ $(FLAGS) HashTable.o testHashTable.cpp -o test_hash_table

test_state: State.o testState.cpp
	g++ $(FLAGS) State.o testState.cpp -o test_state

State.o: State.h State.cpp
	g++ $(FLAGS) -c State.cpp

AVLNode.o: AVLNode.h AVLNode.cpp
	g++ $(FLAGS) -c AVLNode.cpp

AVLTree.o: AVLTree.h AVLTree.cpp
	g++ $(FLAGS) -c AVLTree.cpp

HashTable.o: HashTable.h HashTable.cpp
	g++ $(FLAGS) -c HashTable.cpp

PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
	g++ $(FLAGS) -c PriorityQueue.cpp

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
