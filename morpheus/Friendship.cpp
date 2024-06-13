#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Hund{
    string name;
public:
    Hund(string newname):name(newname){}
    string getName(){
        return this->name;
    }
    friend void adopt(Hund &h);         //befreundete Funktion, funktioniert auch mit klassen
};
void adopt(Hund &h){
    h.name = "Goofy";
}
int main(){
    Hund ace("Ace");    //
    adopt(ace);         //
    cout << ace.getName();
    return 0;
}