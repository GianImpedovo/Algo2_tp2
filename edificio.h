#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>

using namespace std;

class Edificio
{
protected:

    string nombre;
    string diminutivo;
    int cantidad_piedra;
    int canitdad_madera;
    int cantidad_metal;
    int cantidad_edificios;
    int maximo_construir;

public:
    Edificio();

    Edificio(std::string nombre , int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir);

    string obtener_nombre();

    string obtener_diminutivo();

    int obtener_cantidad_piedra();

    int obtener_cantidad_madera();

    int obtener_cantidad_metal();

    int obtener_cantidad_construidos();

    int obtener_maximo_construir();

    int obtener_mitad_piedra();

    int obtener_mitad_madera();

    int obtener_mitad_metal();

    void sumar_cantidad();

    void restar_cantidad();

};




#endif // EDIFICIO_H