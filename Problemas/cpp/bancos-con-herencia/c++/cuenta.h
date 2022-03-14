#pragma once

class Cuenta
{
protected:
	// Comun
	double capital;

public:
	Cuenta(double _capital);

	// Cada tipo de cuenta debe dar su implementación
	virtual double valor(int t) const = 0;

	// La clase base ofrece ya una implementación para todos
	double tae() const;

	// La clase base ofrece ya una implementación, que sirve
	// para la mayoria de los casos
	// Los casos especiales pueden redefinirla
	virtual void actualiza();
};
