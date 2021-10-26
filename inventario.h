#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED

#include "material.h"
#include <iostream>
#include <string>

using namespace std;


class Inventario { 
private:

	Material** lista_materiales;
    int cantidad_de_materiales;

public:

    //Constructor de inventario sin parametros
    //PRE: -
    //POST: Construye un inventario
    Inventario();

    //Destructor de inventario
    //PRE:-
    //POST: Liberar la memoria que se uso en la creacion del inventario y escribe el 
    //archivo materiales.txt con la info actulizada
    ~Inventario();

    //Cargar materiales
    //PRE: -
    //POST: Abre el archivo materiales.txt y carga la lista de materiales del iventario 
    //con los materiales del archivo. Si no lo logra abrir, carga -1 en cantidad_de_materiales
    void cargar_materiales();

    //Agregar material a la lista de materiales
    //PRE: Recibe un objeto de tipo "material"
    //POST: agrega el material a la lista de materiales
    void agregar_material(Material* material);

    //Obtener material en lista_materiales
    //PRE: Recibe el entero "pos" con la posicion del material en lista_materiales
    //POST: Devuelve un puntero al material que se encuentra la posicion "pos".
    Material* obtener_material_de_lista_materiales(int pos);

    //Obtener cantidad_de_materiales
    //PRE:-
    //POST: Devuelve un entero con la cantidad de materiales en lista_materiales.
    int obtener_cantidad_de_materiales();


};

#endif // INVENTARIO_H_INCLUDED
