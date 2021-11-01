#ifndef MINA_H
#define MINA_H

#include "../edificio.h"

class Mina: public Edificio {

private:
    int brinda;

public:

    Mina(int piedra, int madera, int metal, int maximo);

    int obtener_cantidad_brindada();

    void mostrar_mensaje();

};

#endif