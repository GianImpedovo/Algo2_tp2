#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>

#include "casillero.h"
#include "caracteristicas_edificios.h"
#include "casillero_construible.h"
#include "casillero_transitable.h"
#include "casillero_inaccesible.h"

using namespace std;

const string ARCHIVO_MAPA = "mapa.txt";
const string ARCHIVO_UBICACIONES = "ubicaciones.txt";

class Mapa
{
private:
    int cantidad_filas;
    int cantidad_columnas;
    Casillero *** mapa;

public:
    Mapa();
    void generar_matriz();

    void buscar_coordenada(int fila, int columna);

    void procesar_archivo_ubicaciones(Caracteristicas_edificio  * lista_edificio);
    
    void mostrar_filas();
    
    void mostrar_columnas();
    
    void mostrar_mapa();
    
    ~Mapa();
};



#endif // MAPA_H