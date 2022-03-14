#include "cuenta.h"
#include <cmath>

using namespace std;

Cuenta::Cuenta(Tipo _tipo,double _capital,double _interes,int _plazo)
	:	tipo(_tipo),
		capital(_capital), interes(_interes), plazo(_plazo)
{
};

Cuenta::Cuenta(double _capital,double _interes)
	:	tipo(CORRIENTE),
		capital(_capital), interes(_interes)
{
}

// Contructor delegado
Cuenta::Cuenta(double _capital,double _interes,int _plazo)
	:	Cuenta(PLAZO,_capital,_interes,_plazo)
/*
	:	tipo(PLAZO),
		capital(_capital), interes(_interes), plazo(_plazo)
*/
{
}

double Cuenta::valor_corriente(int t) const
{
	return capital*pow(1+(interes/100.0),t);
}

double Cuenta::valor_plazo(int t) const
{
	return (t<plazo ? capital : capital*(1+(interes/100.0)));
}

double Cuenta::valor(int t) const
{
	double res(0.0);

	switch(tipo)
	{
		case CORRIENTE:
			res = valor_corriente(t);
			break;
		case PLAZO:
			res = valor_plazo(t);
			break;
	}

	return res;
}

double Cuenta::tae() const
{
	return 100.0*(valor(12)/valor(0) - 1);
}
