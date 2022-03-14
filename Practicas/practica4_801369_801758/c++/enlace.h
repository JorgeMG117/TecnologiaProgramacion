#pragma once
#include "nodo.h"
#include <memory>

using namespace std; 

class Enlace : public Nodo{
protected:
    shared_ptr<Nodo> org;

public:
    Enlace(const string& name, shared_ptr<Nodo> param) : Nodo(name), org(param) {}
    int getSize() const override {return org -> getSize();}
};