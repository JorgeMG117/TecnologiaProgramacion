#pragma once

#include <iostream>
#include <iomanip>
#include "nodo.h"
#include "symboltab.h"

class Expression
{
private:
	// Raiz del arbol de terminos
	Nodo* root;

	void	parse(const string& s);

	string to_string() const;

public:
	// Constructores
	Expression(const string& exp);

	float	eval(const SymbolTab& syms) const;

	friend ostream& operator<<(ostream& os,const Expression& e);
};

ostream& operator<<(ostream& os,const Expression& e);
