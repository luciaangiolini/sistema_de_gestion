// Created by Laru on 4/6/2023.
//

#include "archivo.h"
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
    ofstream file_transacciones("transacciones.txt", ios::app);

    if (file_transacciones.is_open()) {
        file_transacciones << n_cliente<<"             //   " << n_transaccion<<"                   //   "<<cantidad<<"      //   "
                           <<tipo<<"     //   " << dia <<"   //   " << mes<<"    //   "  << anio<<"   //   " <<endl;
        file_transacciones.close();  // Cerrar el archivo
    } else {
        cout << "Error al abrir el archivo." << std::endl;
    }

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
void archivo::aniadir_cliente(int n_cliente, const string nombre, string apellido, string tipo, int anio_incorporacion, string estado) {
    ofstream file_clientes("clientes.txt", ios::app);

    if (file_clientes.is_open()) {
        file_clientes <<  n_cliente<<"               //   " << nombre<<"         //   "<<apellido<<"      //   "
                      <<tipo<<"     //   " << anio_incorporacion <<"    //   " << estado <<endl;
        file_clientes.close();  // Cerrar el archivo
    } else {
        cout << "Error al abrir el archivo." << std::endl;
    }

}
void archivo::close_cli() {
    file_clientes.close();
}
void archivo::close_tran() {
    file_transacciones.close();
}
void archivo::open_cli() {
    ifstream file_clientes;
}
void archivo::open_tran() {
    ifstream file_transacciones;
}
void archivo::reescribir_cliente(int n_cliente, const string nombre, string apellido, string tipo,
                                 int anio_incorporacion, string estado) {
    ofstream file_clientes("clientes.txt", ios::out);

    if (file_clientes.is_open()) {
        file_clientes << "nro de cliente  //   " << "Nombre  //   "<<"Apellido  //   "<<
                      "tipo  //   "<<"anio  //   "<<"estado"<<endl;
        file_clientes <<  n_cliente<<"               //   " << nombre<<"         //   "<<apellido<<"      //   "
                      <<tipo<<"     //   " << anio_incorporacion <<"    //   " << estado <<endl;
        file_clientes.close();  // Cerrar el archivo
    } else {
        cout << "Error al abrir el archivo." << std::endl;
    }

}
void archivo::mostrar_transacciones() {
    ifstream file_transacciones ("transacciones.txt",ios::in);
    if(file_transacciones.is_open()){
        string linea;
        while (std::getline(file_transacciones, linea)) {
            cout << linea << std::endl;
        }
        file_transacciones.close();
    }
}