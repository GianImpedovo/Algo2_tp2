#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "../edificio.h"
#include "../edificios/aserradero.h"
#include "../edificios/escuela.h"
#include "../edificios/fabrica.h"
#include "../edificios/mina.h"
#include "../edificios/obelisco.h"
#include "../edificios/planta_electrica.h"
#include "casillero.h"


class Casillero_construible : public Casillero {

private:
    Edificio * edificio_construido;

public:
    Casillero_construible(int fila, int columna);

    void agregar_edificio(string nombre, int piedra, int madera, int metal, int maximo);

    void agregar_material(string nombre, int cantidad);

    string obtener_nombre_edificio();

    string obtener_diminutivo_edificio();

    string obtener_diminutivo_material();

    void eliminar_edificio();

    void es_casillero_construible();

    void mostrar_casillero();

    string obtener_nombre();

    void mostrar_coordenadas_edificio(string nombre);

    bool existe_edificio();

    bool existe_material();

    ~Casillero_construible();

};


#endif