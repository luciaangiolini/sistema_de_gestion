//
// Created by Laru on 3/6/2023.
//

#include "deposito.h"
void deposito::depositar(cuenta c, float canti_deposito,int dia,int mes,int anio,int N) {

    c.crear_deposito(canti_deposito,N,dia,mes,anio);
}
