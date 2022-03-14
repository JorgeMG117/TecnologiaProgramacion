#include "rational.h"

// Helper methods -----------------------
int Rational::mcd(int a, int b)
{
   return ( b == 0 ? a : mcd(b,a%b));
}

void Rational::reduce()
{
   int m = mcd(num, den);
   num /= m;
   den /= m;
}

// Constructor -----------------------
Rational::Rational(int num, int den) : num(num), den(den)
{
   reduce();
}

// Add -----------------------
Rational Rational::operator+(const Rational& that) const
{
	Rational r;

	r.num = num*that.den + den*that.num;
	r.den = den*that.den;
	r.reduce();

	return r;
};

Rational Rational::operator+(int k) const
{
	Rational r;

	r.num = num + den*k;
	r.den = den;
	r.reduce();

	return r;
};

Rational operator+(int i, const Rational& r)
{
   return r + i;
}

const Rational& Rational::operator+=(const Rational& that)
{
	num = num*that.den + den*that.num;
	den = den*that.den;
	reduce();

    return (*this);
}

const Rational& Rational::operator+=(int k)
{
	num += k*den;
	reduce();

    return (*this);
}


// Substract -----------------------
Rational Rational::operator-(const Rational& that) const
{
	Rational r;

	r.num = num*that.den - den*that.num;
	r.den = den*that.den;
	r.reduce();

	return r;
};

Rational Rational::operator-(int k) const
{
	Rational r;

	r.num = num - den*k;
	r.den = den;
	r.reduce();

	return r;
};

Rational operator-(int i, const Rational& r)
{
   return Rational(i) - r;
}

const Rational& Rational::operator-=(const Rational& that)
{
	num = num*that.den - den*that.num;
	den = den*that.den;
	reduce();

    return (*this);
}

const Rational& Rational::operator-=(int k)
{
	num -= k*den;
	reduce();

    return (*this);
}

// Multiply -------------------------
Rational Rational::operator*(const Rational& that) const
{
	Rational r;

	r.num = num*that.num;
	r.den = den*that.den;
	r.reduce();

	return r;
};

Rational Rational::operator*(int k) const
{
	Rational r;

	r.num = num*k;
	r.den = den;
	r.reduce();

	return r;
};

Rational operator*(int i, const Rational& r)
{
   return r * i;
}

const Rational& Rational::operator*=(const Rational& that)
{
	num *= that.num;
	den *= that.den;
	reduce();

    return (*this);
}

const Rational& Rational::operator*=(int i)
{
	num *= i;
	reduce();

    return (*this);
}


// Divide ------------------------------
Rational Rational::operator/(const Rational& that) const
{
	Rational r;

	r.num = num*that.den;
	r.den = den*that.num;
	r.reduce();

	return r;
};

Rational Rational::operator/(int k) const
{
	Rational r;

	r.num = num;
	r.den = den*k;
	r.reduce();

	return r;
};

Rational operator/(int i, const Rational& r)
{
   return Rational(i)/r;
}

const Rational& Rational::operator/=(const Rational& that)
{
	num *= that.den;
	den *= that.num;
	reduce();

    return (*this);
}

const Rational& Rational::operator/=(int i)
{
	den *= i;
	reduce();

    return (*this);
}


// Helper function ------------------------------
float Rational::value() const
{
	return float(num)/float(den);
}

Rational::operator float() const
{
	return float(num)/float(den);
}

// Input/output ---------------------------------
std::ostream& operator<<(std::ostream& os, const Rational& r)
{
 	os<< r.num<<"/"<<r.den;

	return os;
}

std::istream& operator>>(std::istream& is, Rational& r)
{
	is >> r.num;
	is.ignore(1000,'/');
	is >> r.den;

	return is;
}



