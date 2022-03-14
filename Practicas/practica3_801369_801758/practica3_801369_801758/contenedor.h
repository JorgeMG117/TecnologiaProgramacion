#pragma once

#include "carga.h"
#include "almacen.h"
#include <string>

template <typename T>
class Contenedor: public Carga, public Almacen<T>{
public:
    Contenedor(double _volumen) : Carga("Contenedor", _volumen, 0), Almacen<T>(_volumen) {}

    string to_string(int nivel) const override {
        return nombre() + " ["  + std::to_string(volumen()) + " m3] [" 
                + std::to_string(peso()) + " kg]\n" + Almacen<T>::to_string(nivel+1);
    };

    string nombre() const override {
        return nom + " de " + T::tipo(); 
    }

    double peso() const override {
        return Almacen<T>::peso();
    }

};