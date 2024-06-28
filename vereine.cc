/*
 * vereine.cc
 * 
 * Copyright 2024 Erwin Hofffmann <erwin@fehcom.de>
 * 
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <fstream>
#include <sstream>

typedef std::vector<std::string> Vereine;

int load(Vereine& v)
{
  string fn = "bundesliga_tabelle.csv";

  ifstream input(fn,std::ios::app);
  if (!input.is_open()){
    cout << "Konnte Datei " << fn << " nicht öffnen" << endl;
    return -1;
  }

  for (string line, field; getline(input, line) ; )
    if (!(line.empty() || line.at(0) == '#' || line.at(0) == ' ')) {
      stringstream s(line);
      int i = 0;
      while (getline(s,field,s.widen('|'))){
        i++;
        if (i == 2) v.push_back(field);
      }
    }
  
/*
  v.push_back("Bayer Leverkusen");  
  v.push_back("1. FC Koeln");
  v.push_back("Borussia Moenchengladbach");
  v.push_back("Eintracht Frankfurt");
  v.push_back("Kickers Offenbach");
  v.push_back("SV Darmstadt 98");  // 5
  v.push_back("Bayern Muechnen");
  v.push_back("Union Berlin");
  v.push_back("FC St. Pauli");
*/
  return v.size();
}

void print(Vereine v)
{
  for (int i=0; i < v.size(); i++)
    std::cout << "Verein: " << v.at(i) << " (" << i << ")" << std::endl;
  std::cout << std::endl;
}

int main()
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

