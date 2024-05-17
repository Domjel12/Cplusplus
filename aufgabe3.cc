#include <iostream>
#include <vector> 
#include <cassert>

using namespace std;

char tohex(int i){
    assert(i<15);
    if(i > 0 && i < 10) return (char) i;
    if (i == 10) return 'a';
    if (i == 11) return 'b';
    if (i == 12) return 'c';
    if (i == 13) return 'd';
    if (i == 14) return 'e';
    if (i == 15) return 'f';

    return ' ';

}

string hexadecimal(int n){

    string s;
    int k, m;

    while(k > 16 && m > 16){
        k = n/16;
        m = n%16;
    }

    cout << k << " " << m << endl;

    return s;
}

int main()
{
    int i = 1023;
    hexadecimal(i);
    cout << "Dezimale Zahl: " << i << " =>" << " in hexadezimal: " <<tohex(i) << endl;

    return 0;
  
}