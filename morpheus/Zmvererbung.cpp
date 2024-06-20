//Zugruiffsmodifikatoren bei Vererbung
//verschiedene arten zu erben
//https://www.youtube.com/watch?v=X8HqCZQr1PI&list=PLNmsVeXQZj7oG-kkn36ZnDpRq6iahUXZS&index=16

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Tier{                                     //was machen public, protected und private?
public:     //Können wir immer nutzen und sehen
    void wieMachtDasTier(){   
        cout << "Hallo" << endl;    
    } 
protected:     //wir können die nicht außerhalb der klasse aufrufen, aber in der abgeleiteten klasse "class hund: Public Tier"
    void foo(){
        cout << "foo" << endl;
    }       
private:       //können wir nirgendwo aufrufen außer in der Tier klasse
    void baz(){
        cout << "baz" << endl;
    }       
};

class Hund: public Tier{            //public wird übernommen ohne probleme,
                                    //Wenn wir protected nutzen werden alle public aus "Tier" auch auf protected überschrieben
private:                            //Wenn wir private nutzen werden alle protected und public aus "Tier" auch auf protected überschrieben
    string name;                    //private aus "Tier" wird aber nicht vererbt
public:
    Hund(string newname):name(newname){}
    string getName(){
        return this->name;
    }
void test(){                                    //zeigt uns beispiele
    foo(); //protectet ist hier machbar weil unterklasse 
}
};

int main(){
    Hund ace("Ace");
    ace.wieMachtDasTier();
    return 0;
}