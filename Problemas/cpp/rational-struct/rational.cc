#include "rational.h"

// Helper functions -----------------------
int mcd(int a, int b) {
   return ( b == 0? a : mcd(b,a%b));
}

void reduce(Rational& r) {
   int m = mcd(r.num, r.den);
   r.num /= m; r.den /= m;
}

// Constructor -----------------------
Rational rational(int num, int den) {
   Rational sol;
   sol.num = num; sol.den = den;
   reduce(sol);
   return sol;
}

// Add -----------------------
Rational add(const Rational& r1, const Rational& r2) {
   return rational(r1.num*r2.den + r1.den*r2.num, r1.den*r2.den);
}

Rational add(const Rational& r, int i) {
   return rational(r.num+(i*r.den), r.den);
}

Rational add(int i, const Rational& r) {
   return add(r,i);
}

// Substract -----------------------
Rational substract(const Rational& r1, const Rational& r2) {
   return add(r1, rational(-r2.num, r2.den));
}

Rational substract(const Rational& r, int i) {
   return add(r,-i);
}

Rational substract(int i, const Rational& r) {
   return add(rational(-r.num, r.den), i);
}

// Multiply -------------------------
Rational multiply(const Rational& r1, const Rational& r2) {
   return rational(r1.num*r2.num, r1.den*r2.den);
}

Rational multiply(const Rational& r, int i) {
   return rational(i*r.num, r.den);
}

Rational multiply(int i, const Rational& r) {
   return multiply(r,i);
}

// Divide ------------------------------
Rational divide(const Rational& r1, const Rational& r2) {
   return rational(r1.num*r2.den, r1.den*r2.num);
}

Rational divide(const Rational& r, int i) {
   return rational(r.num, r.den*i);
}

Rational divide(int i, const Rational& r) {
   return rational(i*r.den, r.num);
}

// Helper function ------------------------------
float value(const Rational& r) {
	return float(r.num)/float(r.den);
}

// Input/output ---------------------------------
void write(const Rational& r, std::ostream& os) {
 	os<< r.num<<"/"<<r.den;
}

void read(Rational& r, std::istream& is) {
	is >> r.num;
	is.ignore(1);
	is >> r.den;
}


