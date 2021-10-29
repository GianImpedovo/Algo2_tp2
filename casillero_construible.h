#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "edificio.h"
#include "casillero.h"


class Casillero_construible : public Casillero {

private:
    Edificio * edificio_construido;

public:
    Casillero_construible(int fila, int columna);

    void agregar_edificio();

    void eliminar_edificio();

    void es_casillero_construible();

    void mostrar_casillero();

    string mostrar_nombre();

};


#endif