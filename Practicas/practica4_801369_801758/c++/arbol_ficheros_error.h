#pragma once
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class arbol_ficheros_error : public runtime_error {
public:
    arbol_ficheros_error(const string& msg) : runtime_error(msg) {}
};

class error_node_not_found : public arbol_ficheros_error {
public:
    error_node_not_found(string _command, string _path) : arbol_ficheros_error(_command +": failed to access '" + _path + "': No such file or directory.") {}
};

class error_file_exists : public arbol_ficheros_error {
public:
    error_file_exists(string _command, string _name) : arbol_ficheros_error(_command + " '" +_name + "': File exists.") {}
};


class is_not_file : public arbol_ficheros_error {
public:
    is_not_file(string _name) : arbol_ficheros_error("vi: failed to access '"+_name+ "' is not a file.") {}
};
