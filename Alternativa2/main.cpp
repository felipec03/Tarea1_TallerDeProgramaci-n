#include "Jug.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool readFile(const std::string& filename, int*& initialVolumes, int*& goalVolumes, int& numJugs) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return false;
    }

    string line;
    if (!getline(file, line)) {
        cerr << "El archivo está vacío, o ha ocurrido un error..." << endl;
        return false;
    }

    istringstream iss1(line);
    int value;
    vector<int> initialVolumesVec;
    while (iss1 >> value) {
        initialVolumesVec.push_back(value);
    }

    if (!getline(file, line)) {
        cerr << "No se pudo leer la segunda línea." << endl;
        return false;
    }

    istringstream iss2(line);
    vector<int> goalVolumesVec;
    while (iss2 >> value) {
        goalVolumesVec.push_back(value);
    }

    if (initialVolumesVec.size() != goalVolumesVec.size()) {
        cerr << "Las líneas del archivo deben tener el mismo número de valores." << endl;
        return false;
    }

    numJugs = initialVolumesVec.size();
    initialVolumes = new int[numJugs];
    goalVolumes = new int[numJugs];

    for (int i = 0; i < numJugs; ++i) {
        initialVolumes[i] = initialVolumesVec[i];
        goalVolumes[i] = goalVolumesVec[i];
    }

    return true;
}

int main() {
    int* initialVolumes = nullptr;
    int* goalVolumes = nullptr;
    int numJugs = 0;
    string fileName;

    int* maxCapacities = nullptr;
    int* goalVolumes = nullptr;
    int numJugs = 0;

    
    cout << "Ingrese el nombre del archivo (por ejemplo, E3.txt): ";
    cin >> fileName;

    if (!readFile(fileName, initialVolumes, goalVolumes, numJugs)) {
        return 1;
    }

    int* maxCapacities = new int[numJugs];
    for (int i = 0; i < numJugs; ++i) {
        maxCapacities[i] = initialVolumes[i];
    }

    // Initialize all jugs to 0 volume for the initial state
    int* startVolumes = new int[numJugs];
    for (int i = 0; i < numJugs; ++i) {
        startVolumes[i] = 0;
    }

    State* initialState = new State(startVolumes, maxCapacities, goalVolumes, numJugs, nullptr, "Inicio");

    Jug jugSolver(initialState, 10000, 10000);

    State* solution = jugSolver.solve();

    if (solution != nullptr) {
        jugSolver.printSolution(solution);
    } else {
        cout << "No se encontró solución." << endl;
    }

    // Clean up
    delete[] initialVolumes;
    delete[] goalVolumes;
    delete[] maxCapacities;
    delete initialState;

    return 0;
}