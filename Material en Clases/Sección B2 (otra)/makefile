FLAGS = -g

all: State.o Queue.o Heap.o Jug.o test_State test_Queue test_Heap main readFile

State.o: State.cpp State.h
	g++ ${FLAGS} -c State.cpp

Queue.o: Queue.cpp Queue.h
	g++ ${FLAGS} -c Queue.cpp

Heap.o: Heap.cpp Heap.h
	g++ ${FLAGS} -c Heap.cpp

Jug.o: Jug.cpp Jug.h
	g++ ${FLAGS} -c Jug.cpp

test_State: test_State.cpp State.o
	g++ ${FLAGS} State.o test_State.cpp  -o test_State 

test_Queue: test_Queue.cpp Queue.o
	g++  ${FLAGS} State.o Queue.o test_Queue.cpp -o test_Queue 	

test_Heap: test_Heap.cpp State.o Heap.o
	g++ ${FLAGS} State.o Heap.o test_Heap.cpp -o test_Heap

main: main.cpp Jug.o State.o Queue.o
	g++ ${FLAGS} Jug.o State.o Queue.o main.cpp -o main

readFile: readFile.cpp
	g++ ${FLAGS} readFile.cpp -o readFile

clean:
	rm -f *.o test_State test_Queue test_Heap main readFile