#include <iostream>

using namespace std;

class Memstatic
{
  public:
    Memstatic() { ++count; };   // Konstruktor
    ~Memstatic() { --count; };  // Destruktor
    static int count;           // static Member  
};
int Memstatic::count = 10;

int main()
{
  Memstatic x, y;
  cout << "Zaehler count ist jetzt: " << x.count << endl;

// Neuer Block => Scope

  {
    Memstatic a, b, c, d;
    cout << "Zaehler count steht auf: " << x.count << endl;
  }

  Memstatic z;
  cout << "Zaehler count ist nun: " << z.count << endl;
    
  return 0;
}
