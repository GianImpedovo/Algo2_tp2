#ifndef LISTA_EDIFICIO_H
#define LISTA_EDIFICIO_H

#include "edificio.h"
#include <fstream>

using namespace std;


class Lista_edificio
{
private:
    int cantidad_edificios;
    Edificio ** edificios_posibles;


public:
    Lista_edificio(std::string archivo);
    void mostrar_edificios();

};





#endif // LISTA_EDIFICIO_H