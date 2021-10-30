#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>

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

    virtual void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo) = 0;

    virtual void mostrar_casillero() = 0;

    virtual string obtener_nombre() = 0;

    int mostrar_fila();

    int mostrar_columna();

    virtual void mostrar_coordenadas_edificio(string nombre) = 0;
    


};


#endif // CASILLERO_H