#ifndef EDIFICIOS_CONSTRUIDOS_H
#define EDIFICIOS_CONSTRUIDOS_H

#include "edificio.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

const string ARCHIVO_UBICACION = "ubicaciones.txt";

class Edificios_construidos{
private:
    int cantidad_edificios_construidos;
    Edificio ** edificios_construidos;

public:
    Edificios_construidos();

    void procesar_archivo();

    ~Edificios_construidos();

};



#endif