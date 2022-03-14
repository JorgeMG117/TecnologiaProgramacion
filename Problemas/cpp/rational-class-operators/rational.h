#pragma once
/*
En vez de ifndef, endif ... */

#include <iostream>

//- All methods, friend functions for symetric operators
//- All possible operators overloaded.
//- We add more operators than previous versions
//- Attributes private so they can only be accessed from the class.
class Rational
{
private:
   int num, den;

   static int mcd(int a, int b);
   void reduce();

public:
   Rational(int num = 0, int den = 1);

   Rational  operator+(const Rational& that) const; //Returning version
   Rational  operator+(int i) const;                //Returning version
   friend Rational operator+(int i, const Rational& r); //Commutative version
   const Rational& operator+=(const Rational& that);      //Inplace version
   const Rational& operator+=(int i);                     //Inplace version

   Rational  operator-(const Rational& that) const; //Returning version
   Rational  operator-(int i) const;                //Returning version
   friend Rational operator-(int i, const Rational& r); //Commutative version
   const Rational& operator-=(const Rational& that);      //Inplace version
   const Rational& operator-=(int i);                     //Inplace version

   Rational  operator*(const Rational& that) const; //Returning version
   Rational  operator*(int i) const;                //Returning version
   friend Rational operator*(int i, const Rational& r); //Commutative version
   const Rational& operator*=(const Rational& that);      //Inplace version
   const Rational& operator*=(int i);                     //Inplace version

   Rational  operator/(const Rational& that) const; //Returning version
   Rational  operator/(int i) const;                //Returning version
   friend Rational operator/(int i, const Rational& r); //Commutative version
   const Rational& operator/=(const Rational& that);      //Inplace version
   const Rational& operator/=(int i);                     //Inplace version

   float value() const;

   operator float() const;

   friend std::ostream& operator<<(std::ostream& os, const Rational& r); //Output
   friend std::istream& operator>>(std::istream& is, Rational& r);       //Input
};

Rational operator+(int i, const Rational& r);
Rational operator-(int i, const Rational& r);
Rational operator*(int i, const Rational& r);
Rational operator/(int i, const Rational& r);

/*Para acceder campos privados las meto
dentro con friend ademas de fuera
*/
std::ostream& operator<<(std::ostream& os, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& r);

