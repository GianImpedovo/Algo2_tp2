#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>

#include "casillero.h"
#include "casillero_construible.h"
#include "casillero_transitable.h"
#include "casillero_inaccesible.h"

using namespace std;

const string ARCHIVO_MAPA = "mapa.txt";

class Mapa
{
private:
    int cantidad_filas;
    int cantidad_columnas;
    Casillero *** mapa;

public:
    Mapa();
    ~Mapa();
    void buscar_coordenada(int fila, int columna);
    void generar_matriz();
    void mostrar_filas();
    void mostrar_columnas();
    void mostrar_mapa();
};



#endif // MAPA_H