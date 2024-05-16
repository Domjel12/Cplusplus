/*
 * vector.cxx
 * 
 * Copyright 2024 Erwin Hofffmann <erwin@fehcom.de>
 * 
 */


#include <iostream>
#include <vector> 

using namespace std;

int main(int argc, char **argv)
{
  
  vector<float> vec {1.2, 2.2, 3.3};
  cout << "Vektor: " << vec[0] << endl;
  
  float i = vec.at(2);   // Element 2
  float j = vec.size();  // #Elemente
  
  cout << "Vektor [2]: " << i << endl;
  cout << "Vektor Groesse: " << j << endl;
  	
  return 0;
}

