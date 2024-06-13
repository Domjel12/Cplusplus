#include "Vektor.h"
#include <iostream>
using namespace std;

Vektor::Vektor(double a, double b, double c){
    x = a;
    y = b;
    z = c;
}
Vektor Vektor::operator +(Vektor &b){                                       
    return Vektor(this->x + b.x, this->y + b.y, this->z + b.z);
}
void Vektor::printMe(){
    cout << "<" << this->x << ", " << this->y << ", " << this->z << ">"; 
}

//Vektor:: wichtig!!
//gehört zu Vektor.h und Headerfiles