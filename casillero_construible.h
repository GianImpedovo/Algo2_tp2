#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "edificio.h"
#include "casillero.h"


class Casillero_construible : public Casillero {

public:
    Casillero_construible(int fila, int columna);

    void mostrar_casillero();

    string mostrar_nombre();

};


#endif