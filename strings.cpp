#include <iostream>

using namespace std;

int main()
{
  int n = 44;
  cout << "int n = ?: " << n << "\t\t\t Adresse: " << &n << endl;

  int* ptr_n = &n;
  cout << "Adresse von ptr_n: " << &ptr_n << "\t\t Wert: " << *ptr_n << endl;

  // Zugriff auf RValue ueber Pointer

  *ptr_n = 77;
  cout << "int n = ?: " << n << "\t\t\t Adresse: " << &n << endl;
  cout << "Adresse von ptr_n: " << &ptr_n << "\t\t Wert: " << *ptr_n << endl;

  int* ptr_q = &n;
  cout << "Adresse von ptr_q: " << &ptr_q << "\t\t Wert: " << *ptr_q << endl;

  // Aenderung des Datentypes; explizites Casting ?

//  float* ptr_f = &(float )n;
//  cout << "Adresse von ptr_f: " << ptr_f << "\t Wert: " << *ptr_f << endl;

}
	

