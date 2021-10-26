#ifndef LISTA_EDIFICIO_H
#define LISTA_EDIFICIO_H

#include "edificio.h"
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
    
    void mostrar_cantidad_edificios();
    
    void procesar_arhivo();

    Edificio encontrar_edificio();

    void listar_todos_edificios();

    void guardar_datos();
    ~Caracteristicas_edificio();


};





#endif // LISTA_EDIFICIO_H