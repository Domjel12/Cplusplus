#include <iostream>
#include <memory>
using namespace std;

class Konto {
public:
    Konto(string name, int nummer, int betrag) :
        besitzer(name), kontonummer(nummer), saldo(betrag)
        { cout << "Konto eroeffnet " << endl; };
    ~Konto(){cout << "konto geloescht " << endl; };
    int einzahlen(int, int);
    int auszahlen(int, int);
    void abfrage(int);
private:
    int kontonummer;
    int saldo;
    string besitzer;

};

int main(){
    unique_ptr<Konto> p1 (new Konto{ "Daniel", 1000,5});
    p1->einzahlen(1000,555);
    p1->abfrage(1000);

    unique_ptr<Konto> p2 (new Konto{ "Hoffmann", 5000,6});
    p2->einzahlen(5000, 300);
    p2->abfrage(5000);

    shared_ptr<Konto> p3 (new Konto{ "Fred Feuersein", 8000,7});
    shared_ptr<Konto> p4(p3);

    p4->einzahlen(8000, 440);
    p4->abfrage(8000);
    p4->auszahlen(8000, 1);

    cout << "So viele Konten haben Zugang: " << p3.use_count() << endl;
    p3.reset();
    cout <<  "So viele Konten haben Zugang: " << p3.use_count() << endl;
    //p3->abfrage(8000);

    shared_ptr<Konto> p5(p4);// nach dem löschen wieder eröffnet
    p5->abfrage(8000);


    return 0;

    //Konto Daniel {"Daniel", 1000, 10};
    //Daniel.einzahlen(1000,555);
    //Daniel.abfrage(1000);
}

int Konto::einzahlen(int konto, int betrag){
    if (konto != kontonummer) return 1;
    saldo += betrag;
    return 0;
}
int Konto::auszahlen(int konto, int betrag){
    if (konto != kontonummer) return 1;
    saldo -= betrag;
    return 0;
}
void Konto::abfrage(int konto){
    if (konto != kontonummer) return;
    cout << "Inhaber: " << besitzer << " Kontonummer: " << kontonummer << " Saldo: " << saldo << endl;
}