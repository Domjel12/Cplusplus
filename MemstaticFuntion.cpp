#include <iostream>

using namespace std;

class Memstatic
{
  public:
    Memstatic() { ++count; };   // Konstruktur
    ~Memstatic() { --count; };  // Destruktur
    static int numMemstatic() { return count; };
  private:
    static int count;           // static Member  
  
};
int Memstatic::count = 10;



int main(int argc, char **argv)
{
  Memstatic x, y;
  cout << "Zaehler count ist jetzt: " << Memstatic::numMemstatic() << endl;
  {
    Memstatic a, b, c, d;
    cout << "Zaehler count steht auf: " << Memstatic::numMemstatic() << endl;
  }
  Memstatic z;
  cout << "Zaehler count ist nun: " << Memstatic::numMemstatic() << endl;
    
	return 0;
}
