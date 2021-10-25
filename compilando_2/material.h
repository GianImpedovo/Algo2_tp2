#ifndef MATERIAL_H_INCLUDED
#define MATERAIL_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;


class Material{

private:

    string nombre;
    int cantidad;

public:

    //Consructor de material sin parametros
    //PRE:-
    //POST: Construye un material sin parametros
    Material();
    
    //setter de material
    //PRE: Material debe estar instanciado
    //POST: Asigna un nombre y una cantidad al material
    void asignar_contenido(string nombre, int cantidad);

    //Obtener nombre
    //PRE: -
    //POST: Devuelve un string con el nombre del material
    string obtener_nombre();
    
    //Obtener cantidad
    //PRE: -
    //POST: Devuelve un enetro con la cantidad disponible del material 
    int obtener_cantidad_disponible();

    //cargar material
    //
    //
    void asignar_valores(string nombre, int cantidad);

    //Mostrar nombre material
    //PRE:-
    //POST: Muestra el nombre del material
    void mostrar_nombre();

    
    //Mostrar cantidad material
    //PRE:-
    //POST: Muestra la cantiad del material
    void mostrar_cantidad();

    //Constructor de copia
    Material (const Material & nuevo_material );

};


#endif // MATERIAL_H_INCLUDED