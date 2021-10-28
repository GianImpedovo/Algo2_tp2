#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include "caracteristicas_edificios.h"

using namespace std;

class Casillero
{
protected:
    int fila;
    int columna;
    string nombre;

public:
    Casillero(int fila, int columna , string nombre);

    Casillero();

    virtual void mostrar_casillero() = 0;

    string mostrar_nombre();

    int mostrar_fila();

    int mostrar_columna();


};


#endif // CASILLERO_H