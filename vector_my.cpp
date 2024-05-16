/*
 * vector_my.cxx
 * 
 * Copyright 2024 Erwin Hofffmann <erwin@fehcom.de>
 * 
 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> Vektor = { 42, 43, 44, 45 };

int main()
{
	
  vector<int> my_vec;
  
  my_vec = Vektor; // Zuweisung
  
  for (int i = 0; i < my_vec.size(); i++)
    cout << "Vektor Element 'my_vec': " << my_vec.at(i) << endl;
  
  return 0;
}

