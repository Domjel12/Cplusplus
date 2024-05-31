#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

class Kreis {
private:
    float radius;

public:

    Kreis(){                     
        radius = 42;
    }

    Kreis(float r){ 
        setRadius(r);
    }

    void setRadius(float r){  //setter
        if(r>0)
        {
            radius = r;
        }
    }
    float getRadius(){      //getter
        return radius;
    }                       

    float flaeche(){
        return M_PI * radius * radius;
    }

};

int main(){
    Kreis hanspeter(12);
    Kreis * pointeraufhp = &hanspeter;                 
    cout << pointeraufhp->flaeche() << "\n";
    //hanspeter.radius = 1337;          //durch privat kann ich bspw den Wert hier nicht mehr ändern "er ist sozusagen Privat" 
    pointeraufhp->setRadius(1337);      //durch die setRadius()"setter" funktion können wir den wert aber trozdem bearbeiten (-1 geht nicht weil wir es so wollen)
    cout << "hanspeters flaeche ist: " << hanspeter.getRadius() << "\n";  //durch getRadius()"getter" können wir den "privaten" Wert anzeigen lassen

    return 0;
}