#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "casillero.h"


class Casillero_transitable : public Casillero {
private:
    // PUNTERO A MATERIAL;
public:
    Casillero_transitable(int fila, int columna);

    void mostrar_casillero();
    string mostrar_nombre();

};


#endif