/*
 * vereine.cc
 * 
 * Copyright 2024 Erwin Hofffmann <erwin@fehcom.de>
 * 
 */


#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> Vereine;

int load(Vereine& v)
{
  v.push_back("Bayer Leverkusen");  
  v.push_back("1. FC Koeln");
  v.push_back("Borussia Moenchengladbach");
  v.push_back("Eintracht Frankfurt");
  v.push_back("Kickers Offenbach");
  v.push_back("SV Darmstadt 98");  // 5
  v.push_back("Bayern Muechnen");
  v.push_back("Union Berlin");
  v.push_back("FC St. Pauli");

  return v.size();
}

void print(Vereine v)
{
  for (int i=0; i < v.size(); i++)
    std::cout << "Verein: " << v.at(i) << " (" << i << ")" << std::endl;
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  int anz;
  Vereine v; // leer
    
  anz = load(v);
  
  std::cout << "Anzahl Bundesligavereine: " << anz << "\n" << std::endl;
  print(v);
  
  int p = 5;  // Darmstadt steht auf Position 5
  std::cout << v.at(p) << "\n" << std::endl;
    
  v.erase(v.begin());  // Bayer Leverkusen ist raus
  print(v);

  std::vector<std::string>::iterator it; // neuer Datentyp: Iterator
  it = v.begin() + p - 1;                // '+' und '-' sind Ueberladen
   
  v.erase(it);  // Darmstadt ist raus
  print(v);
 
	return 0;
}

