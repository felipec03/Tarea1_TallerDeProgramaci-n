#include "Jug.h"

int main(){
	Jug j(100,100);
	State* solution = j.solve();
	solution->print();
	return 0;
}
