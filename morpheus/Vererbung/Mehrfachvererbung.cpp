//Mehrfachvererbung und fehler "ambiguous" aka Diamantenproblem
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Tier{                         
public:     
    virtual void wieMachtDasTier(){   
        cout << "Hallo" << endl;    
    }
    virtual void lead(){            //(2)wir haben hier 2 mal lead was ein Problem ist "ambiguous". 
                                    //Kurz gesagt er weiß nicht was gemacht werden soll
    }         
};

class Blindenfuehrer{
public:
    virtual void lead(){            //(1)
        cout << "Follow Me" << endl;  
    }

};

class Hund: public Tier, public Blindenfuehrer{      //Hier haben wir schon eine Mehrfachvererbung "Tier" und "Blindenfuehrer"      
private:                          
    string name;
public:
    Hund(string newname):name(newname){}
    void wieMachtDasTier(){
        cout << "Wuff" << endl; 
    }
    string getName(){
        return this->name;
    }
    void test(){
        wieMachtDasTier();
    }
    void lead(){                                //(3)durch noch eine Leadfunktion wird ein Diamantenproblem behoben
        cout << "Follow, wuff" << endl;         //bzw die anderen 2 Lead werden überschrieben
    }
};

int main(){
    Hund ace("Ace");            
    ace.lead();

    return 0;
}
