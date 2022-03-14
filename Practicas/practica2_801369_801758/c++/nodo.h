#pragma once

#include <iostream>
#include <string>
#include "symboltab.h"

class Nodo
{
public:
    virtual string toString() const = 0;
    virtual float eval(const SymbolTab& syms) const = 0;
};

class Operacion
{
protected:
    Nodo* izq;
    Nodo* der;

public:
    Operacion(Nodo* _izq, Nodo* _der);
};

class Suma : public Nodo, public Operacion
{
public:
    Suma(Nodo* _izq, Nodo* _der);
    string toString() const override;
    float eval(const SymbolTab& syms) const override;
};

class Resta : public Nodo, public Operacion
{
public:
    Resta(Nodo* _izq, Nodo* _der);
    string toString() const override;
    float eval(const SymbolTab& syms) const override;
};

class Multiplicacion : public Nodo, public Operacion
{
public:
    Multiplicacion(Nodo* _izq, Nodo* _der);
    string toString() const override;
    float eval(const SymbolTab& syms) const override;
};

class Division : public Nodo, public Operacion
{
public:
    Division(Nodo* _izq, Nodo* _der);
    string toString() const override;
    float eval(const SymbolTab& syms) const override;
};

class Variable : public Nodo
{
private:
    string variable;
public:
    Variable(string _variable);
    string toString() const override;
    float eval(const SymbolTab& syms) const override;
};

class Constante : public Nodo
{
private:
    float constante;
public:
    Constante(float _constante);
    string toString() const override;
    float eval(const SymbolTab& syms) const override;
};
