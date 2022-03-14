#pragma once
#include "nodo.h"
#include "arbol_ficheros_error.h"
#include <string>
#include <list>
#include <memory>

using namespace std; 

class Directorio : public Nodo{
protected:
    list <shared_ptr<Nodo>> lista;
public:
    Directorio(string _name) : Nodo(_name) {}

    int getSize() const override {
        int size = 0;
        for (const auto& e : lista) {
            size+= e->getSize();
        }
        return size;
    }

    string getFiles() {
        string chain;
        for (const auto& e : lista) {
            chain = chain + e->getName() + "\n";
        }
        return chain;
    }

    string getDu(){
        string chain;
        for (const auto& e : lista) {
            chain = chain + e->getName() + " " + to_string(e->getSize()) + "\n";
        }
        return chain;
    }

    shared_ptr<Nodo> exists(string name){
        for (const auto& e : lista) {
            if(e->getName()==name){
                return e;
            }
        }
        return nullptr;
    }

    void editFile(string name, int size) {
        shared_ptr<Nodo> isFile = exists(name);
        if(isFile == nullptr){
            //Creamos fichero
            shared_ptr<Fichero> file = make_shared <Fichero>(name, size);
            lista.push_back(file);

        }
        else{
            //Cambiamos tamaño del fichero
            shared_ptr<Fichero> file = dynamic_pointer_cast<Fichero>(isFile);
            if(file == nullptr) {throw is_not_file(name);}
            file -> setSize(size);
        }
    }


    void makeDir(string name) {
        shared_ptr<Nodo> isDir = exists(name);
        if(isDir!=nullptr) { throw error_file_exists("mkdir: cannot create directory" ,name); }

        shared_ptr<Directorio> dir = make_shared <Directorio>(name);
        lista.push_back(dir);
    }

    void makeLink(string name, shared_ptr<Nodo> nodo){
        // Buscamos a ver si existe un nodo con el nombre del enlace que queremos crear
        shared_ptr<Nodo> isLink = exists(name);
        if(isLink!=nullptr) { throw error_file_exists("ln: failed to create hard link", name); }

        shared_ptr<Enlace> link = make_shared <Enlace>(name, nodo);

        lista.push_back(link);
    }

    void rmNodo(shared_ptr<Nodo> nodo) {
        lista.remove(nodo);
    }


};
