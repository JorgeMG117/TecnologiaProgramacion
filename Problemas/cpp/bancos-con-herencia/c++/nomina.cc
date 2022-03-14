#include "nomina.h"

Nomina::Nomina(double _sueldo)
	: Cuenta(_sueldo), sueldo(_sueldo)
{
}

double Nomina::valor(int t) const
{
	return capital + t*sueldo;
}
