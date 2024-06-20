//mehr zu Vererbung und Virtual
//https://www.youtube.com/watch?v=esCBTBiMTNQ&list=PLNmsVeXQZj7oG-kkn36ZnDpRq6iahUXZS&index=17

//Kurz gesagt Const, overloaded operatoren werden nicht vererbt!!!

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Tier{                         
public:     
    virtual void wieMachtDasTier(){   //(3)virtual = dynamische bindung, weil wir wollen nicht Hallo haben sondern Hund
        cout << "Hallo" << endl;    
    }         
};

class Hund: public Tier{            
private:                          
    string name;
public:
    Hund(string newname):name(newname){}
    void wieMachtDasTier(){
        cout << "Wuff" << endl;   //Vererbung geht hier nicht weil die normale Klasse wichtigiger ist als das Vererbte "Wuff" > "Hallo"
    }
    string getName(){
        return this->name;
    }
    void test(){
        wieMachtDasTier();
    }
};

int main(){
    Hund ace("Ace");
    //Tier abc = ace;  //(1)Wenn nur das hier ist, dann wird alles in klasse "Hund" vergessen und nur "Tier" zugewiesen
    //abc.wieMachtDasTier(); //(2)statische Bindung bis hier wird nur "Hallo" gesagt
    Tier* abc = &ace;   
    abc->wieMachtDasTier();     //wegen den Pointern ("*, &" und "->") wird "Wuff gesagt".
                                //Pointer Nzutzen wenn wir die Unterklasse nutzen wollen!!!!!

    return 0;
}

