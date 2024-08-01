#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
using namespace std;

class Medien{
private:
    string titel;
    int jahr;
public:
    Medien(string t, int j): titel(t), jahr(j)
    {
        cout << "Medien wurden erstellt: " <<  " Titel: " << titel << " Veröffentlicht: " << jahr << endl;
    }
    virtual void ShowInfo(){cout << "Titel: " << titel << " Veröffentlicht: " << jahr << endl;}

    virtual ~Medien(){cout << "gelöscht" << endl;};
};

class Buch: public Medien{
private:
    string autor;
    string isbn;
public:
    Buch(string t, int j, string a, string i): Medien(t, j), autor(a), isbn(i)
    {
        
    }

    void ShowInfo()override{cout <<  " Autor: " << autor << " ISBN: " << isbn << endl;};
};

class Zeitschrift: public Medien{
private:
    string herausgeber;
    int ausgabe;
public:
    Zeitschrift(string t, int j, string h, int a): Medien(t, j), herausgeber(h), ausgabe(a)
    {
        cout << "Zeitschrift wurde erstellt: " << " herausgeber: " << herausgeber << " Ausgabe: " << ausgabe << endl;
    }
    void ShowInfo()override{ cout << " herausgeber: " << herausgeber << " Ausgabe: " << ausgabe << endl;}
};

class Bibliothek{
private:
    vector<shared_ptr<Medien>> medienliste;
public:
    void AddMedia(shared_ptr<Medien> media){
        medienliste.push_back(media);
    };
    void ShowAllMedia( ){
        for (const auto& media : medienliste) {
            media->ShowInfo();
            std::cout << std::endl;
        }
    };
};


int main(){

    shared_ptr<Medien> b1(new Buch("Katze zuhause!", 1999, "Felix Hund", "A1214890"));

    Bibliothek bib;
    bib.AddMedia(b1);

    bib.ShowAllMedia();


    
    return 0;
}