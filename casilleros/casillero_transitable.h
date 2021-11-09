#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "casillero.h"
#include "../material.h"


class Casillero_transitable : public Casillero {
private:
    Material * material;
public:

    //Constructor de casillero transitable
    //PRE: Recibe un entero con la fila y otro con la columna
    //POST: Construye un casillero transitable con nombre = "c" e inicializa el puntero material en null.
    Casillero_transitable(int fila, int columna);

    void mostrar_casillero();

    void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo);

    void agregar_material(string nombre, int cantidad);

    string obtener_nombre_edificio();

    string obtener_nombre_material();

    string obtener_diminutivo_edificio();

    string obtener_diminutivo_material();

    void eliminar_edificio();

    bool existe_edificio();

    bool existe_material();

    string obtener_nombre();

    void mostrar_coordenadas_edificio(string nombre);

    ~Casillero_transitable();

    int obtener_fila();

    int obtener_columna();
};


#endif