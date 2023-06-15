#include <iostream>
#include <stdexcept>
#include <limits>
#include "clientes.h"
#include "transaccion.h"
#include "cuenta.h"
#include "archivo.h"
#include "deposito.h"
#include "extracciones.h"
using namespace std;
void alta_cliente (clientes *c, int n_clientes, string _nombre, string _apellido, int _anio, float _saldo);
/*
template<typename T>
T getInputInRange(const T& input, const T& minVal, const T& maxVal) {
    if (input >= minVal && input <= maxVal) {
        return input;
    } else {
        cout << "Valor invalido. Fuera del rango. Por favor, ingrese nuevamente: " << endl;
        T newInput;
        cin >> newInput;
        return getInputInRange<T>(newInput, minVal, maxVal);
    }
}*/
int main() {
    deposito d[6];
    extracciones e[6];
    archivo files;
    files.create_fileT();
    files.create_fileC();
    //files.aniadir_transaccion(32, 2, 6, 10, 2019, 3500, 'E');
    int opcion;
    clientes c[6];
    bool alta = false;
    int N = 1, N_clientes = 1;
    bool es_valido = false;
    while (1 == 1) {
        do {
            try {
                cout << endl << endl << "---------SISTEMA DE GESTION---------" << endl << endl;
                cout << "1 - Dar de alta un cliente" << endl;
                cout << "2 - Dar de baja un cliente" << endl;
                cout << "3 - Generar un deposito" << endl;
                cout << "4 - Generar una extraccion" << endl;
                cout << "5 - Consultar datos (Ingresando su numero de cliente)" << endl;
                cout << "6 - Consultar todos los clientes" << endl;
                cout << "7 - Consultar transacciones por cliente" << endl;
                cout << "8 - Generar informe de transacciones por periodo de 6 meses" << endl;
                cout << "9 - Generar informe de transacciones por anio" << endl;
                cout << "10 - Generar informe total de transacciones" << endl;
                cout << "11 - Salir" << endl << endl << endl;
                cout << "Que desea hacer hoy? (Indique con el numero de cada opcion)" << endl;
                cin >> opcion;
                //getInputInRange(opcion, 1, 11);
                if (cin.fail()) {
                    throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero.");
                }
                es_valido = true;
            }
            catch (const exception &e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!es_valido);
        switch (opcion) {
            case 1: {
                string _nombre, _apellido;
                string _tipo;
                int _anio;
                float _saldo;
                bool estado = true;
                string estado2;
                bool is_valid_1=false;
                bool is_valid_2=false;
                bool is_valid_3=false;
                bool is_valid_4=false;

                do {
                    cout << "Ingrese nombre: " << endl;
                    try {
                        cin >> _nombre;
                        for (char c : _nombre) {
                            if (!isalpha(c)) {
                                throw runtime_error("Error. Ingrese el nombre con letras :)");
                            }
                        }
                        is_valid_1=true;
                    }
                    catch (const exception& e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_1);
                do {
                    cout << "Ingrese apellido: " << endl;
                    try {
                        cin >> _apellido;
                        for (char c : _apellido) {
                            if (!isalpha(c)) {
                                throw runtime_error("Error. Ingrese el apellido con letras :)");
                            }
                        }
                        is_valid_2=true;
                    }
                    catch (const exception& e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_2);
                do {
                    cout << "Ingrese el saldo: " << endl;

                    try {
                        cin >> _saldo;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero :)");
                        }
                        is_valid_3=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_3);

                do {
                    cout << "Ingrese el anio de incorporacion: " << endl;
                    try {
                        cin >> _anio;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero.");
                        }
                        is_valid_4=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_4);

                alta_cliente(&c[N_clientes - 1], N_clientes, _nombre, _apellido, _anio, _saldo);
                c[N_clientes - 1].cuenta_datos.set_estado(estado);
                estado2 = "Activo";
                _tipo = c[N_clientes - 1].get_tipo();
                files.open_cli();
                files.aniadir_cliente(N_clientes, _nombre, _apellido, _tipo, _anio, estado2);
                files.close_cli();
                N_clientes++;
                alta = true;
                break;
            }
            case 2: {
                string nombre1, apellido1, tipo1, estado2;
                int n_cliente1, anio1;
                bool estado1;
                int num;
                bool is_valid=false;
                if (alta) {
                    for (int i = 0; i < N_clientes - 1; ++i) {
                        cout << i + 1 << "  " << c[i].get_nombre() << " " << c[i].get_apellido() << endl;
                    }
                    do {
                        cout << "Que cliente quiere dar de baja?" << endl;
                        try {
                            cin >> num;
                            if (cin.fail()) {
                                throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero.");
                            }
                            is_valid=true;
                        }
                        catch (const exception &e) {
                            cerr << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (!is_valid);
                    c[num - 1].cuenta_datos.cambiar_estado();
                    files.create_fileC();

                    nombre1 = c[0].get_nombre();
                    apellido1 = c[0].get_apellido();
                    tipo1 = c[0].get_tipo();
                    n_cliente1 = 1;
                    anio1 = c[0].cuenta_datos.get_anio();
                    if (c[0].cuenta_datos.get_estado()) {
                        estado2 = "Activo";
                    } else {
                        estado2 = "Inactivo";
                    }
                    files.reescribir_cliente(n_cliente1, nombre1, apellido1, tipo1, anio1, estado2);


                    for (int i = 1; i < N_clientes - 1; ++i) {
                        nombre1 = c[i].get_nombre();
                        apellido1 = c[i].get_apellido();
                        tipo1 = c[i].get_tipo();
                        n_cliente1 = i + 1;
                        anio1 = c[i].cuenta_datos.get_anio();
                        if (c[i].cuenta_datos.get_estado()) {
                            estado2 = "Activo";
                        } else {
                            estado2 = "Inactivo";
                        }
                        files.aniadir_cliente(n_cliente1, nombre1, apellido1, tipo1, anio1, estado2);
                    }
                    cout << "El cliente " << c[num - 1].get_nombre() << " " << c[num - 1].get_apellido()
                         << " ha sido dado de baja." << endl << endl;

                } else {
                    cout << "Error. No tiene clientes cargados" << endl;
                }
                break;
            }
            case 3: {
                int num;
                float monto_dep;
                int dia, mes, anio;
                bool is_valid_1= false;
                bool is_valid_2=false;
                bool is_valid_3=false;
                bool is_valid_4=false;
                bool is_valid_5=false;

                for (int i = 0; i < N_clientes - 1; ++i) {
                    cout << i + 1 << "  " << c[i].get_nombre() << " " << c[i].get_apellido() << endl;
                }
                do {
                    cout << "A que cliente desea generar un deposito?" << endl;
                    try {
                        cin >> num;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid_1=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_1);
                do {
                    cout << "Ingrese monto a depositar: " << endl;
                    try {
                        cin >> monto_dep;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid_2=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_2);
                do {
                    cout << "Ingrese dia: " << endl;
                    try {
                        cin >> dia;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid_3=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_3);
                do {
                    cout << "Ingrese mes: " << endl;
                    try {
                        cin >> mes ;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid_4=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_4);
                do {
                    cout << "Ingrese anio: " << endl;
                    try {
                        cin >> anio;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid_5=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_5);

                d[num - 1].depositar(c[num - 1].cuenta_datos, monto_dep, dia, mes, anio, N);
                files.aniadir_transaccion(num , N, dia, mes, anio, monto_dep, 'D');
                N++;
                break;
            }
            case 4: {
                int num;
                float monto_ext;
                int dia, mes, anio;
                bool is_valid_1=false;
                bool is_valid_2=false;
                bool is_valid_3=false;
                bool is_valid_4=false;
                bool is_valid_5=false;
                for (int i = 0; i < N_clientes - 1; ++i) {
                    cout << i + 1 << "  " << c[i].get_nombre() << " " << c[i].get_apellido() << endl;
                }
                do {
                    cout << "A que cliente desea generar una extraccion?" << endl;
                    try {
                        cin >> num;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid_1=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_1);
                do {
                    cout << "Ingrese monto a extraer: " << endl;
                    try {
                        cin >> monto_ext;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero :)");
                        }
                        is_valid_2=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_2);
                do {
                    cout << "Ingrese dia: " << endl;
                    try {
                        cin >> dia;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid_3=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_3);
                do {
                    cout << "Ingrese mes: " << endl;
                    try {
                        cin >> mes ;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid_4=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_4);
                do {
                    cout << "Ingrese anio: " << endl;
                    try {
                        cin >> anio;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid_5=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid_5);

                e[num - 1].extraer(c[num - 1].cuenta_datos, monto_ext, dia, mes, anio, N);
                files.aniadir_transaccion(num , N, dia, mes, anio, monto_ext, 'E');
                N++;
                break;
            }
            case 5: {
                int num;
                bool is_valid=false;
                for (int i = 0; i < N_clientes - 1; ++i) {
                    cout << "Cliente N " << c[i].cuenta_datos.get_n_cliente() << " --> " << c[i].get_nombre()
                         << " "
                         << c[i].get_apellido() << endl;
                }
                do {
                    cout << "Indique con el numero del cliente para consultar sus respectivos datos: " << endl;
                    try {
                        cin >> num;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid);
                cout << "Datos: " << endl;
                cout << "Cliente N --> " << c[num - 1].cuenta_datos.get_n_cliente() << endl;
                cout << "Nombre --> " << c[num - 1].get_nombre() << " " << c[num - 1].get_apellido() << endl;
                cout << "Categoria --> " << c[num - 1].get_tipo() << endl;
                cout << "Anio de incorporacion --> " << c[num - 1].cuenta_datos.get_anio() << endl;
                if (c[num - 1].cuenta_datos.get_estado()) {
                    cout << "Estado -->  Activo" << endl;
                } else {
                    cout << "Estado -->  Inactivo" << endl;
                }
                break;
            }
            case 6: {
                //Consultar datos de todos los clientes
                for (int i = 0; i < N_clientes - 1; ++i) {
                    cout << "Cliente N --> " << c[i].cuenta_datos.get_n_cliente() << endl;
                    cout << " - Nombre --> " << c[i].get_nombre() << endl;
                    cout << " - Apellido --> " << c[i].get_apellido() << endl;
                    cout << " - Categoria --> " << c[i].get_tipo();
                    if (c[i].get_tipo() == "plata") {
                        cout << " - Tarjeta de credito --> NO" << endl;
                    } else {
                        cout << " - Tarjeta de credito --> SI" << endl;
                        cout << " - Limite tarjeta de credito --> $" << c[i].get_tarjeta() << endl;
                    }
                    cout << " - Anio de incorporacion --> " << c[i].cuenta_datos.get_anio() << endl;
                    if (c[i].cuenta_datos.get_estado()) {
                        cout << " - Estado -->  Activo" << endl;
                    } else {
                        cout << " - Estado -->  Inactivo" << endl;
                    }
                }
                break;
            }
            case 7: {
                //Consultar transacciones por numero de clientes

                int num;
                bool is_valid=false;
                for (int i = 0; i < N_clientes - 1; ++i) {
                    cout << "Cliente N " << c[i].cuenta_datos.get_n_cliente() << " --> " << c[i].get_nombre()
                         << " "
                         << c[i].get_apellido() << endl;
                }
                do {
                    cout << "Indique con el numero del cliente para ver sus transferencias: " << endl;
                    try {
                        cin >> num;
                        if (cin.fail()) {
                            throw runtime_error("Error: Entrada invalida. Debe ingresar un numero entero:)");
                        }
                        is_valid=true;
                    }
                    catch (const exception &e) {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!is_valid);
                /*
                cout << "Datos: " << endl;
                cout << "Transacciones correspondientes al cliente N --> " << c[num - 1].cuenta_datos.get_n_cliente() <<": "<< c[num - 1].get_nombre()<<c[num - 1].get_apellido()<< endl;

                int fin;
                fin = c[num-1].cuenta_datos.get_cant_transacciones();
                cout << c [num-1].cuenta_datos.get_cant_transacciones() << endl;

                int fin;
                fin= c[num-1].cuenta_datos.get_cantT();
                cout<<c[num-1].cuenta_datos.get_cantT();
                    if (fin != 0) {
                    for (int i = 0; i < fin; ++i) {
                        cout << "N de transaccion: --> " << c[num - 1].cuenta_datos.t[i].get_num_t();
                        cout << "Tipo de transaccion --> " << c[num - 1].cuenta_datos.t[i].get_tipo() << endl;
                        cout << "Monto de la transaccion -->" << c[num-1].cuenta_datos.t[i].get_cantidad()<<"$"<<endl;
                        cout << "Fecha de transaccion --> " << c[num - 1].cuenta_datos.t[i].get_dia() << "/"
                             << c[num - 1].cuenta_datos.t[i].get_mes() << "/" << c[num - 1].cuenta_datos.t[i].get_anio()
                             << endl;
                    }
                } else{
                    cout << "El cliente N --> " << c[num - 1].cuenta_datos.get_n_cliente() <<": "<<
                         c[num - 1].cuenta_datos.get_nombre()<<c[num - 1].cuenta_datos.get_apellido()<<
                         "No tiene registrada ninguna transacción " <<endl;
                }*/
                break;

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
                files.mostrar_transacciones();
                break;
            }
            case 11:
                cout << "Gracias por elegirnos! Volve pronto, siempre para vos" << endl;
                exit(EXIT_SUCCESS);
                break;
        }
    }
    return 0;
}


void alta_cliente(clientes *c, int n_clientes, string _nombre, string _apellido, int _anio, float _saldo) {

    c->set_nombre(_nombre);
    c->set_apellido(_apellido);
    c->cuenta_datos.set_anio(_anio);
    c->cuenta_datos.set_saldo(_saldo);
    c->cuenta_datos.set_n_cliente(n_clientes);

    if (_anio < 2012 & _anio > 2005) {
        c->set_tipo("oro");
        c->set_tarjeta(50000);
    } else if (_anio <= 2005) {
        c->set_tipo("black");
        c->set_tarjeta(250000);
    } else {
        c->set_tipo("plata");
        c->set_tarjeta(0);
    }
}

