//
// Created by Luchi on 30/5/2023.
//
#ifndef SISTEMA_DE_GESTION_CLIENTES_H
#define SISTEMA_DE_GESTION_CLIENTES_H
#include "cuenta.h"
#include "transaccion.h"
#include "black.h"
#include "oro.h"
#include "plata.h"
#include <iostream>
#include <fstream>
using namespace std;

class clientes{
    string tipo;
public:
    cuenta cuenta_datos;
    clientes(int _n_cliente, string _nombre, string _apellido, int _anio, bool _estado, string _tipo);
    void set_tipo(string _tipo);
    string get_tipo();
    void start();
};

#endif //SISTEMA_DE_GESTION_CLIENTES_H
