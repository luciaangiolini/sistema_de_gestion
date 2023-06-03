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
public:
    transaccion(int n_transaccion, int dia, int mes,int anio);
    void set_num_t(int un_num);
    int get_num_t();
    void set_dia(int _dia);
    int get_dia();
    void set_mes(int _mes);
    int get_mes();
    void set_anio(int _anio);
    int get_anio();
};


#endif //SISTEMA_DE_GESTION_TRANSACCION_H
