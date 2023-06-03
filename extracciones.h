//
// Created by Laru on 3/6/2023.
//

#ifndef SISTEMA_DE_GESTION_EXTRACCIONES_H
#define SISTEMA_DE_GESTION_EXTRACCIONES_H
#include "transaccion.h"
#include "transaccion.cpp"
#include "clientes.h"


class extracciones: public transaccion{
public:
    void extraer(float cant_extraccion);
};


#endif //SISTEMA_DE_GESTION_EXTRACCIONES_H
