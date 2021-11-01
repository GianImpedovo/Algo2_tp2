#ifndef OBELISCO_H
#define OBELISCO_H

#include "../edificio.h"

class Obelisco: public Edificio {

private:
    int brinda;

public:

    Obelisco(int piedra, int madera, int metal, int maximo);

    int obtener_material_brinda();

    void mostrar_mensaje();

};

#endif