#pragma once


// Solución usando punteros a métodos

class Cuenta
{
public:
	enum Tipo { CORRIENTE, PLAZO };

private:
	Tipo	tipo;
	// Comun
	double	capital;
	// Si es cuenta corriente, tipo de interes mensual en %.
	// Si es plazo fijo, tipo de interes en % cuando se acaba el plazo.
	double	interes;
	// Si es plazo fijo, tiempo (en meses)
	//	hasta que vence el plazo (no da dinero antes)
	int		plazo;

	double valor_corriente(int t) const;
	double valor_plazo(int t) const;

	// Puntero al metodo elegido para implementar valor()
	double (Cuenta::*valor_impl)(int t) const;

public:
    //Constructor general
	Cuenta(Tipo _tipo,double _capital,double _interes,int _plazo=0);
    //Constructor que crea un plazo fijo (hay un plazo)
	Cuenta(double _capital,double _interes);
    //Constructor que crea un plazo fijo (no hay un parámetro plazo)
	Cuenta(double _capital,double _interes,int _plazo);

	double valor(int t) const;
	double tae() const;
};
