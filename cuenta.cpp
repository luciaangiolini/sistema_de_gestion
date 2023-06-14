//
// Created by Luchi on 30/5/2023.
//
#include <iostream>
#include "cuenta.h"
using namespace std;
cuenta::cuenta(int _n_cliente, string _nombre, string _apellido, int _anio, bool _estado, float _saldo) {
    n_cliente = _n_cliente;
    nombre = _nombre;
    apellido = _apellido;
    anio = _anio;
    estado = _estado;
    saldo = _saldo;
}
void cuenta::set_n_cliente( int _n_cliente) {
    n_cliente = _n_cliente;
}
int cuenta::get_n_cliente() {
    return n_cliente;
}

void cuenta::set_nombre(string _nombre) {
    nombre = _nombre;
}
string cuenta::get_nombre() {
    return nombre;
}
void cuenta::set_apellido(string _apellido) {
    apellido = _apellido;
}
string cuenta::get_apellido() {
    return apellido;
}
void cuenta::set_anio( int _anio) {
    anio = _anio;
}
int cuenta::get_anio() {
    return anio;
}
void cuenta::set_estado(bool _estado) {
    estado = _estado;
}
bool cuenta::get_estado() {
    return estado;
}
void cuenta::set_saldo(float _saldo) {
    saldo = _saldo;
}
float cuenta::get_saldo() {
    return saldo;
}

void cuenta::crear_extraccion(float canti_extraccion,int dia,int mes,int anio, int N) {
        try {
            if (canti_extraccion <= 0) {
                throw "Error: El monto debe ser mayor que 0";
            }
            if (canti_extraccion > saldo) {
                throw "Error: fondos insuficientes";
            }
            saldo -= canti_extraccion;
            cout << "Se extrajo: $" << canti_extraccion << " de la cuenta. Saldo actual: $" << saldo << endl;
            t[cant_transacciones].set_cantidad(canti_extraccion);
            t[cant_transacciones].set_anio(anio);
            t[cant_transacciones].set_dia(dia);
            t[cant_transacciones].set_mes(mes);
            t[cant_transacciones].set_tipo('D');
            t[cant_transacciones].set_num_t(N);
            cant_transacciones++;

        } catch (const char *error) {
            cerr << error << endl;
        }
}

void cuenta::crear_deposito(float canti_deposito,int dia,int mes,int anio,int N) {

    try {
        if (canti_deposito<=0){
            throw "Error: El monto debe ser mayor que 0";
        }
        saldo +=canti_deposito;
        //cout<<"Ingrese dia, mes y anio en la que se realizo el deposito"<<endl;
        //cin >> dia >> mes >> anio;
        cout<<"Se depositaron: "<<canti_deposito<<"$ en la cuenta. Saldo actual: "<<saldo<<"$"<<endl;
        t [cant_transacciones].set_cantidad(canti_deposito);
        t[cant_transacciones].set_anio(anio);
        t[cant_transacciones].set_dia(dia);
        t[cant_transacciones].set_mes(mes);
        t[cant_transacciones].set_tipo('D');
        t[cant_transacciones].set_num_t(N);
        cant_transacciones++;

    }catch (const char* error) {
        cerr << error << endl;
    }
}

void cuenta::cambiar_estado() {
        estado = false;

}


