#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "edificio.h"
#include "caracteristicas_edificios.h"
#include "casillero.h"


class Casillero_construible : public Casillero {
private:
    Edificio * edificio_construido;
public:
    Casillero_construible(int fila, int columna);

    void mostrar_casillero();

    string mostrar_nombre();

};


#endif