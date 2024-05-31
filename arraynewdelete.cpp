#include <iostream>
#include <string.h>
using namespace std;

void getarray(double*& array, int& n){
    cout << "Bitte Arraygroesse angeben: " << endl;
    cin >> n; //Einlesen

    array = new double[n];  //Erstelle Array, Speicherplatzadresse von main

    cout << "Ein Element pro Zeile: " << endl; 
    for(int i=0; i < n; i++){
        cin >> array[i];
    }

}

void printarray(double*& array, int n){
    cout << "belegung des Array: \n";
    for (int i = 0; i < n; i++)
        cout << "Wert " << i << ": " << array[i] << "\n";
    
    cout << endl;
    
}

int main(){

    int n;          //Anzahl array Elemente, wird in getarray befuellt
    double* array;  //Adresse von array; wird in getarray genutzt

    getarray(array,n);

    printarray(array, n);

    delete[] array;

    return 0;
}