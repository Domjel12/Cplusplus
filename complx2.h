#ifndef COMPLX_H
#define COMPLX_H

namespace ToComplx{
  class Complx {
    private:
      double re;
      double im;
    public:
      Complx(double r, double i) : re{r}, im{i} { }; // Konstruktor
      Complx(double r) : re{r}, im{0.0} { };         // Konstruktor mit im=0
      Complx() : re{0.0}, im{0.0} { };               // Konstruktor re=im=0
      ~Complx() {};                                  // Destruktor
      Complx(const Complx& z) : re(z.re), im(z.im) { }; // Copy Konstruktor
      
      double real() const { return re; };            // Getter -> const
      double imag() const { return im; };
      void real(double r) { re = r; }                // Setter
      void imag(double i) { im = i;  }

 // Eigene Memberfunktionen: ComplxAdd, ComplxSub, ComplxMult => Return by Reference

      Complx& operator+=(Complx z) { re += z.re; im += z.im; return *this; }
      Complx& operator-=(Complx z) { re -= z.re; im -= z.im; return *this; }
      Complx& operator*=(Complx z) { re = re*z.re - im*z.im; im = re*z.im + im*z.re; return *this; }
   };
};
#endif // Datei: complx2.h

