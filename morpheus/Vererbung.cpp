//https://www.youtube.com/watch?v=Ia1QE-RraGU&list=PLNmsVeXQZj7oG-kkn36ZnDpRq6iahUXZS&index=15 
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Tier{                         //neu
public:     
    void wieMachtDasTier(){   
        cout << "Hallo" << endl;    //wir brauchen keinen parameter
    }         
};

class Hund: public Tier{            //hiermit sagen wir, dass jeder Hund bspw ein Tier ist "ab :"
private:                          
    string name;
public:
    Hund(string newname):name(newname){}
    string getName(){
        return this->name;
    }
};

int main(){
    Hund ace("Ace");
    ace.wieMachtDasTier();
    return 0;
}




