#ifndef ESCUELA_H
#define ESCUELA_H

#include "../edificio.h"

class Escuela: public Edificio {

private:
    int brinda;

public:

    Escuela(int piedra, int madera, int metal, int maximo);

    int obtener_material_brinda();

    void mostrar_mensaje();

};


#endif 