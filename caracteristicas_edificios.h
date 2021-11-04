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
    //PRE: - 
    //POS: Inicializa los valores de cantidad = 0 y el doble puntero en NULL.
    Caracteristicas_edificio();

    //PRE: Usando el archivo de edificios con por lo menos 1 edificio.
    //POS: Carga el archivo dentro del vector dinamico edificios_posibles.
    void cargar_edificios();

    //PRE: con cantidad_edificios >= 0
    //POS: agrega un edificio al vector y lo redimensiona.
    void agregar_edificio(Edificio * nuevo_edificio);

    //PRE: - 
    //POS: Obtenemos el valor del atributo : cantidad_edificios.
    int obtener_cantidad_edificios();

    //PRE: Si cantidad_edificios > 0 y recibiendo un nombre de edificio que este en el archivo edificios.txt 
    //POS: para localizarlo devuelve la posicion en la que se encuentra el edificio en el vector.
    int obtener_posicion_edificio(string nombre);

    //PRE: Posicion >= 0, en caso que la lista contenga elementos.
    //POS: Devuelve un puntero con la direccion de memoria donde se encuentra el edificio.
    Edificio * obtener_edificio(int posicion);

    //PRE: - 
    //POS: Recorre el vector mostrandonos las caracteristicas de los edificios que vienen en el archivo.
    void listar_todos_edificios();

    //PRE: Nombre tiene que ser un nombre que se encuentre en el archivo edificios.txt
    //POS: Obtendremos si el edificio se encuentra en el vector o no.
    bool existe_el_edificio(string nombre);

    bool supera_maximo(string nombre);

    // Destructor
    //PRE: - 
    //POS: Elimina el vector y libera la memoria que se uso.
    ~Caracteristicas_edificio();


};





#endif // LISTA_EDIFICIO_H