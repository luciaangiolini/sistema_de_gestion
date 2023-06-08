//
// Created by Laru on 4/6/2023.
//

#ifndef SISTEMA_DE_GESTION_ARCHIVO_H
#define SISTEMA_DE_GESTION_ARCHIVO_H
#include "fstream"
#include "iostream"
#pragma once
using namespace std;

class archivo {
    ofstream file_transacciones;
    ofstream file_clientes;

public:
    void create_fileT();
    void create_fileC();
    void aniadir_transaccion(int n_cliente, int n_transaccion, int dia,int mes, int anio,float cantidad,char tipo);
    void aniadir_cliente(int n_cliente, string nombre, string apellido, string tipo,int anio_incorporacion,string estado);
    void close_tran();
    void close_cli();

};

#endif //SISTEMA_DE_GESTION_ARCHIVO_H