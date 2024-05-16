/*
 * new_delete.cxx
 * 
 * Copyright 2024 Erwin Hofffmann <erwin@fehcom.de>
 * 
 */

#include <iostream>

using namespace std;

int main()
{
  float* f1 = new float;
  float* f2 = new float(3.1415);

  cout << "f2: " << f2 << " Value: " << *f2 << endl;

  delete f1;
  delete f2;

  char* buffer = new char[128];
  strcpy(buffer,"Hello World!");;

  cout << "Buffer: " << buffer << endl;

  delete[] buffer;
  delete[] buffer;


  return 0;
}

