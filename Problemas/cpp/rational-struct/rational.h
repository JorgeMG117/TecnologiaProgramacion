#pragma once

#include <iostream>

// Solution with public attributes and all functions.
struct Rational {
   int num, den;
};

int mcd(int a, int b);
void reduce(Rational& r);
Rational rational(int num, int den = 1);
Rational add(const Rational& r1, const Rational& r2);
Rational add(const Rational& r, int i);
Rational add(int i, const Rational& r);
Rational substract(const Rational& r1, const Rational& r2);
Rational substract(const Rational& r, int i);
Rational substract(int i, const Rational& r);
Rational multiply(const Rational& r1, const Rational& r2);
Rational multiply(const Rational& r, int i);
Rational multiply(int i, const Rational& r);
Rational divide(const Rational& r1, const Rational& r2);
Rational divide(const Rational& r, int i);
Rational divide(int i, const Rational& r);
float value(const Rational& r);
void write(const Rational& r, std::ostream& os = std::cout);
void read(Rational& r, std::istream& is = std::cin);

