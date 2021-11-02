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
    void construir_edificio_nombre();

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

    //PRE:
    //POS:
    void recolectar_recursos_producidos();

    //PRE: Recibe los eneteros "max_fila" y  "max_col" con los vaores de las maxima columna y la maxima fila que
    //hay en el mapa
    //POST: Coloca en el mapa 1 unidad de cada material generado. Si la posicion random en la que se lo colocaria
    //resulta estar ocupada, no se coloca dicho material.
    void lluvia_recursos();

    //Consultar material a colocar
    //PRE: Recibe los enteros "cant_gen_piedras", "cant_gen_maderas" y "cant_gen_metales" y el string
    //material_a_colocar
    //POST: Modifica por parametro "material_a_colocar" y las cantidades de piedra y madera restantes
    //void Mapa ::
    void consultar_material_a_colocar(int &cant_gen_piedras, int &cant_gen_maderas, int &cant_gen_metales, string &material_a_colocar);

    //Generar numero random
    //PRE: Recibe los enteros "min" y "max" con los valores limites (inclusives) entre los cuales se desea generar
    //el numero random 
    //POST: Devuelve un valor random entre "min" y "max"
    int generar_numero_random(int min, int max);

    // Detructor
    //PRE:
    //POS:
    ~Mapa();
};



#endif // MAPA_H