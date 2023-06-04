//
// Created by Luchi on 30/5/2023.
//
#include "clientes.h"
#include "cuenta.h"
#include <iostream>
using namespace std;

clientes::clientes(int _n_cliente, int _nombre, int _apellido, int _anio, bool _estado, string _tipo){
    cuenta_datos.set_n_cliente(_n_cliente);
    cuenta_datos.set_nombre(_nombre);
    cuenta_datos.set_apellido(_apellido);
    cuenta_datos.set_anio(_anio);
    cuenta_datos.set_estado(_estado);
    tipo = _tipo;
}
void clientes::set_tipo(string_tipo) {
    tipo = _tipo;
}
string clientes::get_tipo() {
    return tipo;
}

void clientes::start() {
    int opcion;
    while (1=1){
        cout << "SISTEMA DE GESTION" << endl << endl;
        cout << "1 - Dar de alta un cliente" << endl;
        cout << "2 - Dar de baja un cliente" << endl;
        cout << "3 - Generar un depósito" << endl;
        cout << "4 - Generar una extracción" << endl;
        cout << "5 - Consultar datos (Ingresando su numero de cliente)" << endl;
        cout << "6 - Consultar todos los cliente" << endl;
        cout << "7 - Consultar transacciones por cliente" << endl;
        cout << "8 - Generar informe de transacciones por periodo de 6 meses" << endl;
        cout << "9 - Generar informe de transacciones por año" << endl;
        cout << "10 - Generar informe total de transacciones" << endl;
        cout << "11 - Salir" << endl << endl << endl;
        cout << "Que desea hacer hoy? (Indique con el numero de cada opcion)" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                exit(EXIT_SUCCESS);
                break;
        }
    }
}