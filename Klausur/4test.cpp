//Inhalt des Programms:
//  (Klassen, vererbung, templates, sharedpointer, destruktor, string, setter getter, konstruktoren, containerklassen)
// (unique, weak)

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

typedef struct gdate{           //struct
    int tag, monat, jahr;

}dob;

template<typename T> //templates
class Student{
    private:
        int matrikel;
        T id;
    public:
        void setid(T id){
            this->id = id;
        }

        T getid() const {
            return id;
        }   
    
};

class Mensch: private Student<int>{         //klasse + Vererbung
private:
    string name;            //string = auch eine Containerklasse
    string mutter;
    string vater;
    shared_ptr<Mensch> mom;
    shared_ptr<Mensch> pap;
    dob gebdatum;
public:
    Mensch(string n, dob d = {01,01,2000}) : name(n), gebdatum(d)       //Konstruktor +vererbung
    {
        cout << "Neuer Mensch, Name: " << n << endl; showbirth();
    };

    void showname(){cout << name << endl;};
    void showbirth(){cout << gebdatum.tag << "." << gebdatum.monat << "." << gebdatum.jahr << endl;};

    void setmother(shared_ptr<Mensch> p, string m){mom = p; mutter = m;};   //setter
    void setfather(shared_ptr<Mensch> p, string f){pap = p; vater = f;};
    void showparents(){ cout << "Mutter: " << mutter << " Vater: " << vater << endl;};

    void setid(int id){ Student<int>::setid(id);};
    void showid(){ cout << "ID: " << Student<int>::getid() << endl; };

    shared_ptr<Mensch> showmother(){ cout << "Mutter: " << mutter << endl; return mom;}; //verkettung
    shared_ptr<Mensch> showfather(){ cout << "Vater: " << vater << endl; return pap;};

    ~Mensch() {cout << "Mensch " << name << " ist gestorben." << endl;}  //destruktor
};

int main(){

    shared_ptr<Mensch> p1(new Mensch("Adam", {01,01,1111})); //sharedptr + new
    shared_ptr<Mensch> p2(new Mensch("Eva", {02,01,1111}));
    shared_ptr<Mensch> p3(new Mensch("Kain", {01,01,1111}));

    p1->showname(); 
    p1->showbirth();
    p1->setmother(0, "God himself");
    p1->setfather(0, "God himself");
    p3->setmother(p2, "Eva");
    p3->setfather(p1, "Adam");
    p3->setid(1212);
    p3->showid();
    p3->showname();
    p3->showparents();
    p3->showmother();

    cout << p1.use_count() << endl;

return 0;
}





