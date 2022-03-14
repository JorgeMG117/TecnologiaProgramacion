#pragma once
#include "nodo.h"
#include <string>

using namespace std; 

class Fichero : public Nodo{
private:
    int size;
public:
    Fichero(const string& _name, int _size) : Nodo(_name), size(_size) {}
    int getSize() const override {return size;}

    void setSize(int _size) { size = _size; }
};
