#pragma once
#include <string>

using namespace std;

class Nodo {
private:
    string name;
public:
    Nodo(const string& _name) : name(_name) {}
    virtual int getSize() const = 0;
 
    string getName() const { return name; }
};
