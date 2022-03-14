#include "plazo-fijo.h"

PlazoFijo::PlazoFijo(double _capital, double _interes, int _plazo)
	: Cuenta(_capital), interes(_interes), plazo(_plazo)
{
}

double PlazoFijo::valor(int t) const
{
	return (t<plazo ? capital : capital*(1.0+interes/100.0));
}

void PlazoFijo::actualiza()
{
	if (plazo >= 0) plazo--;
	if (plazo == 0) capital *= (1.0+interes/100.0);
}
