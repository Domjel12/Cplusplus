#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

class Kreis {           //<-- Klasse
public:
    float radius;
    float flaeche(){
        return M_PI * radius * radius;
    }

};

int main(){
    Kreis frank;            //<-- Klasse wird zugewiesen einer Person bspw.
    frank.radius = 25;
    Kreis hanspeter;
    hanspeter.radius = 1337;
    cout << "franks flaeche ist: " << frank.flaeche();
    cout << "hanspeters flaeche ist: " << hanspeter.flaeche();

    return 0;
}