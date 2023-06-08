//
// Created by Laru on 3/6/2023.
//

#ifndef SISTEMA_DE_GESTION_EXTRACCIONES_H
#define SISTEMA_DE_GESTION_EXTRACCIONES_H
#include "transaccion.h"
#include "cuenta.h"
#pragma once

class extracciones: public transaccion{
public:
    void extraer(cuenta c,float cant_extraccion, int dia,int mes,int anio,int N);
};


#endif //SISTEMA_DE_GESTION_EXTRACCIONES_H
