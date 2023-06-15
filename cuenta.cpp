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
int cuenta::cantT =0;
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
            t[cantT].set_cantidad(canti_extraccion);
            t[cantT].set_anio(anio);
            t[cantT].set_dia(dia);
            t[cantT].set_mes(mes);
            t[cantT].set_tipo('D');
            t[cantT].set_num_t(N);
            cantT++;
        } catch (const char *error) {
            cerr << error << endl;
        }
}
int cuenta::get_cant_transacciones() {
    return cant_transacciones;
}

void cuenta::crear_deposito(float canti_deposito,int dia,int mes,int anio,int N) {

    try {
        if (canti_deposito<=0){
            throw "Error: El monto debe ser mayor que 0";
        }
        saldo +=canti_deposito;
        //cout<<"Ingrese dia, mes y anio en la que se realizo el deposito"<<endl;
        //cin >> dia >> mes >> anio;
        cout<<"Se depositaron: $"<<canti_deposito<<" en la cuenta. Saldo actual: $"<<saldo<<endl;
        t[cantT].set_cantidad(canti_deposito);
        t[cantT].set_anio(anio);
        t[cantT].set_dia(dia);
        t[cantT].set_mes(mes);
        t[cantT].set_tipo('D');
        t[cantT].set_num_t(N);
        cantT++;

    }catch (const char* error) {
        cerr << error << endl;
    }
}

void cuenta::cambiar_estado() {
        estado = false;

}
void cuenta::aumentar_cantT()  {
    cantT++;
}
int cuenta::get_cantT(){
    return cantT;
}

/*
void cuenta::mostrar_transacciones_un_anio() {
    int _anio_;
    cout << "De que anio desea conocer las transacciones: " << endl;
    cin >> _anio_;
    for (int i = 0; i < cantT; ++i) {
        if (t[i].get_anio()==_anio_){
            for (int i = 0; i < cantT; ++i) {
                cout << t[i].get_num_t() << "  " << t[i].get_cantidad() << "  " << t[i].get_tipo() << "  " << t[i].get_dia() << "  " << t[i].get_mes() << "  " << t[i].get_anio() << endl;
            }
        }
    }
}*/