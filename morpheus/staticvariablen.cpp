#include <stdio.h>
#include <iostream>
using namespace std;

class Vektor{
public:
    static int dimension;               //static variablen sind für alle instanzen der klasse das selbe
    double x,y,z;
    Vektor(double a, double b, double c):x(a),y(b),z(c){}
    Vektor operator +(Vektor &b){                                       
        return Vektor(this->x + b.x, this->y + b.y, this->z + b.z);
    }

    void printMe(){
        cout << "<" << this->x << ", " << this->y << ", " << this->z << ">"; 
    }
};
int Vektor::dimension = 3;          // wir definieren die Dimension
int main(){
    Vektor nukular(5,5,5);
    Vektor numberof911(9,1,1);
    Vektor dieBartdie = nukular + numberof911;         //addiert 2 Vektoren

    nukular.dimension = 4;
    cout << numberof911.dimension;

    //dieBartdie.printMe();
    return 0;
}