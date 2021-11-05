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
    //PRE: - 
    //POS: Inicializa el mapa con todos sus valores y punteros en 0.
    Mapa();

    //PRE: Utilizando los arhivos requeridos.
    //POS: Setea el mapa con sus valores ingresando cada uno de sus casilleros correspondientes y 
    //     en caso de existir ubicaciones de edificios o materiales.
    //     Ingresa los valores a los punteros usuarios_inventario y lista_edificio 
    //     haciendo lectura correspondiente de los arhivos
    void ingreso_datos_mapa();

    //PRE: Utilizando el archivo ubicaciones.txt.
    //POS: Agrega Edificios/Materiales en sus ubicaciones.
    void procesar_archivo_ubicaciones();

    //PRE: Utilizando el archivo mapa.txt.
    //POS: Obtiene la cantidad de filas y columnas. Ingresa los valores de los casilleros.
    void procesar_archivo_mapa();

    //PRE: -
    //POS: Inicializa la matriz del mapa con valor 0.
    void generar_matriz();

    //PRE:
    //POS:
    void validar_coordenada(int &fila, int &columna);

    // -------------- DIVISION PUNTO POR PUNTO : MENU -------------------------------

    //PRE: Debe crearse un edificio con el nombre de algun edificio que exista ( se encuentre en caracteristicas_edificios)
    //     solicitando las coordenadas , se chequea si se poseen los materiales necesarios, si no supero el maximo de edificios y si se puede
    //     construir en tales coordenadas, debe ser un casillero_construible.
    //POS: Agrega el edificio dentro del casillero solicitado.
    void construir_edificio_nombre();

    //PRE: En caso de que existan edificios construidos en los casilleros.
    //POS: Muestra cuales edificios estan construidos con su cantidad y en que coordenadas se encuentran.
    void listar_edificios_construidos();

    //PRE: En caso que haya edificios construidos en los casilleros.
    //POS: Muestra los edificios que estan construidos y donde se encuentran ubicados.
    void mostrar_coordenadas(string nombre);

    //PRE: si lista_edificios != 0.
    //POS: Muestra las caracteristicas de todos los edificios posibles a construir/demomel.
    void mostrar_todos_edificios();

    //PRE: Solicitando coordenadas, fila <= cantidad_filas, columna <= cantidad_columnas.
    //POS: Elimina el edificio solicitado del casillero correspondiente y retorna la mitad de los materiales usados al inventario.
    void demoler_edificio();

    //PRE: Con el nombre del edificio que se desea demoler y sus coordenadas (fila y columna).
    //POS: Obtengo los valores de los materiales a retornar luego de la demolicion y elimino el edificios , 
    //     restando 1 a la cantidad de edificios y sumando los materiales obtenidos al inventario.
    void obtengo_materiales_elimino_edificio(string nombre_edificio, int fila, int columna);

    //PRE: Una ves demolido el edificio.
    //POS: Muestro por pantalla los materiales obtenidos, y los guardo en el inventario. 
    void devolver_materiales(int piedra, int madera, int metal);

    //PRE: Teniendo cargada la matriz dinamica.
    //POS: Recorro la matriz y muestro los nombres de los casilleros. 
    void mostrar_mapa();

    //PRE: Solicitando las coordenadas, fila <= cantidad_filas, columna <= cantidad_columnas.
    //POS: Muestra por pantalla el mensaje del casillero.
    void consultar_coordenada();

    //PRE: - 
    //POS: Imprime por pantalla las cantidades de los materiales que se poseen.
    void mostrar_inv();

    //PRE: En caso de tener edificios construidos que brinden materiales.
    //POS: Obtengo los materiales que brindan los edificios y se guardan en el inventario.
    void recolectar_recursos_producidos();

    //PRE: Recibe los eneteros "max_fila" y  "max_col" con los vaores de las maxima columna y la maxima fila que
    //hay en el mapa
    //POST: Coloca en el mapa 1 unidad de cada material generado. Si la posicion random en la que se lo colocaria
    //resulta estar ocupada, no se coloca dicho material.
    void lluvia_recursos();

    //Generar numero random
    //PRE: Recibe los enteros "min" y "max" con los valores limites (inclusives) entre los cuales se desea generar
    //el numero random 
    //POST: Devuelve un valor random entre "min" y "max"
    int generar_numero_random(int min, int max);

    //Ejecutar lluvia
    //PRE: Recibe un entero con la cantidad total de materiales y otros 3 enteros con las cantiades de piedra,
    //madera y metal generadas.
    //POST: Efectua la lluvia de materiales colocando en el mapa en las posiciones hablitadas y generadas por
    //la funcion "generar_numero_random".
    void ejecutar_lluvia(int tot_materiales_gen, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales);
    
    //Consultar material a colocar
    //PRE: Recibe los enteros "cant_gen_piedras", "cant_gen_maderas" y "cant_gen_metales" y el string
    //material_a_colocar
    //POST: Modifica por parametro "material_a_colocar" y las cantidades de piedra y madera restantes.
    void consultar_material_a_colocar(int &cant_gen_piedras, int &cant_gen_maderas, int &cant_gen_metales, string &material_a_colocar);

    //Detructor
    //PRE: - 
    //POS: Libero la memoria reservada por el mapa y los casilleros creados , liberando los edificios y materiales 
    //     que se encuentran en los casilleros y se guarda la informacion en el archivo ubicaciones.txt,
    //     tambien se libera la memoria reservada por el inventario y las caracteristicas_edificios.
    //     Se vuelve a setear todos los valores en 0.
    ~Mapa();
};



#endif // MAPA_H