#include <iostream>
#include <cmath>
#include <memory>

using namespace std;


class Form {
	public:
		const float pi = 3.14;
		virtual void Ausgabe() const = 0;
		virtual float Fläche() const = 0;
		virtual float Umfang() const = 0;
		virtual float Volumen() const = 0;
		virtual ~Form() = default;
};

class TwoDim : public Form {
	public:
		virtual float Umfang() const = 0;
};

class ThreeDim : public Form {
	public:
		virtual float Volumen() const = 0;
};

class Kreis : public TwoDim {
	private:
		float radius;
		
	public:
		Kreis(float r) : radius(r) {} ;		//Konstruktor
		
		void Ausgabe() const override { std::cout << "Kreis mit dem Radius: " << radius << "." << std::endl;};
		float Umfang() const override { return 2*Form::pi*radius;};
		float Fläche() const override { return Form::pi*radius*radius;};
		float Volumen() const override { return 0;};		//sinnlos für kreis, aber wegen virtueller vererbung muss hier genutzt werden
};		

class Dreieck : public TwoDim {
	private:
		float seite1, seite2, seite3;
	
	public:
		Dreieck(float s1, float s2, float s3) : seite1(s1), seite2(s2), seite3(s3) {};		//Konstruktor
		
		void Ausgabe() const override { std::cout << "Dreieck mit Seitenlängen " << seite1 << ", " << seite2 << ", " << seite3 << "." << std::endl;};
		float Fläche() const override { 
			float S = Umfang() / 2;
			return std::sqrt(S*(S-seite1)*(S-seite2)*(S-seite3));
		}	
		float Umfang() const override { return (seite1+seite2+seite3) ;};
		float Volumen() const override { return 0;};			//sinnlos, aber wegen virtueller vererbung muss hier genutzt werden	
};

class Rechteck : public TwoDim {
	protected:
		float länge, breite;
	public:
		Rechteck(float l, float b) : länge(l), breite(b) {};			//Konstruktor
		
		void Ausgabe() const override { std::cout << "Rechteck mit Länge " << länge << " und Breite " << breite << " ." << std::endl;};
		float Umfang() const override { return 2*länge+2*breite; };
		float Fläche() const override { return länge*breite; };
		float Volumen() const override { return 0;};	//sinnlos, aber wegen virtueller vererbung muss hier genutzt werden
};

class Quadrat : public Rechteck {
		public:
		Quadrat(float seite) : Rechteck(seite, seite) {}				//Konstruktor mit übergabe der seite an rechteck
		
		void Ausgabe() const override { std::cout << "Quadrat mit der Seitenlänge " << länge << "." << std::endl;}						//TEST OB seite geht, sonst Länge
};
		
class Kasten : public ThreeDim {
	private:
		float länge, breite, höhe;
	public:
		Kasten(float l, float b, float h) : länge(l), breite(b), höhe(h) {};
		
		void Ausgabe() const override { std::cout << "Kasten mit Länge " << länge << ", Breite " << breite << " und Höhe " << höhe << "." << std::endl;};
		float Fläche() const override { return 2 * (länge * breite + länge * höhe + breite * höhe);};
		float Volumen() const override { return länge*breite*höhe;}
		float Umfang() const override { return 0;};	//sinnlos, aber wegen virtueller vererbung muss hier genutzt werden
};

class Kugel : public ThreeDim {
	private:
		float radius;
	public:
		Kugel(float r) : radius(r) {};
		
		void Ausgabe() const override { std::cout << "Kugel mit Radius: " << radius << "." << std::endl;};
		float Fläche() const override { return (4*radius*radius*Form::pi); };
		float Volumen() const override { return (4/3*radius*radius*radius*Form::pi);}
		float Umfang() const override { return 0;};		//sinnlos, aber wegen virtueller vererbung muss hier genutzt werden
};
		
int main()
{
	//Smart Pointer für ein Kreis-Objekt
	std::unique_ptr<Form> kreis(new Kreis(5.0));
	//Methoden
	kreis->Ausgabe();
	cout << "Umfang: " << kreis->Umfang() << endl;
	cout << "Fläche: " << kreis->Fläche() << "\n" << endl;
	
	std::unique_ptr<Form> dreieck(new Dreieck(5,5,5));
	dreieck->Ausgabe();
	cout << "Umfang: " << dreieck->Umfang() << endl;
	cout << "Fläche: " << dreieck->Fläche() << "\n" <<endl;
	
	std::unique_ptr<Form> rechteck(new Rechteck(5,5));
	rechteck->Ausgabe();
	cout << "Umfang: " << rechteck->Umfang() << endl;
	cout << "Fläche: " << rechteck->Fläche() << "\n" << endl;
	
	std::unique_ptr<Form> quadrat(new Quadrat(5));
	quadrat->Ausgabe();
	cout << "Umfang: " << quadrat->Umfang() << endl;
	cout << "Fläche: " << quadrat->Fläche() << "\n" << endl;
	
	std::unique_ptr<Form> kasten(new Kasten(5,5,5));
	kasten->Ausgabe();
	cout << "Fläche: " << kasten->Fläche() << endl;
	cout << "Volumen: " << kasten->Volumen() << "\n" << endl;
	
	std::unique_ptr<Form> kugel(new Kugel(5));
	kugel->Ausgabe();
	cout << "Fläche: " << kugel->Fläche() << endl;
	cout << "Volumen: " << kugel->Volumen() << "\n" << endl;
	
	
	
	return 0;
}

