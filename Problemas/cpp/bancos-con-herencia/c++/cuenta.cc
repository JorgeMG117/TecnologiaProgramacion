#include "cuenta.h"
#include <cmath>

using namespace std;

Cuenta::Cuenta(double _capital) : capital(_capital)
{
}

double Cuenta::tae() const
{
	return 100.0*(valor(12)/valor(0) - 1);
}

void Cuenta::actualiza()
{
	capital = valor(1);
}
