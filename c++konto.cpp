#include <iostream>

class Konto {
  public:
     Konto() {};  // Default Konstruktor
     bool abfragen(unsigned int, int&);
     bool einzahlen(unsigned int, int, int&);
     bool auszahlen(unsigned int, int, int&);
     bool eroeffnen(unsigned int);
     bool schliessen(unsigned int, int&);
private:
     unsigned int kontonummer;
     int betrag, saldo;
};

using namespace std;

int main()
{
  int a = 0;
  int& guthaben = a;
  int b = 0;
  int& saldo = b;
  
  unsigned int k = 4711;

  Konto erwin;
  erwin.eroeffnen(k);
  erwin.abfragen(k,saldo);
   
  cout << "Erwin Kontostand: " << saldo << " Euro" << endl;
  
  int i = 100;
  erwin.einzahlen(k,i,saldo);
  cout << "Erwin Kontostand: " << saldo << " Euro "<< endl;
  
  i = 50;
  erwin.auszahlen(k,i,saldo);
  cout << "Erwin Kontostand: " << saldo << " Euro "<< endl;
  
 // cout << "Erwin Kontostand: " << Konto::kontonummer << endl;
  
  return 0;
}
bool Konto::eroeffnen(unsigned int konum)
{
  kontonummer = konum;
  saldo = 0;
  return true;
}
bool Konto::schliessen(unsigned int konum, int& kontostd)
{
  if (kontonummer != konum) return false;
  kontostd = saldo;
  return true;
}

bool Konto::abfragen(unsigned int konum, int& kontostd)
{
  if (kontonummer != konum) return false;
  kontostd = saldo;
  return true;
}

bool Konto::einzahlen(unsigned int konum, int betrag, int& kontostd)
{
    if (kontonummer != konum) return false;
    saldo += betrag; 
    kontostd = saldo;
    return true;
}

bool Konto::auszahlen(unsigned int konum, int betrag, int& kontostd)
{
    if (kontonummer != konum) return false;
    if (betrag > saldo) return false;
    saldo -= betrag; 
    kontostd = saldo;
    return true;
}
