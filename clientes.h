//
// Created by Luchi on 30/5/2023.
//
#ifndef SISTEMA_DE_GESTION_CLIENTES_H
#define SISTEMA_DE_GESTION_CLIENTES_H
#include <fstream>
#include "cuenta.h"
#include <iostream>
#pragma once

using namespace std;

class clientes{
private:
    string tipo;
    string nombre;
    string apellido;
    float tarjeta;
public:
    cuenta cuenta_datos;
    clientes(){};
    clientes(int _n_cliente, string _nombre, string _apellido, int _anio, bool _estado, string _tipo);
     void set_nombre(string _nombre);
    string get_nombre();
    void set_apellido(string _apellido);
    string get_apellido();
    void set_tipo(string _tipo);
    string get_tipo();
    void start();
    void set_tarjeta (float _limite);
    float get_tarjeta ();
    void alta_cliente (clientes *c,int n_clientes);
};

#endif //SISTEMA_DE_GESTION_CLIENTES_H
