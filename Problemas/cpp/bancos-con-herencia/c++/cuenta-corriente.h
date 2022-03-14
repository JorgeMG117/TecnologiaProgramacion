#pragma once

#include "cuenta.h"

class CuentaCorriente : public Cuenta
{
private:
	double interes;

public:
	CuentaCorriente(double _capital, double _interes);

	// Implementa el calculo del valor
	double valor(int t) const override;
};
