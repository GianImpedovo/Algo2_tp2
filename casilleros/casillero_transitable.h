#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "casillero.h"


class Casillero_transitable : public Casillero {
private:
    //Material * material;
public:
    Casillero_transitable(int fila, int columna);

    void mostrar_casillero();

    void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo);

    string obtener_nombre_edificio();

    string obtener_diminutivo_edificio();

    void eliminar_edificio();

    string obtener_nombre();

    void mostrar_coordenadas_edificio(string nombre);

};


#endif