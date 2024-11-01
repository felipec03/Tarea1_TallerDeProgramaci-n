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
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    // Read the first line
    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "File is empty or cannot read the first line." << std::endl;
        return false;
    }

    // Read integers from the first line
    std::istringstream iss1(line);
    int value;
    int size1 = 0;
    while (iss1 >> value) {
        size1++;
    }

    // Allocate array1
    array1 = new int[size1];
    iss1.clear(); // Clear the stream state
    iss1.str(line); // Reset the stream with the line again

    int index1 = 0;
    while (iss1 >> value) {
        array1[index1++] = value;
    }

    // Read the second line
    if (!std::getline(file, line)) {
        std::cerr << "Cannot read the second line." << std::endl;
        delete[] array1; // Clean up
        return false;
    }

    // Read integers from the second line
    std::istringstream iss2(line);
    int size2 = 0;
    while (iss2 >> value) {
        size2++;
    }

    // Allocate array2
    array2 = new int[size2];
    iss2.clear(); // Clear the stream state
    iss2.str(line); // Reset the stream with the line again

    int index2 = 0;
    while (iss2 >> value) {
        array2[index2++] = value;
    }

    // Set count to the size of the first array
    count = size1;

    file.close();
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

    readFile(fileName,initialVolumes, goalVolumes, numJugs);

    State* initialState = new State(initialVolumes, initialVolumes, goalVolumes, numJugs, nullptr, "Inicio");
    
    Jug j = Jug(initialState, 10000000, 10000000);
    
    State* solution = j.solve();

    if (solution != nullptr) {
        std::cout << "Solution found!" << std::endl;
        j.printSolution(solution);
    } else {
        std::cout << "No solution exists." << std::endl;
    }
}