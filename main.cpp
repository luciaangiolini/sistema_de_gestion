#include <iostream>
#include "clientes.h"
#include "transaccion.h"
#include "cuenta.h"
#include "archivo.h"
#include "deposito.h"
#include "extracciones.h"
using namespace std;
void alta_cliente (clientes *c, int n_clientes, string _nombre, string _apellido, int _anio, float _saldo);
int main() {
    deposito d[6];
    extracciones e[6];
    archivo files;
    files.create_fileT();
    files.create_fileC();
    files.aniadir_transaccion(32,2,6,10,2019,3500,'E');
    int opcion;
    clientes c[6];
    bool alta= false;
    int N=1, N_clientes=1;
    while (1==1){
        cout << "SISTEMA DE GESTION" << endl << endl;
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
        switch (opcion) {
            case 1:{
                string _nombre, _apellido;
                string _tipo;
                int  _anio;
                float _saldo;
                bool estado= true;
                string estado2;

                cout << "Ingrese nombre, apellido, saldo y anio de incorporacion: " << endl;
                cin >> _nombre >> _apellido >> _saldo >> _anio;
                alta_cliente(&c[N_clientes-1], N_clientes, _nombre, _apellido, _anio, _saldo );
                c->cuenta_datos.set_estado(estado);
                    estado2 = "Activo";
                _tipo = c[N_clientes-1].get_tipo();
                files.open_cli();
                    files.aniadir_cliente(N_clientes, _nombre, _apellido, _tipo, _anio, estado2);
                    files.close_cli();
                    N_clientes++;

                alta=true;

                break;
            }
            case 2: {
                string nombre1, apellido1, tipo1, estado2;
                int n_cliente1, anio1;
                bool estado1;
                int num;
                if (alta){
                for (int i = 0; i < N_clientes-1; ++i) {
                    cout << i+1 << "  " <<c[i].get_nombre() << " " << c[i].get_apellido()<<endl;
                }
                cout << "Que cliente quiere dar de baja?" << endl;
                cin >>num;
                c[num-1].cuenta_datos.cambiar_estado();
                files.create_fileC();

                    cout << c[num-1].cuenta_datos.get_estado();
                    cout<< "hola"<<endl;
                for (int i = 0; i < N_clientes-1; ++i) {
                    nombre1 = c[i].get_nombre();
                    apellido1 = c[i].get_apellido();
                    tipo1 = c[i].get_tipo();
                    n_cliente1 = i + 1;
                    anio1 = c[i].cuenta_datos.get_anio();
                    if (c[i].cuenta_datos.get_estado()){
                        estado2 = "Activo";
                    }else{
                        estado2 = "Inactivo";
                    }
                    files.aniadir_cliente(n_cliente1, nombre1, apellido1, tipo1, anio1, estado2);
                }
                } else {
                    cout <<"Error. No tiene clientes cargados"<<endl;
                }
                break;
            }
            case 3:{
                int num;
                float monto_dep;
                int dia, mes, anio;
                for (int i = 0; i < N_clientes-1; ++i) {
                    cout << i+1 << "  " <<c[i].get_nombre() << " " << c[i].get_apellido()<<endl;
                }
                cout << "A que cliente desea generar un deposito?" << endl;
                cin >>num;
                cout << "Ingrese monto a depositar: " << endl;
                cin >> monto_dep;
                cout << "Ingrese dia, mes y anio: " << endl;
                cin >> dia >> mes >> anio;
                d[num-1].depositar(c[num-1].cuenta_datos, monto_dep, dia, mes, anio, N);
                files.aniadir_transaccion(num-1, N, dia, mes, anio, monto_dep, 'D');
                break;
            }
            case 4: {
                int num;
                float monto_ext;
                int dia, mes, anio;
                for (int i = 0; i < N_clientes-1; ++i) {
                    cout << i+1 << "  " <<c[i].get_nombre() << " " << c[i].get_apellido()<<endl;
                }
                cout << "A que cliente desea generar una extraccion?" << endl;
                cin >>num;
                cout << "Ingrese monto a extraer: " << endl;
                cin >> monto_ext;
                cout << "Ingrese dia, mes y anio: " << endl;
                cin >> dia >> mes >> anio;
                e[num-1].extraer(c[num-1].cuenta_datos, monto_ext, dia, mes, anio, N);
                files.aniadir_transaccion(num-1, N, dia, mes, anio, monto_ext, 'E');
                break;
            }
            case 5: {
                //Consultar datos por numero de cliente
                break;
            }
            case 6: {
                //Consultar datos de todos los clientes
                break;
            }
            case 7: {
                //Consultar transacciones por numero de clientes
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
                break;
            }
            case 11:
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
