#include "MinHeap.h"
#include "State.h"

int main(){

    int arregloJugs[] = {0,0,0};
    int maxCapacities[] = {1,2,3};
    int goalVolumes[] = {0,0,0};
    State* state = new State(arregloJugs, maxCapacities, goalVolumes, 3, nullptr, "inicio");

    MinHeap* minHeap = new MinHeap(10);
    
    cout << "MinHeap creado" << endl;
    minHeap->insert(state);
    cout << "Se insertó estado" << endl;
    State* estadoExtraido = minHeap->extractMin();
    cout << "Se extrayo estado: " << endl;
    estadoExtraido->print();

    if(minHeap->isEmpty()){
        cout << "MinHeap esta vacío" << endl;
        return 0;
    }
    else{
        cout << "MinHeap NO está vacío" << endl;
    }
    return 0;
}