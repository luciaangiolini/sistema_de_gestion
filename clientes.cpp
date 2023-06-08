//
// Created by Luchi on 30/5/2023.
//
#include "clientes.h"
#include "cuenta.h"
#include <iostream>
#pragma
using namespace std;

clientes::clientes(int _n_cliente, string _nombre, string _apellido, int _anio, bool _estado, string _tipo) {
    cuenta_datos.set_n_cliente(_n_cliente);
    cuenta_datos.set_anio(_anio);
    cuenta_datos.set_estado(_estado);
    tipo = _tipo;
}
void clientes::set_tipo(string _tipo) {
    tipo = _tipo;
}
string clientes::get_tipo() {
    return tipo;
}

void clientes::start() {
    int opcion;
    while (1==1){
        cout << "SISTEMA DE GESTION" << endl << endl;
        cout << "1 - Dar de alta un cliente" << endl;
        cout << "2 - Dar de baja un cliente" << endl;
        cout << "3 - Generar un depósito" << endl;
        cout << "4 - Generar una extracción" << endl;
        cout << "5 - Consultar datos (Ingresando su numero de cliente)" << endl;
        cout << "6 - Consultar todos los clientes" << endl;
        cout << "7 - Consultar transacciones por cliente" << endl;
        cout << "8 - Generar informe de transacciones por periodo de 6 meses" << endl;
        cout << "9 - Generar informe de transacciones por anio" << endl;
        cout << "10 - Generar informe total de transacciones" << endl;
        cout << "11 - Salir" << endl << endl << endl;
        cout << "Que desea hacer hoy? (Indique con el numero de cada opcion)" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:{
                clientes c[6];
                bool alta= false;
                int N=1, N_clientes=1;
                clientes::alta_cliente(c, N_clientes);
                break;
            }
            case 2:
                break;
            case 3:{
                cuenta::crear_deposito();
                break;
            }
            case 4: {
                cuenta::crear_extraccion();
                break;
            }
            case 5: {
                //Consultar datos por numero de cliente
                break;
            }
            case 6: {
                //Consultar datos de todos los clientes
                break;
            }
            case 7: {
                //Consultar transacciones por numero de clientes
                break;
            }
            case 8: {
                //Generar informe de transacciones por6 meses
                break;
            }
            case 9: {
                //Generar informe de transacciones por 1 anio
                break;
            }
            case 10: {
                //Generar informe total de transacciones
                break;
            }
            case 11:
                exit(EXIT_SUCCESS);
                break;
        }
    }
}
void clientes::set_nombre(string _nombre) {
    nombre = _nombre;
}
string clientes::get_nombre() {
    return nombre;
}
void clientes::set_apellido(string _apellido) {
    apellido = _apellido;
}
string clientes::get_apellido() {
    return apellido;
}
void clientes::set_tarjeta(float _limite) {
    tarjeta = _limite;
}
float clientes::get_tarjeta() {
    return tarjeta;
}

void alta_cliente (clientes *c, int n_clientes){
    string _nombre, _apellido;
    int _n_cliente, _anio;
    float _saldo;
    bool _estado;

    cout << "ingrese nombre, apellido, saldo y año de incorporacion"<<endl;
    cin >> _nombre>>_apellido>> _saldo>> _anio;

    c->set_nombre(_nombre);
    c->set_apellido(_apellido);
    c->cuenta_datos.set_anio(_anio);
    c->cuenta_datos.set_saldo(_saldo);
    c->cuenta_datos.set_estado(_estado= true);
    c->cuenta_datos.set_n_cliente(n_clientes);

    if (_anio < 2012 & _anio > 2005){
        c->set_tipo("oro");
        c->set_tarjeta(50000);
    }else if (_anio <= 2005){
        c->set_tipo("black");
        c->set_tarjeta(250000);
    } else {
        c->set_tipo("plata");
        c->set_tarjeta(0);
    }
}