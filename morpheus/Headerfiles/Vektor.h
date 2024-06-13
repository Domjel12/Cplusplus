//Headerdatei#
//die Funktionen werden nicht genauer spezifiziert, sondern nur erwähnt

#ifndef VEKTOR_H
#define VEKTOR_H

class Vektor{
public:
    static int dimension; 
    double x, y,z;
    Vektor(double a, double b, double c);   //:x(a),y(b),z(c){}                                        "brauchen wir nicht, wird nie erwähnt
    Vektor operator +(Vektor &b);        //{                                       
                                    //return Vektor(this->x + b.x, this->y + b.y, this->z + b.z);      "Hier genau so"
                                        //}

    void printMe();                          //{
                                    //cout << "<" << this->x << ", " << this->y << ", " << this->z << ">"; 
                                            //}
};
#endif


//wir erstellen nochmal ne neue File für die Codes der Funktion, die wir hier nicht nutzen können!