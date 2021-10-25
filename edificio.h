#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>

using namespace std;

class Edificio
{
private:
    string nombre;
    int cantidad_piedra;
    int canitdad_madera;
    int cantidad_metal;
    int maximo_construir;

public:
    Edificio(std::string nombre , int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir);
    string mostrar_nombre();

};




#endif // EDIFICIO_H