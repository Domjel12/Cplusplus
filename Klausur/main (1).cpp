#include <iostream>
#include <memory>
using namespace std;


template <typename T> //nutze individuellen Typnamen T
T quad(T a)           //Funktion mit Rückgabewert vom i. Typ T
{
        return a * a;
}
template <typename T>   //T kann anscheinend mehrmals benutzt werden lol
void test(T a)         //warum aber auch nicht, hier ist es ja ne void methode mit anderem namen...
{
    cout << a << endl;
}
template <typename T>
class Car
{
private:
    T kW;
public:
    Car(T kiloWatt): kW(kiloWatt){cout << "Auto mit " << kW << " kW angelegt. " << endl;}
    ~Car() {cout << "Auto zerstört" << endl;} 
};

class NonTemplateCar
{
    private:
    int kW;
    shared_ptr<NonTemplateCar> vorherigesAuto;
    public:
    NonTemplateCar() {}
    NonTemplateCar(int kiloWatt): kW(kiloWatt){cout << "Auto mit " << kW << " kW angelegt. " << endl;}
    void printkW(){cout << kW << endl;}
    ~NonTemplateCar() {cout << "Non Template Auto zerstört" << endl;} 
};




typedef struct gdate   //wie in C...
{
    int tag, monat, jahr;
}Gdate;
class Human
{
    private:    //private memberdaten
        string name;
        string mother;
        string father;
        shared_ptr<Human> mom; //ein pointer für unsere classe human um die parents (haha) zu linken
        shared_ptr<Human> dad;
        Gdate dob;       //unser wie in C date of birth datentyp
    public:
        Human(string n, Gdate g = {1,1,1970}) : name(n), dob(g)    //konstruktor mit initialisierungsliste
        {
            cout << "Mensch: " << n << " "; GiveBirth();           //wird gemacht wenn konstruiert
        }
        void GiveName() {cout << name << endl; }
        void GiveBirth() {cout << dob.tag << "." << dob.monat << "." << dob.jahr << endl; }
        void SetMother(shared_ptr<Human> p, string m) {mom = p; mother = m;}
        void SetFather(shared_ptr<Human> p, string f) {dad = p; father = f;}
        void GiveParents(){cout << "Mother: " << mother << ", Father: " << father << endl; }
        shared_ptr<Human> ShowMother() {cout << "Mother: " << mother << endl; return mom;}
        shared_ptr<Human> ShowFather() {cout << "Father: " << father << endl; return dad;}
        ~Human() {cout << "Mensch " << name << " ist gestorben." << endl;}
};

int main() {
    shared_ptr<Human> p1(new Human("Adam", {2,2,1111})); //shared pointer auf neues objekt
    p1->GiveName();
    p1->SetMother(0, "God himself");

    
    //template methoden test
    cout << quad(4.0f) << endl;
    test(5000);
    
    //shared pointer auf einmal template auto, einmal normal auto
    shared_ptr<Car<double> > p2(new Car<double>(123.4));   

    shared_ptr<NonTemplateCar> p3(new NonTemplateCar());

    shared_ptr<NonTemplateCar> p4 = make_shared<NonTemplateCar>(); //mit make shared
    auto p5 = make_shared<NonTemplateCar>();               //alternativ make shared mit auto (auto typisierung?)
    
    //template und normal auto mit new angelegt deshalb später delete
    NonTemplateCar* testcar = new NonTemplateCar(); 

    Car<int>* testcar2 = new Car<int>(100.4f);
    

    testcar->printkW();

    //hier delete
    delete(testcar);
    delete(testcar2);
    
    return 0;
}