#include <iostream>
#include "clientes.h"
#include "transaccion.h"
#include "cuenta.h"
#include "archivo.h"
#include "black.h"
#include "deposito.h"
#include "extracciones.h"
#include "oro.h"
#include "plata.h"
using namespace std;

void alta_cliente (clientes *c,int n_clientes);
int main() {
    clientes c[6];
    bool alta= false;
    int N=1, N_clientes=1;
    return 0;
}
void alta_cliente (clientes *c, int n_clientes){
    string _nombre, _apellido;
    int _n_cliente, _anio;
    float _saldo;
    bool _estado;

    cout << "ingrese nombre, apellido, saldo y año de incorporacion"<<endl;
    cin >> _nombre>>_apellido>> _saldo>> _anio;

    c->set_nombre(_nombre);
    c->set_apellido(_apellido);
    c->cuenta_datos.set_anio(_anio);
    c->cuenta_datos.set_saldo(_saldo);
    c->cuenta_datos.set_estado(_estado= true);
    c->cuenta_datos.set_n_cliente(n_clientes);

    if (_anio < 2012 & _anio > 2005){
        c->set_tipo("oro");
        c->set_tarjeta(50000);
    }else if (_anio <= 2005){
        c->set_tipo("black");
        c->set_tarjeta(250000);
    } else {
        c->set_tipo("plata");
        c->set_tarjeta(0);
    }
}
