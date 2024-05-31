#include <stdio.h>
#include <iostream>
using namespace std;

class Vektor{
public:
    double x,y,z;
    Vektor(double a, double b, double c):x(a),y(b),z(c){}
    Vektor operator +(Vektor &b){                                       //call by value = (Vektor b), call by referece = (Vektor &b) oder (Vektor *b)
        return Vektor(this->x + b.x, this->y + b.y, this->z + b.z);
    }

    void printMe(){
        cout << "<" << this->x << ", " << this->y << ", " << this->z << ">"; //call be reference deswegen -> statt .
    }
};

int main(){
    Vektor nukular(5,5,5);
    Vektor numberof911(9,1,1);
    Vektor dieBartdie = nukular + numberof911;         
    dieBartdie.printMe();
    return 0;
}