#pragma once

#include "general.h"
#include "almacen.h"
#include <string>

class Camion : public General, public Almacen<Carga> {
public:
    Camion(double _capacidad) : General("Camion"), Almacen<Carga>(_capacidad) {}
    
    string to_string(int nivel) const override {
        string cadena = nombre() + "\n";
        cadena = cadena + Almacen<Carga>::to_string(nivel + 1);
        return cadena;
    };

};