#ifndef PLANTA_ELECTRICA_H
#define PLANTA_ELECTRICA_H

#include "../edificio.h"

class Planta_electrica: public Edificio {

private:
    int brinda;

public:

    Planta_electrica(int piedra, int madera, int metal, int maximo);

    int obtener_material_brinda();

    void mostrar_mensaje();

};

#endif