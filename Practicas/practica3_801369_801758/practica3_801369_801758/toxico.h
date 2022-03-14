#pragma once
#include <string>
#include "cargaGeneral.h"

class Toxico : public CargaGeneral{
public:
    Toxico(string _nombre, double _volumen, double _peso) : CargaGeneral(_nombre, _volumen, _peso) {}

    static string tipo(){
        return "Productos Toxicos";
    }
};