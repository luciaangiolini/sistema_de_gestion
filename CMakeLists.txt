cmake_minimum_required(VERSION 3.24)
project(Sistema_de_Gestion)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sistema_de_Gestion main.cpp transaccion.h transaccion.cpp plata.h plata.cpp oro.h oro.cpp cuenta.h black.cpp clientes.h cuenta.cpp clientes.cpp extracciones.cpp extracciones.h deposito.cpp deposito.h archivo.h archivo.cpp)
