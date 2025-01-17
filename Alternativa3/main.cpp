#include "Jug.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <cmath>
using namespace std;

bool readFile(const std::string& filename, int*& array1, int*& array2, int& count) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "No se pudo abrír el archivo: " << filename << std::endl;
        return false;
    }

    // lectura de la primera linea
    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "El archivo está vacío, o ha ocurrido un error..." << std::endl;
        return false;
    }

    // lectura de la primera linea
    std::istringstream iss1(line);
    int value;
    int size1 = 0;
    while (iss1 >> value) {
        size1++;
    }

    // asignar memoria a arreglo 1
    array1 = new int[size1];
    // limpiar y resetear stream
    iss1.clear(); 
    iss1.str(line); 

    int index1 = 0;
    while (iss1 >> value) {
        array1[index1++] = value;
    }

    // lectura de la segunda linea
    if (!std::getline(file, line)) {
        std::cerr << "No se pudo leer la segunda línea." << std::endl;
        delete[] array1; // Clean up
        return false;
    }

    // leer enteros de la segunda linea
    std::istringstream iss2(line);
    int size2 = 0;
    while (iss2 >> value) {
        size2++;
    }

    // Verificar que ambas líneas tienen el mismo número de elementos
    if (size1 != size2) {
        std::cerr << "Las líneas tienen diferente cantidad de números." << std::endl;
        delete[] array1;
        return false;
    }

    // asignamos memoria a segundo arreglo
    array2 = new int[size2];
    // resetear stream
    iss2.clear();
    iss2.str(line);

    int index2 = 0;
    while (iss2 >> value) {
        array2[index2++] = value;
    }

    // Establecer el número de jarras
    count = size1;

    return true;
}


int main() {
    int* initialVolumes;
    int* goalVolumes;
    int numJugs;
    string fileName;

    cout << "Resolución del problema de los N Jarros" << endl;
    cout << "Por favor Ingrese el nombre del archivo: ";
    cin >> fileName;

    if (!readFile(fileName, initialVolumes, goalVolumes, numJugs)) {
        return 1;
    }

    int* currentVolumes = new int[numJugs];
    for (int i = 0; i < numJugs; i++) {
        currentVolumes[i] = 0;
    }

    State* initialState = new State(currentVolumes, initialVolumes, goalVolumes, numJugs, nullptr, "Inicio");

    Jug j(initialState, 100000000, 100000000);
    State* solution = j.solve();


    if (solution != nullptr) {
        cout << "Se encontró una solución!" << endl;
        j.printSolution(solution, 0);

    } else {
        cout << "No se encontró una solución..." << endl;
    }

    delete[] currentVolumes;
    delete[] initialVolumes;
    delete[] goalVolumes;

    return 0;
}