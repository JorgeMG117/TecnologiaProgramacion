#pragma once
#include <iostream>
#include "nodo.h"
#include "enlace.h"
#include "fichero.h"
#include "directorio.h"
#include "arbol_ficheros_error.h"
#include <memory>
#include <list>
#include <string>


using namespace std; 

class Ruta {
private: 
    list <shared_ptr<Directorio>> route;

    shared_ptr<Nodo> getNode(string path) {
        Ruta routeAux(route);


        int pos = path.find_last_of('/');
        string nodo;
        if(pos != -1){  //No hay que cambiar de directorio
            string ruta = path.substr(0, pos);
            routeAux.cd(ruta);
            nodo = path.substr(pos+1,path.size()-pos-1);
        }
        else{nodo = path;}

        return routeAux.route.back()->exists(nodo);
    }

public:
    Ruta(Directorio* _raiz) {
        shared_ptr<Directorio> d;
        d = make_shared<Directorio>(_raiz->getName());
        route.push_back(d);
    }

    Ruta(list <shared_ptr<Directorio>> _route) : route(_route) {}
    
    string pwd() {
        string chain;
        for (const auto& e : route) {
            chain = chain + e->getName()  + "/";
        }
        return chain;
    }

    string ls() {
        return route.back()->getFiles();
    }

    string du() {
        return route.back()->getDu();
    }

    void vi(string name, int size) {
        route.back()->editFile(name, size);
    }

    void mkdir(string name){
        route.back()->makeDir(name);
    }

  
    void cd(string path) {
        bool relativa=true;
        if(path.at(0) == '/'){
            while(route.size() > 1) {
                route.pop_back();
            }
            path.erase(0,1);
            relativa=false;
        }
            
        string delimiter = "/";
        while(path != ""){
            int pos = path.find(delimiter);
            string field;
            if(pos == -1) { field = path; }
            else { field = path.substr(0, pos);}
            
            if(relativa && (field == "..")){
                if(route.size() > 1){
                    route.pop_back();
                }
            }
            else if(relativa && (field == ".")) {}
            else{
                shared_ptr<Nodo> isDir = route.back()->exists(field);
                shared_ptr<Directorio> dir = dynamic_pointer_cast<Directorio>(isDir); //Comprobar si es un dir
                
                //si esta añadir lista
                if(dir != nullptr) {route.push_back(dir);}
                else {break;}
                
            }
            if(pos == -1){ break; }
            path.erase(0, path.find(delimiter) + delimiter.length());
            
            
        }
    }


    void ln(string path, string name) {
        shared_ptr<Nodo> nodo = getNode(path);
        if(nodo == nullptr) {throw error_node_not_found("ln", path);}
        route.back() -> makeLink(name, nodo);
    }

    int stat(string path) {
        shared_ptr<Nodo> nodo = getNode(path);
        if(nodo == nullptr) {throw error_node_not_found("stat", path);}
        return nodo->getSize();
    }

    void rm(string path) {
        Ruta routeAux(route);


        int pos = path.find_last_of('/');
        string nodo;
        if(pos != -1){  //No hay que cambiar de directorio
            string ruta = path.substr(0, pos);
            routeAux.cd(ruta);
            nodo = path.substr(pos+1,path.size()-pos-1);

            
        }
        else{nodo = path;}

        shared_ptr<Nodo> removeNodo = routeAux.route.back()->exists(nodo);
        if(removeNodo == nullptr) {throw error_node_not_found("rm", path);}
        //Comprobar si existe
        routeAux.route.back()->rmNodo(removeNodo);
        
    }
};
