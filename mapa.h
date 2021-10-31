#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>

#include "inventario.h"
#include "caracteristicas_edificios.h"
#include "casilleros/casillero.h"
#include "casilleros/casillero_construible.h"
#include "casilleros/casillero_transitable.h"
#include "casilleros/casillero_inaccesible.h"

using namespace std;

const string ARCHIVO_MAPA = "mapa.txt";
const string ARCHIVO_UBICACIONES = "ubicaciones.txt";

class Mapa
{
private:
    int cantidad_filas;
    int cantidad_columnas;
    Casillero *** mapa;

    Inventario * usuario_inventario;
    Caracteristicas_edificio * lista_edificios;

public:
    Mapa();

    void mostrar_inv();

    void generar_matriz();

    void listar_edificios_construidos();

    void mostrar_coordenadas(string nombre);

    void mostrar_todos_edificios();

    void demoler_edificio();

    void buscar_coordenada();

    void procesar_archivo_ubicaciones();
    
    void mostrar_filas();
    
    void mostrar_columnas();

    void mostrar_mapa();
    
    ~Mapa();
};



#endif // MAPA_H