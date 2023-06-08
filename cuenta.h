//
// Created by Luchi on 30/5/2023.
//
#ifndef SISTEMA_DE_GESTION_CUENTA_H
#define SISTEMA_DE_GESTION_CUENTA_H
#include <iostream>
#include "transaccion.h"
using namespace std;

class cuenta{
private:
    int n_cliente;
    string nombre;
    string apellido;
    int anio;
    bool estado;
    int cant_transacciones = 0;
    float saldo;
    transaccion t[10];
public:
    cuenta(){};
    cuenta(int _n_cliente, string _nombre, string _apellido, int _anio, bool _estado, float _saldo);
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
    void crear_extraccion(float monto_deposito, int N, int _dia, int _mes, int _anio);
    float get_saldo();
    void set_saldo(float _saldo);
    void crear_deposito(float monto_extraccion, int N, int _dia, int _mes, int _anio);
    void cambiar_estado();
};


#endif //SISTEMA_DE_GESTION_CUENTA_H
