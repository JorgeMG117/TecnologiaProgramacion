#pragma once

#include "cuenta.h"

class PlazoFijo : public Cuenta
{
private:
	double interes;
	int    plazo;

public:
	PlazoFijo(double _capital, double _interes, int _plazo);

	// Implementa el calculo del valor
	double valor(int t) const override;
	// Redefine la forma de actualizarse
	void   actualiza() override;
};
