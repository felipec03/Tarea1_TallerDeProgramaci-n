#include "Jug.h"


Jug::Jug(int a, int b){
	open = new Queue(a);
	all = new Queue(b);
	State* s = new State(0,0,nullptr, "");
	open -> push(s);
	all -> push(s);
}

State* Jug::filla0(State* o){
	if(o->a0 < 3){
		State *s = new State(3, o->a1,o,"Fill up a0.");
		return s;
	}
	else{
		return nullptr;
	}
}

State* Jug::filla1(State* o){
	if(o->a1 < 5){
		State *s = new State(o->a0, 5,o,"Fill up a1.");
		return s;
	}
	else{
		return nullptr;
	}
}

State* Jug::emptya0(State* o){
	if(o->a0 > 0){
		State *s = new State(0, o->a1,o,"Empty out a0.");
		return s;
	}
	else{
		return nullptr;
	}
}

State* Jug::emptya1(State* o){
	if(o->a1 > 0){
		State *s = new State(o->a0, 0,o,"Empty out a1.");
		return s;
	}
	else{
		return nullptr;
	}
}

State* Jug::poura0toa1(State* o){
	if(o->a0 > 0 && o->a1 < 5){
		int difference = 5 - o->a1;
		if(o->a0 > t){
			State *s = new State(o->a0 - difference, 5,o,"Pour a0 to a1.");
			return s;
		}
		else{
			State *s = new State(0, o->a1 + o->a0,o,"Pour a0 to a1.");
			return s;
		}
	}
	else{
		return nullptr;
	}
}

State* Jug::poura1toa0(State* o){
	if(o->a1 > 0 && o->a0 < 3){
		int difference = 3 - o->a0;
		if(o->a1 > difference){
			State *s = new State(3, o->a1 - difference,o,"Pour a1 to a0.");
			return s;
		}
		else{
			State *s = new State(o->a0 + o->a1, 0,o,"Pour a1 to a0.");
			return s;
		}
	}
	else{
		return nullptr;
}


State* Jug::solve(){
	// Mientras que la cola open no este vacia
	while(open->numElements() > 0){
		// Se saca el primer elemento de la cola
		State* s = open->pop();
		// Se agrega a la cola all
		all->push(s);
		if(s->a1 == 4){
			return current;
		}

		// Esto nunca se debería hacer!!
		// No se debe poner tanto if, hay que generalizar!!
		// Hay que hacer una función que generalice el llenado, vaciado y vertido para n jarrones
		// Crear clase operación para generalizar problema a n jarrones

		State* f0 = filla0(s);
		State* f1 = filla1(s);
		State* e0 = emptya0(s);
		State* e1 = emptya1(s);
		State* p0 = poura0toa1(s);
		State* p1 = poura1toa0(s);

		if(f0 != nullptr && !all->find(f0)){
			open->push(f0);
			all->push(f0);
		} else if(f0 != nullptr){
			delete f0;
		}

		if(f1 != nullptr && !all->find(f1)){
			open->push(f1);
			all->push(f1);
		} else if(f1 != nullptr){
			delete f1;
		}

		if(e0 != nullptr && !all->find(e0)){
			open->push(e0);
			all->push(e0);
		} else if(e0 != nullptr){
			delete e0;
		}

		if(e1 != nullptr && !all->find(e1)){
			open->push(e1);
			all->push(e1);
		} else if(e1 != nullptr){
			delete e1;
		}

		if(p0 != nullptr && !all->find(p0)){
			open->push(p0);
			all->push(p0);
		} else if(p0 != nullptr){
			delete p0;
		}

		if(p1 != nullptr && !all->find(p1)){
			open->push(p1);
			all->push(p1);
		} else if(p1 != nullptr){
			delete p1;
		}

	}
	return nullptr;
}
