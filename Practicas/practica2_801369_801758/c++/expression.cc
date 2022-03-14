#include "expression.h"
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

Expression::Expression(const string& exp){
	parse(exp);
}


void Expression::parse(const string& s)
{
	istringstream ss(s);
	string tok;

	// Pila de términos
	// Consulta el tipo de datos 'stack' de la STL
	stack <Nodo*> stk;

	while (ss >> tok)
	{
		if (tok=="+")
		{
			// Apilar suma
			Nodo* r = stk.top();
			stk.pop();
			Nodo* l = stk.top();
			stk.pop();
			Suma* o = new Suma(l, r);
			stk.push(o);
		}
		else if (tok=="-")
		{
			// Apilar resta
			Nodo* r = stk.top();
			stk.pop();
			Nodo* l = stk.top();
			stk.pop();
			Resta* o = new Resta(l, r);
			stk.push(o);
		}
		else if (tok=="*")
		{
			// Apilar producto
			Nodo* r = stk.top();
			stk.pop();
			Nodo* l = stk.top();
			stk.pop();
			Multiplicacion* o = new Multiplicacion(l, r);
			stk.push(o);
		}
		else if (tok=="/")
		{
			// Apilar cociente
			Nodo* r = stk.top();
			stk.pop();
			Nodo* l = stk.top();
			stk.pop();
			Division* o = new Division(l, r);
			stk.push(o);
		}
		else
		{
			// Variable o constante
			// Si comienza por un caracter no numerico,
			// es un nombre de variable
			if (isalpha(tok[0]))
			{
				// Apilar variable
				stk.push(new Variable(tok));
			}
			else
			{
				float f = stof(tok);
				// Apilar constante
				stk.push(new Constante(f));
			}
		}
	}

	root = stk.top();// cima de la pila
}

float Expression::eval(const SymbolTab& syms) const
{
	// Devuelve el resultado de evaluar la expresion
	return root->eval(syms);
}

string Expression::to_string() const
{
	// Devuelve la cadena que representa la expresion
	return root->toString();
}

ostream& operator<<(ostream& os,const Expression& e)
{
    os << fixed << setprecision(2) << e.to_string();

    return os;
}

