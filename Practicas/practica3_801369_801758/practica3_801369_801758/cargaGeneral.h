#pragma once

#include "general.h"
#include <string>
#include <cmath>
using namespace std;

class CargaGeneral : public General{
protected:
    double vol;
    double pes;
public:
    CargaGeneral(string _nombre, double _volumen, double _peso) : General(_nombre), vol(_volumen), pes(_peso) {}
    virtual double peso() const { return pes; }
    double volumen() const { return vol; }
    string to_string(int nivel) const override{
        return  nombre() + " ["  + std::to_string(volumen()) + " m3] [" + std::to_string(peso()) + " kg]\n";
    }
};