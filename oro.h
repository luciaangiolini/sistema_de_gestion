//
// Created by Luchi on 30/5/2023.
//

#ifndef SISTEMA_DE_GESTION_ORO_H
#define SISTEMA_DE_GESTION_ORO_H
#include <iostream>
#include "clientes.h"
using namespace std;

class oro: public clientes{
    float limit_tarjeta;
public:
    oro();
};


#endif //SISTEMA_DE_GESTION_ORO_H
