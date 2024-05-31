#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

class Kreis {
public:
    float radius;

    Kreis(){                     //(2)  overload (Wie constructor nur bspw wenn man ihn überschreiben will)
        radius = 42;
    }

    Kreis(float r){              //(1)  constructor  (siehe "frank")
        radius = r;
    }             

    float flaeche(){
        return M_PI * radius * radius;
    }

};

int main(){
    Kreis frank(25);            //(1)   verglichen zu klassen ist es kürzer! ohne () geht es nicht mehr "default const"
    cout << "franks flaeche ist: " << frank.flaeche();

    Kreis hanspeter;            //(2)   überschreiben 
    cout << hanspeter.flaeche() << "\n";
    hanspeter.radius = 1337;
    cout << "hanspeters flaeche ist: " << hanspeter.flaeche();


    
    
    return 0;
}