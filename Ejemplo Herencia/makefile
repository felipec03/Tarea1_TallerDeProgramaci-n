FLAGS = -g
#FLAGS = -O2

all: test_ABC 

test_ABC: A.o B.o C.o test_ABC.cpp
	g++ ${FLAGS} A.o B.o C.o test_ABC.cpp -o test_ABC

A.o: A.h A.cpp
	g++ ${FLAGS} -c A.cpp

B.o: B.h B.cpp
	g++ ${FLAGS} -c B.cpp

C.o: C.h C.cpp
	g++ ${FLAGS} -c C.cpp

clean:
	rm -f *.o test_Queue test_State test_Jug test_ABC


