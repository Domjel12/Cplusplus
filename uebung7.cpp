#include <iostream>
using namespace std;

class Form{
    public:
        const float pi = 3.14;
        virtual float flaeche(){ return 0;};  //getter
};

class TwoDim : public Form{
    public:
        virtual float Umfang() = 0;
};

class ThreeDim : public Form{
    public:
        virtual float Volumen() = 0;
};

class Kreis : public Form{ //Vererbung
    private:
        float radius;
    public:
        Kreis(float r) : radius(r){};
        float Umfang(){
            return 2*pi*radius;             //wir nutzen nicht math.h und M_PI
        };
        float Flaeche(){
            return (radius*radius)*pi;
        };
};

class Quadrat : public Form{
    private:
        float seite;
    public:
        Quadrat(float s) : seite(s){};
        float Umfang(){
            return seite*4;
        };
        float Flaeche(){
            return seite*seite;
        }

};

class Kugel : public ThreeDim{
    private:
        float radius;
    public:
        Kugel(float r) : radius(r) {};
        float Volumen(){ return(4/3*pi*radius*radius*radius);};
        float Flaeche(){ return(4*radius*radius*pi);};

};

class Rechteck : public TwoDim{
    private:
        float laenge;
        float breite;
    public:
        Rechteck(float l, float b) : laenge(l), breite(b){};
        float Umfang(){
            return 2*laenge+2*breite;
        };
        float Flaeche(){
            return laenge*breite;
        }

};

int main(){
    float r = 3.3;
    Kreis k = r;
    cout << "Umfang des Kreises: " << k.Umfang() << endl;
    cout << "Fläche des Kreises: " << k.Flaeche() << endl;

    float s = 2;
    Quadrat q = s;
    cout << "Umfang des Quadrates: " << q.Umfang() << endl;
    cout << "Fläche des Quadrates: " << q.Flaeche() << endl;

    Kugel K = r;
    cout << "Flaeche der Kugel: " << K.Flaeche() << endl;
    cout << "Volumen der Kugel : " << K.Volumen() << endl;

    Rechteck R {1.1,2.2};
    cout << "Umfang des Quadrates: " << R.Umfang() << endl;
    cout << "Fläche des Quadrates: " << R.Flaeche() << endl;

    return 0;
    }