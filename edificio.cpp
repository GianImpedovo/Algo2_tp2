#include "edificio.h"


Edificio::Edificio(std::string nombre , int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir){
    this-> nombre = nombre;
    this-> cantidad_piedra = cantidad_piedra;
    this-> canitdad_madera = canitdad_madera;
    this-> cantidad_metal = cantidad_metal;
    this-> maximo_construir = maximo_construir;
}

string Edificio::mostrar_nombre(){
    return nombre;
}


