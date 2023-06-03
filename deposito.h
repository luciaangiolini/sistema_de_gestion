//
// Created by Laru on 3/6/2023.
//

#ifndef SISTEMA_DE_GESTION_DEPOSITO_H
#define SISTEMA_DE_GESTION_DEPOSITO_H
#include "transaccion.h"
#include "clientes.h"


class deposito: public transaccion{
public:
    void depositar(float cant_deposito);
};


#endif //SISTEMA_DE_GESTION_DEPOSITO_H
