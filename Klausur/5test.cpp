//Inhalt des Programms:
//  (Vektoren,cin einlesen und ablesen von vektoren,)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

template <typename T>
void readData(vector<T>& data, T sentinel) {
    T input;
    while(cin >> input && input != sentinel) {
        data.push_back(input);
    }
}

template <typename T>
void sortData(vector<T>& data) {
    sort(data.begin(), data.end());
}

template <typename T>
void printData(const vector<T>& data) {
    cout << "Anzahl der Elemente: " << data.size() << endl;
    for (const auto& element : data) {
        cout << element << endl;
    }
}

int main() {
    vector<int> numericData;
    vector<string> lexicalData;

    cout << "Geben Sie numerische Daten ein:" << endl;
    readData(numericData, -1);
    sortData(numericData);
    printData(numericData);

    cout << "Geben Sie lexikalische Daten ein:" << endl;
    readData(lexicalData, string("."));
    sortData(lexicalData);
    printData(lexicalData);

    return 0;
}