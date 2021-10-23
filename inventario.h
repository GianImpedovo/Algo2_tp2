#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED

#include <material.h>
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

    //cargar materiales
    //PRE: El archivo materiales.txt debe existoir
    //POST: Abre el archivo materiales.txt y carga la lista de materiales del iventario 
    //con los materiales del archivo
    void cargar_materiales();

    //Agregar material a la lista de materiales
    //PRE: Recibe un objeto de tipo "material"
    //POST: agrega el material a la lista de materiales
    void agregar_material(Material* material);


    //copiar datos
    void copiar_datos(Material** lista_nueva, int tamanio);

    //constructor de copia
    Inventario ( const Inventario & nuevo_inventario );


};

#endif // INVENTARIO_H_INCLUDED
