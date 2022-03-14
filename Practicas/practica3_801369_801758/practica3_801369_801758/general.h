#pragma once
#include <string>
#include <iostream>
using namespace std;

class General{
protected:
    string nom;

public:
    General(string _nombre) : nom(_nombre) {}
    virtual string nombre() const { return nom; }
    virtual string to_string(int nivel) const = 0;
    string to_string() const { return to_string(0); }
    friend ostream& operator<<(ostream& os, const General& G);
};

ostream& operator<<(ostream& os, const General& G) {
    os << G.to_string();
    return os;
}