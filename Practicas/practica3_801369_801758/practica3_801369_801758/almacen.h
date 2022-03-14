#pragma once

#include <list>
#include <string>

template <typename T>
class Almacen{
    protected:
        double capacidad;
        list<T*> lista;
    public:
        Almacen(double _capacidad) : capacidad(_capacidad) {}
        bool guardar(T& elemento) {
            if(capacidad >= elemento.volumen()) {
                capacidad -= elemento.volumen();
                lista.push_back(&elemento);
                return true;
            }
            return false;
        }

        double peso() const {
            double pes;
            for (const auto& e : lista) {
                pes+= e->peso();
            }

            return pes;
        }

        string to_string(int nivel) const {
            string cadena;
            for (const auto& e : lista) {
                for(int i=0; i<nivel; i++){
                    cadena = cadena + "  ";
                }
                cadena = cadena + e->to_string(nivel + 1);
            }   
            return cadena;
        }
};