//
// Created by Luchi on 30/5/2023.
//
#include "clientes.h"

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

