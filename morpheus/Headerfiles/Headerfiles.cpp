#include <stdio.h>
#include <iostream>
#include "Vektor.h" //neu
using namespace std;



int Vektor::dimension = 3;          
int main(){
    Vektor nukular(5,5,5);
    Vektor numberof911(9,1,1);
    Vektor dieBartdie = nukular + numberof911;        
    dieBartdie.printMe();

    return 0;
}

//wir erstellen uns eine Datei Vektor.h
//kopieren class vektor in die Vektor.h

//zum Ausführen im Terminal:
// Headerdatei ("Vektor.h") wird nicht gebraucht 
//g++ Headerfiles.cpp Vektor.cpp -o Headerfiles