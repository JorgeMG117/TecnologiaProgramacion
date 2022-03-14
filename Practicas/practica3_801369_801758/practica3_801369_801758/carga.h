#pragma once

#include "cargaGeneral.h"
#include <string>

class Carga : public CargaGeneral{
public:
    Carga(string _nombre, double _volumen, double _peso) : CargaGeneral(_nombre, _volumen, _peso) {}

    static string tipo(){
        return "Carga Estandar";
    }
};