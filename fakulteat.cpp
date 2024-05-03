#include <iostream>
using namespace std;

unsigned long long fak(const int n){
    unsigned long long f = 1;

    for(int i = n; i > 0; i--)

        f *= i;

    return f;
    
}

int main(){
    int i;

    cout << "Bitte Zahl n zur Berechnung der Fakulaet eingeben: " << endl;

    cin >> i;

    cout << "Fakultaet von " << i << " ist " << fak(i) << endl;

    return 0;
}