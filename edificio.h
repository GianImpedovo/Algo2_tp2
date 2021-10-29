#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>

using namespace std;

class Edificio
{
protected:
    string nombre;
    int cantidad_piedra;
    int canitdad_madera;
    int cantidad_metal;
    int maximo_construir;

public:
    Edificio();

    Edificio(std::string nombre , int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir);
    string mostrar_nombre();

    int obtener_cantidad_piedra();

    int obtener_canitdad_madera();

    int obtener_cantidad_metal();

    int obtener_maximo_construir();

    int obtener_mitad_piedra();

    int obtener_mitad_madera();

    int obtener_mitad_metal();

};




#endif // EDIFICIO_H