//
// Created by Luchi on 30/5/2023.
//

#include "transaccion.h"

using namespace std;

transaccion::transaccion(int un_n_transaccion, int un_dia, int un_mes, int un_anio,float una_cantidad) {
    dia = un_dia;
    mes= un_mes;
    anio= un_anio;
    n_transaccion = un_n_transaccion;
}
void transaccion::set_num_t(int un_num) {
    n_transaccion=un_num;
}
void transaccion::set_anio(int _anio) {
    anio= _anio;
}
void transaccion::set_dia(int _dia) {
    dia= _dia;
}
void transaccion::set_mes(int _mes) {
    mes= _mes;
}
int transaccion::get_anio() {
    return anio;
}
int transaccion::get_num_t() {
    return n_transaccion;
}
int transaccion::get_dia() {
    return dia;
}
int transaccion::get_mes() {
    return mes;
}
float transaccion::get_cantidad() {
    return cantidad;
}
void transaccion::set_cantidad(float _cantidad){
    cantidad=_cantidad;
}
void transaccion::set_tipo(char _tipo) {
    tipo= _tipo;
}
char transaccion::get_tipo() {
    return tipo;
}