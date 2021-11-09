#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H

#include "casillero.h"

class Casillero_inaccesible : public Casillero {


public:

    Casillero_inaccesible(int fila, int columna);


    void mostrar_casillero();

    void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo);

    void agregar_material(string nombre, int cantidad);

    string obtener_nombre_edificio();

    string obtener_nombre_material();

    string obtener_diminutivo_edificio();

    string obtener_diminutivo_material();

    void eliminar_edificio();

    string obtener_nombre();

    void mostrar_coordenadas_edificio(string nombre);

    bool existe_edificio();

    bool existe_material();

    //Obtener fila
    //PRE:-
    //POST: Devuelve un entero con la fila del casillero
    int obtener_fila();

    //Obtener columna
    //PRE:-
    //POST: Devuelve un entero con la columna del casillero
    int obtener_columna();

};


#endif