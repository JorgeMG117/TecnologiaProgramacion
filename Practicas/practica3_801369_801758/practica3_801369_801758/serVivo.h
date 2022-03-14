#pragma once
#include <string>
#include "cargaGeneral.h"

class SerVivo : public CargaGeneral{
public:
    SerVivo(string _nombre, double _volumen, double _peso) : CargaGeneral(_nombre, _volumen, _peso) {}
    static string tipo(){
        return "Seres Vivo";
    }
};