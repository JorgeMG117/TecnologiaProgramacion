#include "nodo.h"
#include <string>

// Constructores

Operacion::Operacion(Nodo* _izq, Nodo* _der) : izq(_izq), der(_der){}

Suma::Suma(Nodo* _izq, Nodo* _der) : Operacion(_izq, _der) {}

Resta::Resta(Nodo* _izq, Nodo* _der) : Operacion(_izq, _der) {}

Multiplicacion::Multiplicacion(Nodo* _izq, Nodo* _der) : Operacion(_izq, _der) {}

Division::Division(Nodo* _izq, Nodo* _der) : Operacion(_izq, _der) {}

Variable::Variable(string _variable) : variable(_variable){}

Constante::Constante(float _constante) : constante(_constante){}


// Funcion toString

string Constante::toString() const{
    string aux = to_string(constante);
	int pos = aux.find('.');
	aux.erase(pos+3);
	return aux;
}

string Variable::toString() const{
    return variable;
}

string Suma::toString() const{
	return "(" + izq->toString() + "+" + der->toString() + ")";
}

string Resta::toString() const{
	return "(" + izq->toString() + "-" + der->toString() + ")";
}

string Multiplicacion::toString() const{
	return izq->toString() + "*" + der->toString();
}

string Division::toString() const{
	return izq->toString() + "/" + der->toString();
}


// Funcion eval

float Constante::eval(const SymbolTab& syms) const{
    return constante;
}

float Variable::eval(const SymbolTab& syms) const{
	if(syms.count(variable) == 0){
		cout << "Error!!! " << variable << " no esta definida. Resultado incorrecto -> ";
		return 0;
	}
	else{
		return syms.find(variable)->second;
	}
}

float Suma::eval(const SymbolTab& syms ) const{ return izq->eval(syms) + der->eval(syms); }

float Resta::eval(const SymbolTab& syms ) const{ return izq->eval(syms) - der->eval(syms); }

float Multiplicacion::eval(const SymbolTab& syms ) const{ return izq->eval(syms) * der->eval(syms); }

float Division::eval(const SymbolTab& syms ) const{ return izq->eval(syms) / der->eval(syms); }
