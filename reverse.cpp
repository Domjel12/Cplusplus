#include <iostream>
#include <string>
using namespace std;


void reverse(string& s){
    int n = s.length();
        for(int i=0; i < n/2; i++){
            swap(s[i], s[n - i - 1]);
        }
    
}

int main(){
    string s = "Homer";
    cout << "Name: " << s << endl;
    reverse(s);
    cout << "Umgedreht: " << s << endl;





    
    return 0;
}