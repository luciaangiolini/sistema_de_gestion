// Created by Laru on 4/6/2023.
//

#include "archivo.h"
#include "iostream"
#pragma once
using namespace std;
void archivo::create_fileT() {
    file_transacciones.open("transacciones.txt",ios::out);
    if (file_transacciones.is_open()){
        file_transacciones << "nro de cliente  //   " << "nro de transaaccion  //   "<<"cantidad  //   "<<
                           "tipo  //   "<<"dia  //   "<<"mes  //   "<<"anio  //   "<<endl;
    } else{
        cout<<"Error al crear el archivo"<<endl;
    }
}
void archivo::aniadir_transaccion(int n_cliente, int n_transaccion, int dia, int mes, int anio, float cantidad,char tipo) {
    file_transacciones << n_cliente<<"             //   " << n_transaccion<<"                   //   "<<cantidad<<"      //   "
                       <<tipo<<"     //   " << dia <<"   //   " << mes<<"    //   "  << anio<<"   //   " <<endl;
}
void archivo::create_fileC() {
    file_clientes.open("clientes.txt",ios::out);
    if (file_clientes.is_open()){
        file_clientes << "nro de cliente  //   " << "Nombre  //   "<<"Apellido  //   "<<
                           "tipo  //   "<<"anio  //   "<<"estado"<<endl;
    } else{
        cout<<"Error al crear el archivo"<<endl;
    }
}
void archivo::aniadir_cliente(int n_cliente, string nombre, string apellido, string tipo, string anio_incorporacion,
                              bool estado) {
    file_clientes <<  n_cliente<<"             //   " << nombre<<"               //   "<<apellido<<"      //   "
                  <<tipo<<"     //   " << anio_incorporacion <<"    //   " << estado <<endl;
}
void archivo::close_cli() {
    file_clientes.close();
}
void archivo::close_tran() {
    file_transacciones.close();
}