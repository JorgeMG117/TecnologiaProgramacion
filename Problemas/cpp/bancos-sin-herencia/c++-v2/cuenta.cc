#include "cuenta.h"
#include <cmath>

// Para invoke
// Desde C++-2017
#include <functional>

using namespace std;

Cuenta::Cuenta(Tipo _tipo,double _capital,double _interes,int _plazo)
	:	tipo(_tipo),
		capital(_capital), interes(_interes), plazo(_plazo)
{
	switch(tipo)
	{
		case CORRIENTE:
			valor_impl = &Cuenta::valor_corriente;
			break;
		case PLAZO:
			valor_impl = &Cuenta::valor_plazo;
			break;
	}
};

Cuenta::Cuenta(double _capital,double _interes)
	:	Cuenta(CORRIENTE,_capital,_interes)
{
}

Cuenta::Cuenta(double _capital,double _interes,int _plazo)
	:	Cuenta(PLAZO,_capital,_interes,_plazo)
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
	// Llamanda manual con el operaador '->*'
	return (this->*valor_impl)(t);
	// Llamada mediante std::invoke()
//	return std::invoke(valor_impl,this,t);
}

double Cuenta::tae() const
{
	return 100.0*(valor(12)/valor(0) - 1);
}
