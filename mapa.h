#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>
#include "casillero.h"

using namespace std;

const string ARCHIVO_MAPA = "mapa.txt";

class Mapa
{
private:
    int cantidad_filas;
    int cantidad_columnas;
    Casillero ** mapa;

public:
    Mapa();
    ~Mapa();
    void generar_matriz();
    void mostrar_filas();
    void mostrar_columnas();
    void mostrar_mapa();
};



#endif // MAPA_H