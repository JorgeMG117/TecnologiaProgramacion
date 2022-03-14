#include "cuenta-corriente.h"
#include <cmath>

using namespace std;

CuentaCorriente::CuentaCorriente(double _capital, double _interes)
	: Cuenta(_capital), interes(_interes)
{
}

double CuentaCorriente::valor(int t) const
{
	return capital*pow(1.0 + interes/100.0,t);
}
