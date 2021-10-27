#include "edificio.h"


Edificio::Edificio(std::string nombre , int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir){
    this-> nombre = nombre;
    this-> cantidad_piedra = cantidad_piedra;
    this-> canitdad_madera = cantidad_madera;
    this-> cantidad_metal = cantidad_metal;
    this-> maximo_construir = maximo_construir;
    this->fila = 0;
    this->columna = 0;
}

string Edificio::mostrar_nombre(){
    return nombre;
}

int Edificio::mostrar_cantidad_piedra(){
    return cantidad_piedra;
}
int Edificio::mostrar_canitdad_madera(){
    return canitdad_madera;
}
int Edificio::mostrar_cantidad_metal(){
    return cantidad_metal;
}
int Edificio::mostrar_maximo_construir(){
    return maximo_construir;
}

void Edificio::cambiar_fila_columna(int i , int j){
    fila = i;
    columna = j;
}


