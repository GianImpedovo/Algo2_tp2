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

    // Constructor
    //PRE:
    //POS:
    Caracteristicas_edificio();

    //PRE:
    //POS:
    void cargar_edificios();

    //PRE:
    //POS:
    void agregar_edificio(Edificio * nuevo_edificio);

    //PRE:
    //POS:
    int obtener_cantidad_edificios();

    //PRE:
    //POS:
    Edificio * obtener_edificio(int posicion);

    //PRE:
    //POS:
    void listar_todos_edificios();

    bool existe_el_edificio(string nombre);

    // Destructor
    //PRE:
    //POS:
    ~Caracteristicas_edificio();


};





#endif // LISTA_EDIFICIO_H