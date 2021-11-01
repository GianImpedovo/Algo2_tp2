#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H

#include "casillero.h"

class Casillero_inaccesible : public Casillero {


public:
    Casillero_inaccesible(int fila, int columna);

    void mostrar_casillero();

    void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo);

    string obtener_nombre_edificio();

    string obtener_diminutivo_edificio();

    void eliminar_edificio();

    string obtener_nombre();

    void mostrar_coordenadas_edificio(string nombre);

};


#endif