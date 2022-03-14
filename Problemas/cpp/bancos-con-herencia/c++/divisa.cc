#include "divisa.h"

Divisa::Divisa(double _ratio, Cuenta& _otra)
	: Cuenta(0), ratio(_ratio), otra(_otra)
{
}

double Divisa::valor(int t) const
{
	return ratio*otra.valor(t);
}

void Divisa::actualiza()
{
	otra.actualiza();
}
