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

void cuenta::crear_deposito(float monto_deposito, int N, int _dia, int _mes, int _anio) {

}

void cuenta::crear_extraccion(float monto_extraccion, int N, int _dia, int _mes, int _anio) {

}

