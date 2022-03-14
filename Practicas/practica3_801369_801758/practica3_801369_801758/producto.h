#pragma once
#include "carga.h"
#include <string>

class Producto : public Carga{
public:
    Producto(string _nombre, double _volumen, double _peso) : Carga(_nombre, _volumen, _peso) {}
};