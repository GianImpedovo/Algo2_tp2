#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "casillero.h"


class Casillero_transitable : public Casillero {
private:
    //Material * material;
public:
    Casillero_transitable(int fila, int columna);

    void mostrar_casillero();

    void agregar_edificio();

    string mostrar_nombre();

};


#endif