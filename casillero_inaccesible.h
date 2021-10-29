#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H

#include "casillero.h"

class Casillero_inaccesible : public Casillero {


public:
    Casillero_inaccesible(int fila, int columna);

    void mostrar_casillero();

    void agregar_edificio();
    string mostrar_nombre();

};


#endif