//
// Created by Laru on 3/6/2023.
//

#include "extracciones.h"

void extracciones::extraer(cuenta c,float cant_extraccion, int dia,int mes,int anio,int N) {
    c.crear_extraccion(cant_extraccion, N, dia, mes, anio);
}
