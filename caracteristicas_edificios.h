#ifndef LISTA_EDIFICIO_H
#define LISTA_EDIFICIO_H

#include "edificio.h"
#include "edificios/aserradero.h"
#include "edificios/escuela.h"
#include "edificios/fabrica.h"
#include "edificios/mina.h"
#include "edificios/obelisco.h"
#include "edificios/planta_electrica.h"
#include <fstream>

using namespace std;

const string ARCHIVO_EDIFICIO = "edificios.txt";

class Caracteristicas_edificio
{
protected:
    int cantidad_edificios;
    Edificio ** edificios_posibles;


public:
    Caracteristicas_edificio();

    int obtener_cantidad_edificios();

    Edificio * obtener_edificio(int posicion);

    void procesar_arhivo();

    void listar_todos_edificios();

    void guardar_datos();

    ~Caracteristicas_edificio();


};





#endif // LISTA_EDIFICIO_H