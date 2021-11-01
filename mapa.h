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

    // Constructor
    //PRE:
    //POS:
    Mapa();

    //PRE:
    //POS:
    void ingreso_datos_mapa();

    //PRE:
    //POS:
    void procesar_archivo_mapa();

    //PRE:
    //POS:
    void procesar_archivo_ubicaciones();

    //PRE:
    //POS:
    void generar_matriz();

    //PRE:
    //POS:
    void listar_edificios_construidos();

    //PRE:
    //POS:
    void mostrar_coordenadas(string nombre);

    //PRE:
    //POS:
    void mostrar_todos_edificios();

    //PRE:
    //POS:
    void demoler_edificio();

    //PRE:
    //POS:
    void obtengo_materiales_elimino_edificio(string nombre_edificio, int fila, int columna);

    //PRE:
    //POS:
    void devolver_materiales(int piedra, int madera, int metal);

    //PRE:
    //POS:
    void mostrar_mapa();

    //PRE:
    //POS:
    void consultar_coordenada();

    //PRE:
    //POS:
    void mostrar_inv();

    // Detructor
    //PRE:
    //POS:
    ~Mapa();
};



#endif // MAPA_H