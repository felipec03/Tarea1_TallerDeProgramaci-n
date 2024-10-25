FLAGS = -g
#FLAGS = -O2
all: testQueue test_State testJug

testQueue: State.o Queue.o testQueue.cpp
	g++ $(FLAGS) State.o Queue.o testQueue.cpp -o testQueue

test_State: State.o testQueue.cpp
	g++ $(FLAGS) State.o test_State.cpp -o test_State

testJug: State.o testJug.cpp
	g++ $(FLAGS) State.o testJug.cpp -o testJug

State.o: State.h State.cpp
	g++ $(FLAGS) -c State.cpp

Queue.o: Queue.h Queue.cpp
	g++ $(FLAGS) -c Queue.cpp

Jug.o: Jug.h Jug.cpp
	g++ $(FLAGS) -c Jug.cpp

HashTable.o: HashTable.h HashTable.cpp
	g++ $(FLAGS) -c HashTable.cpp

Heap.o: Heap.h Heap.cpp
	g++ $(FLAGS) -c Heap.cpp

clean:
	rm $(FLAGS) -f *.o testQueue test_State
