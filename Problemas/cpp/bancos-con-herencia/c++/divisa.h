#pragma once

#include "cuenta.h"

class Divisa : public Cuenta
{
private:
	// Nota: al heredar de "Cuenta", heredamos el atributo "capital",
	// que en este caso es innecesario.
	// Otra solución podría ser mover dicho atributo a todos los hijos menos
	// a "Divisa", lo cual dejaría a "Cuenta" prácticamente como un interfaz,
	// y el metodo actualizar habria que pasarlo a los hijos.
	double	ratio;
	Cuenta&	otra;

public:
	Divisa(double _ratio, Cuenta& _otra);

	// Implementa el calculo del valor
	double	valor(int t) const override;
	// Redefine la forma de actualizarse
	void	actualiza() override;
};
