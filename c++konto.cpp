//vererbung 

#include <iostream>

class Konto {
  public:
     Konto() {};  // Default Konstruktor
     virtual void bankinfo(void){ std::cout << "Banknummer: 13122" << std::endl;};
     virtual int abfragen(unsigned int); //Kontonummer; return ist Saldo
     virtual int einzahlen(unsigned int, int); //Kontonummer, Betrag; Return ist Saldo
     virtual int auszahlen(unsigned int, int);
  protected:
    unsigned int kontonummer;
    int saldo;
};

class Giro : public Konto{
  public:
    Giro(unsigned int n, int s):kontonummer(n), saldo(s)
    {std::cout << "Girokonto eröffnet: " << n << std::endl; };
    int abfragen(unsigned int k)
      {
    if (kontonummer != k) return -999;
    return saldo;
      }
    int einzahlen(unsigned int k, int b)
      {
    if (kontonummer != k) return -999;
    return saldo += b; 
      }
    int auszahlen(unsigned int k, int b)
      {
    if (kontonummer != k) return -999;
    if (b > saldo) return -999;
    return saldo -= b;
      }
  private:
    unsigned int kontonummer;
    int saldo;
};

class Tages : public Konto{
  public:
    Tages(unsigned int n, int s) :kontonummer(n), saldo(s)
    {std::cout << "Tagesgeldkonto eröffnet: " << n << std::endl; };
    int abfragen(unsigned int k)
      {
    if (kontonummer != k) return -999;
    return saldo;
      }
    int einzahlen(unsigned int k, int b)
      {
    if (kontonummer != k) return -999;
    return saldo += b; 
      }
    int auszahlen(unsigned int k, int b)
      {
    if (kontonummer != k) return -999;
    if (b > saldo) return -999;
    return saldo -= b;
      }
  private:
    unsigned int kontonummer;
    int saldo;
    float zinssatz;
    int tage;
};

class Paypal : public Konto{
  public:
    Paypal(unsigned int n, int s) : kontonummer(n), saldo(s)
    {std::cout << "Paypalkonto eröffnet: " << n << std::endl; };
    int abfragen(unsigned int n){
      if (kontonummer != n) return -999;
      return saldo;
    }
    int einzahlen(unsigned int k, int b)
      {
    if (kontonummer != k) return -999;
    return saldo += b; 
      }
    int auszahlen(unsigned int k, int b)
      {
    if (kontonummer != k) return -999;
    if (b > saldo) return -998;
    return saldo -= b;
      }
  private:
    unsigned int kontonummer;
    int saldo;

};

using namespace std;

int main()
{
  Giro Daniel{4711, 100};
  cout << "Konto Daniel " << Daniel.abfragen(4711) << endl;
  Daniel.einzahlen(4711, 101);
  cout << "Konto Daniel " << Daniel.abfragen(4711) << endl;
  Daniel.bankinfo();
  Paypal Daniel_Paypal{ 1000, 10};
  cout << "Paypalkonto Daniel " << Daniel_Paypal.abfragen(1000) << endl;


  return 0;
}

int Konto::abfragen(unsigned int konum)
{
  if (kontonummer != konum) return -999;
  return saldo;
}

int Konto::einzahlen(unsigned int konum, int betrag)
{
    if (kontonummer != konum) return -999;
    return saldo += betrag; 
}

int Konto::auszahlen(unsigned int konum, int betrag)
{
    if (kontonummer != konum) return -999;
    if (betrag > saldo) return -999;
    return saldo -= betrag;
}
