#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

class Kreis {
public:
    float radius;

    Kreis(){                     
        radius = 42;
    }

    Kreis(float r):radius(r){       //alternative

    }
               

    float flaeche(){
        return M_PI * radius * radius;
    }

};

int main(){
    Kreis frank(25);            
    cout << "franks flaeche ist: " << frank.flaeche();

    Kreis hanspeter(12);
    Kreis * pointeraufhp = &hanspeter;      //pointer           
    cout << pointeraufhp->flaeche() << "\n";
    hanspeter.radius = 1337;                //alternativ hanspeter->radius = 1337;
    cout << "hanspeters flaeche ist: " << pointeraufhp->flaeche();


    
    
    return 0;
}