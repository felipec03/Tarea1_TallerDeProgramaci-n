#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  
using namespace std;

class Arr {
    public:
        int *arr;
        int capacity;
        int number;
        Arr(int n){
            capacity=n;
            number=0;
            arr = new int[n];
        };
        Arr(){
            capacity=0;
            number=0;
            arr = new int[0];
        }
        ~Arr(){
            delete[] arr;
        }
        void push(int x) {
            if (number<capacity){
                arr[number]=x;
                number++;
            } else {
                int *arr2 = new int[capacity*2];
                for (int i=0; i<capacity; i++){
                    arr2[i]=arr[i];
                }
                capacity=capacity*2;
                delete[] arr;
                arr=arr2;
            }
        }
};

int main() {
    string line;
    ifstream myfile ("prueba1.txt");
    if (myfile.is_open()) {
        getline(myfile, line);
        int n=0;
        int c;
        stringstream ss(line);
        Arr C(10);
        Arr Sol(10);
        while(ss >> c){
            cout << c << " ";
            C.push(c);
            n++;
        }
        cout << "leidos :" << n<< endl;
        ss.clear();
        getline(myfile, line);
        ss.str(line);
        while(ss >> c){
            cout << c << " ";
            Sol.push(c);
            n++;
        }
        cout << "leidos :" << n<< endl;

        myfile.close();

        for (int i=0; i< C.number; i++){
            cout << C.arr[i] << " ";
        }
        cout << endl;
        for (int i=0; i< Sol.number; i++){
            cout << Sol.arr[i] << " ";
        }
        cout << endl;

    } else {
        cout << "Unable to open file";
    }



    return 0;
}