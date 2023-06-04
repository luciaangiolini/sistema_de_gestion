//
// Created by Luchi on 30/5/2023.
//

#ifndef SISTEMA_DE_GESTION_CUENTA_H
#define SISTEMA_DE_GESTION_CUENTA_H
#include <iostream>
using namespace std;

class cuenta {
    int n_cliente;
    string nombre;
    string apellido;
    int anio;
    bool estado;
public:
    cuenta(){};
    cuenta(int _n_cliente, string _nombre, string _apellido, int _anio, bool _estado);
    void set_n_cliente(int _n_cliente);
    int get_n_cliente();
    void set_nombre(string _nombre);
    string get_nombre();
    void set_apellido(string _apellido);
    string get_apellido();
    void set_anio(int _anio);
    int get_anio();
    void set_estado(bool _estado);
    bool get_estado();
};


#endif //SISTEMA_DE_GESTION_CUENTA_H
