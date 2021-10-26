#ifndef LISTA_EDIFICIO_H
#define LISTA_EDIFICIO_H

#include "edificio.h"
#include <fstream>

using namespace std;

const string ARCHIVO_EDIFICIO = "edificios.txt";

class Lista_edificio
{
private:
    int cantidad_edificios;
    Edificio ** edificios_posibles;


public:
    Lista_edificio();
    void mostrar_cantidad_edificios();
    void procesar_arhivo();
    void listar_todos_edificios();
    void guardar_datos();
    ~Lista_edificio();


};





#endif // LISTA_EDIFICIO_H