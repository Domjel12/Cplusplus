#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
class Student{
    private:
       string name;
       int matrikel;
       string studiengang;
       T ects;
    public:
        Student(string n,int m,string s, T etcs):: name(n),studiengang(s), matrikel(m){
            cout << "Eingeschrieben: "<< s << " MatrNr: " << m << endl;
        } 
        void SetECTS(T t){ ects = t; }
        void InfoStud(){ cout << name << "ECTS:" << ects << endl;};

};
int main(){
    
    Student student1("Noop Nerdig", "Informatik", 1234,0.0);
    student1.SetECTS(7.5);

    student1.InfoStud();

    return 0;
}