#pragma once

#include "cuenta.h"

class Nomina : public Cuenta
{
private:
	double sueldo;

public:
	Nomina(double _sueldo);

	// Implementa el calculo del valor
	double valor(int t) const override;
};
