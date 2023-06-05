//
// Created by Luchi on 30/5/2023.
//

#ifndef SISTEMA_DE_GESTION_TRANSACCION_H
#define SISTEMA_DE_GESTION_TRANSACCION_H
#include "clientes.h"


class transaccion {
    int n_transaccion;
    int dia;
    int mes;
    int anio;
    float cantidad;
public:
    transaccion(int un_n_transaccion, int un_dia, int un_mes,int un_anio, float una_cantidad);
    void set_num_t(int un_num);
    int get_num_t();
    void set_dia(int _dia);
    int get_dia();
    void set_mes(int _mes);
    int get_mes();
    void set_anio(int _anio);
    int get_anio();
    void set_cantidad(float _cantidad);
    float get_cantidad();
};


#endif //SISTEMA_DE_GESTION_TRANSACCION_H
