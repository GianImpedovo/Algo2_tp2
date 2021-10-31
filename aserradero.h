#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "edificio.h"

class Aserradero: public Edificio {

private:
    int brinda;

public:

    Aserradero(int piedra, int madera, int metal, int maximo);

    int obtener_material_brinda();

    void mostrar_mensaje();

};


#endif 