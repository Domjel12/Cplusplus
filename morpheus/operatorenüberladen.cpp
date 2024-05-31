#include <stdio.h>
#include <iostream>
using namespace std;

class Vektor{
public:
    double x,y,z;
    Vektor(double a, double b, double c):x(a),y(b),z(c){}
    Vektor operator +(Vektor  b){
        return Vektor(x + b.x, y+b.y, z+b.z);
    }

    void printMe(){
        cout << "<" << x << ", " << y << ", " << z << ">";
    }
};

int main(){
    Vektor nukular(5,5,5);
    Vektor numberof911(9,1,1);
    //Vektor dieBartdie = nukular + numberof911; //Problem das "+" wird nicht erkannt, wir müssen es definieren
    Vektor dieBartdie = nukular.operator+(numberof911); //alternative
    Vektor dieBartdie = nukular + numberof911;          //geht jetzt durch Vektor operator+ jetzt auch
    nukular.printMe();
    return 0;
}
